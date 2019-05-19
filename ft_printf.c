#include <stdarg.h>
#include <stdio.h>
#include "ft_printf.h"

void	ft_putchar_pf(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putstr_pf(char const *str, int *count)
{
	if (str)
		while (*str)
		{
			write(1, str, 1);
			(*count)++;
			str++;
		}
}

long long	count_of_digits(long long n)
{
	int	count;

	if (n == 0)
		return (1);
	count = 0;
	if (n < 0)
	{
		count++;
		n = (-1) * n;
	}
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_long_to_ascii(long long n)
{
	char	*res;
	int		i;
	int		is_neg;

	is_neg = 1;
	if (n < 0)
		is_neg = -1;
	i = count_of_digits(n);
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res[i] = 0;
	while (i)
	{
		res[i - 1] = is_neg * (n % 10) + 48;
		n = n / 10;
		i--;
	}
	if (is_neg == -1)
		res[0] = '-';
	return (res);
}

void	ft_modul_char(char *num)
{
	ft_memmove(num, (num + 1), ft_strlen(num + 1) + 1);
}

void	ft_cmp_wid_prec_num(t_pf *pf, char *num)
{
	int		count; /* количество цифр без учета знака */

	if ((pf->spec == 'd' || pf->spec == 'i' || pf->spec == 'f') && ft_strchr(num, '-')) /* float оставили т.к. нужен модуль */
	{
		pf->znak = -1;
		ft_modul_char(num);
	}
	else if ((pf->spec == 'd' || pf->spec == 'i') && !(ft_strchr(num, '-'))) /* убрали float т.к. менялся знак */
		pf->znak = 1;
	count = ft_strlen(num);
	if ((pf->spec == 'o') && pf->resh == 1)
	{
		pf->prec--;
		pf->wid--;
	}
	((pf->prec - count) < 0) ? (pf->prec = 0) : (pf->prec  = pf->prec - count); /* чтобы учесть отрицательный результат prec - count, т к дальше сломается!!!*/
	((pf->wid - (pf->prec + count)) < 0) ? (pf->wid = 0) : (pf->wid = pf->wid - (pf->prec + count));
	if ((pf->plus && (pf->spec == 'd' || pf->spec == 'i' || pf->spec == 'f'))
	|| ((pf->spec == 'd' || pf->spec == 'i' || pf->spec == 'f') && (pf->znak == -1)))
		(((pf->wid) - 1) > 0) ? ((pf->wid)--) : (pf->wid = 0);
	if (((pf->spec == 'x') || (pf->spec == 'X')) && (pf->resh == 1))
		(((pf->wid) - 2) > 0) ? ((pf->wid) = (pf->wid) - 2) : (pf->wid = 0); /* с решеткой шестнадцатиричная выводится с 0x */
}

void	ft_type_space(int spaces, int *count) /* печатаем ширину пробелами */
{
	while (spaces > 0)
	{
		ft_putchar_pf(' ', count);
		spaces--;
	}
}

void	ft_type_nul(int nul, int *count) /* печатаем точность нулями */
{
	while (nul > 0)
	{
		ft_putchar_pf('0', count);
		nul--;
	}
}

void	ft_type_sp_nul(int nul, int *count) /* печатаем ширину нулями */
{
	while (nul > 0)
	{
		ft_putchar_pf('0', count);
		nul--;
	}
}

void	ft_print_sit_1(t_pf *pf, char *num, int *count)
{
	if (pf->znak == -1)
		ft_putchar_pf('-', count);
	else if (pf->znak == 1 && pf->plus)
		ft_putchar_pf('+', count);
	ft_type_nul(pf->prec, count);
	ft_putstr_pf(num, count);
	ft_type_space(pf->wid, count);
}

void	ft_print_sit_2(t_pf *pf, char *num, int *count)
{
	if (pf->znak == 1 && pf->space) /* (sit 2a) znak == 1 - значит число либо d или i */
	{
		ft_putchar_pf(' ', count); /* флаг пробел (флаг пробел не работает с восьмиричной и шестнадцатиричной*/
		pf->wid--; /* флаг пробел съел один пробел */
	}
	else if (pf->znak == 0 && pf->spec != 'u' && pf->resh)
	{
		ft_putchar_pf('0', count);
		if (pf->spec != 'o') /* для шестнадцатиричной */
			ft_putchar_pf(pf->spec, count);
	}
	ft_type_nul(pf->prec, count); /* sit 2b - отсюда начинается не заходя в if*/
	ft_putstr_pf(num, count);
	ft_type_space(pf->wid, count);
}

void	ft_print_sit_4(t_pf *pf, char *num, int *count)
{
	if (((pf->spec == 'f' && pf->nul == 0)) || (pf->dot == 1 && (pf->spec == 'd' || pf->spec == 'i')) || (pf->dot == 0 && pf->nul == 0)) /* 4a */
			ft_type_space(pf->wid, count);
	if (pf->znak == -1)
		ft_putchar_pf('-', count);
	else if (pf->znak == 1 && pf->plus)
		ft_putchar_pf('+', count);
	if ((pf->dot == 0 && pf->nul == 1) || (pf->spec == 'f' && pf->nul == 1)) /* 4b */
		ft_type_sp_nul(pf->wid, count);
	ft_type_nul(pf->prec, count);
	ft_putstr_pf(num, count);
}

void	ft_print_sit_6(t_pf *pf, char *num, int *count)
{
	if (pf->znak == 1 && pf->space) /* sit 6a znak == 1 - значит число либо d или i */
	{
		ft_putchar_pf(' ', count); /* флаг пробел (флаг пробел не работает с восьмиричной и шестнадцатиричной*/
		pf->wid--; /* флаг пробел съел один пробел */
	}
	if (((pf->spec == 'f' && pf->nul == 0)) || (pf->dot == 1 && (pf->spec != 'f')) || (pf->dot == 0 && pf->nul == 0))
		ft_type_space(pf->wid, count); /* sit 6b отсюда начинается */
	if (pf->znak == 0 && pf->spec != 'u' && pf->resh)
	{
		if (pf->spec == 'o')
			ft_putchar_pf('0', count);
		else
		{
			ft_putchar_pf('0', count);
			ft_putchar_pf(pf->spec, count);
		}
	}
	if ((pf->dot == 0 && pf->nul == 1) || (pf->spec == 'f' && pf->nul == 1)) /* если точность указана Флаг '0' ignore -> нужно, чтобы не было точки */
		ft_type_sp_nul(pf->wid, count); /* sit 6c или sit 6d*/
	else
		ft_type_nul(pf->prec, count);
	ft_putstr_pf(num, count);
}

long long	ft_apply_modificator(va_list ap, t_pf *pf) /* long long вместо int для num */
{
	long long	num;

	num = va_arg(ap, long long);
	if (pf->h)
		(pf->spec == 'd' || pf->spec == 'i') ? (num = (short)num) : (num = (unsigned short)num);
	else if (pf->hh)
		(pf->spec == 'd' || pf->spec == 'i') ? (num = (char)num) : (num = (unsigned char)num);
	else if (pf->l)
		(pf->spec == 'd' || pf->spec == 'i') ? (num = (long)num) : (num = (unsigned long)num);
	else if (pf->ll)
		(pf->spec == 'd' || pf->spec == 'i') ? (num = (long long)num) : (num = (unsigned long long)num);
	else if (pf->j)
		num = (uintmax_t)num;
	else if (pf->z)
		num = (size_t)num;
	return (num);
}

int		ft_fill_ost(int *ost, unsigned long long num, unsigned long long base)
{
	int		i;

	i = 0;
	while (num > base - 1)
	{
		ost[i] = num % base;
		num = num / base;
		i++;
	}
	ost[i] = num;
	return (i);
}

char	*convert_v_8(unsigned long long num)
{
	int					i;
	int					ost[23];
	char				*oct_num;
	char				*oct_temp;

	oct_num = NULL;
	i = ft_fill_ost(ost, num, 8);
	oct_num = ft_strnew(i + 1);
	oct_temp = oct_num;
	while (i >= 0)
	{
		*oct_num = (char)ost[i] + '0';
		i--;
		oct_num++;
	}
	return (oct_temp);
}

char	*convert_v_16(unsigned long long num, t_pf *pf)
{
	int					i;
	int					ost[23];
	char				*hex_num;
	char				*hex_temp;

	i = 0;
	hex_num = NULL;
	i = ft_fill_ost(ost, num, 16);
	hex_num = ft_strnew(i + 1);
	hex_temp = hex_num;
	while (i >= 0)
	{
		if (ost[i] < 10)
			*hex_num = (char)ost[i] + '0';
		else
			*hex_num = (char)ost[i] - 10 + ((pf->spec == 'X') ? 'A' : 'a');
		i--;
		hex_num++;
	}
	return (hex_temp);
}

int		ft_print_nothing_12(t_pf *pf, int sit, int *count)
{
	if (sit == 1)
	{
		ft_putchar_pf('+', count);
		ft_type_space(pf->wid - 1, count);
	}
	else if (sit == 2)
	{
		if (pf->space == 1 && !pf->plus) /* флаг пробел игнор, когда есть флаг + */
		{
			ft_putchar_pf(' ', count);
			pf->wid--;
		}
		ft_type_space(pf->wid, count);
	}
	return (1);
}

int		ft_print_nothing_34(t_pf *pf, int sit, int *count)
{
	if (sit == 3)
	{
		if (pf->plus == 1)
			ft_putchar_pf('+', count);
		else if (pf->plus == 0 && pf->space == 1)
			ft_putchar_pf(' ', count);
		ft_putchar_pf('0', count);
		ft_type_space(pf->wid - 2, count);
	}
	else if (sit == 4)
	{
		pf->wid = pf->wid - ((pf->prec - 1 < 0) ? 0 : pf->prec - 1);
		if (pf->prec)
			ft_type_nul(pf->prec - 1, count);
		ft_putchar_pf('0', count);
		ft_type_space(pf->wid - 1, count);
	}
	return (1);
}

int		ft_print_nothing_56(t_pf *pf, int sit, int *count)
{
	if (sit == 5)
	{
		pf->wid = pf->wid - ((pf->prec - 1 < 0) ? 0 : pf->prec - 1);
		(pf->dot == 0 && pf->nul == 1) ? ft_type_sp_nul(pf->wid - 1, count) : ft_type_space(pf->wid - 1, count);
		if (pf->prec)
			ft_type_nul(pf->prec - 1, count);
		ft_putchar_pf('0', count);
	}
	else if (sit == 6)
	{
		ft_putchar_pf('+', count);
		ft_type_sp_nul(pf->wid - 2, count);
		ft_putchar_pf('0', count);
	}
	return (1);
}

int		ft_print_nothing_78(t_pf *pf, int sit, int *count)
{
	if (sit == 7)
	{
		ft_type_space(pf->wid - 2, count);
		ft_putchar_pf('+', count);
		ft_putchar_pf('0', count);
	}
	else if (sit == 8)
	{
		ft_type_space(pf->wid - 1, count);
		ft_putchar_pf('+', count);
	}
	return (1);
}

int		ft_printf_nothing_minus(t_pf *pf, int *count)
{
	if (pf->dot != 0 && pf->prec == 0)
	{
		if (pf->spec == 'd' || pf->spec == 'i')
		{
			if (pf->plus == 1)
				return (ft_print_nothing_12(pf, 1, count));
			else if (pf->plus == 0)
				return (ft_print_nothing_12(pf, 2, count));
		}
		else if (pf->resh != 0 && (pf->spec == 'o')) /* восьмиричная с # выводит 0 (остальные выводят пустоту)*/
			return (ft_print_nothing_34(pf, 4, count));
		else
			return (ft_print_nothing_12(pf, 2, count)); /* для o, x, u с .0 или . */
	}
	else if ((pf->spec == 'x' || pf->spec == 'X' || pf->spec == 'o') && pf->resh) /* чтобы с нулем и решеткой не выводилась приставка оx */
		return (ft_print_nothing_34(pf, 4, count));
	return (0);
}

int		ft_printf_nothing_without_minus(t_pf *pf, int *count)
{
	if (pf->dot != 0 && pf->prec == 0)
	{
		if (pf->spec == 'd' || pf->spec == 'i')
		{
			if (pf->plus == 1)
				return (ft_print_nothing_78(pf, 8, count));
			else if (pf->plus == 0)
				return (ft_print_nothing_12(pf, 2, count));
		}
		else if (pf->resh != 0 && (pf->spec == 'o')) /* восьмиричная с # выводит 0 (остальные выводят пустоту)*/
			return (ft_print_nothing_56(pf, 5, count));
		else /* для o (без реш), для x и u */
			return (ft_print_nothing_12(pf, 2, count));
	}
	else if ((pf->spec == 'x' || pf->spec == 'X' || pf->spec == 'o') && pf->resh) /* чтобы с нулем и решеткой не выводилась приставка оx */
		return (ft_print_nothing_56(pf, 5, count));
	return (0);
}

int		ft_check_nothing(char *num, t_pf *pf, int *count)
{
	if (num == NULL)
		return (0);
	if (ft_strcmp("0", num) == 0)
	{
		if (pf->minus)
			return (ft_printf_nothing_minus(pf, count));
		else if (!pf->minus)
			return (ft_printf_nothing_without_minus(pf, count));
	}
	return (0);
}

unsigned long long	ucount_of_digits(unsigned long long n) /* функция под 1 тест lu, -42*/
{
	int count;

	if (n == 0)
		return (1);
	count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_ulong_to_ascii(unsigned long long n) /* функция под 1 тест lu, -42*/
{
	char	*res;
	int		i;
	int		is_neg;

	is_neg = 1;
	i = ucount_of_digits(n);
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res[i] = 0;
	while (i)
	{
		res[i - 1] = is_neg * (n % 10) + 48;
		n = n / 10;
		i--;
	}
	if (is_neg == -1)
		res[0] = '-';
	return (res);
}

void	ft_complex_constructor(t_pf *pf, char *new_num, int *count)
{
	if (pf->minus) /* есть флаг "-" */
	{
		if (pf->znak == -1) /* num отрицательный, есть флаг '-', флаг '+' не важен */
			ft_print_sit_1(pf, new_num, count); /* ветка 1 */
		else
		{
			if (pf->plus) /* num положительный, есть флаг '-' и флаг '+' */
				ft_print_sit_1(pf, new_num, count); /* ветка 2 */
			else
				ft_print_sit_2(pf, new_num, count);
		}
	}
	else
	{
		if (pf->znak == -1) /* num отрицательный, НЕТ флага '-', флаг '+' не важен */
			ft_print_sit_4(pf, new_num, count);
		else /* когда znak == 1 или 0 */
		{
			if (pf->plus) /* num положительный, НЕТ флага '-' и ЕСТЬ флаг '+'  */
				ft_print_sit_4(pf, new_num, count);
			else if (!(pf->plus))/* num положительный, НЕТ флага '-' и НЕТ флага '+'  */
				ft_print_sit_6(pf, new_num, count);
		}
	}
}

char	*ft_create_num(long long num, t_pf *pf)
{
	char	*new_num;

	new_num = NULL;
	if (pf->spec == 'x' || pf->spec == 'X')
		new_num = convert_v_16(num, pf);
	else if (pf->spec == 'o')
		new_num = convert_v_8(num);
	else if ((pf->spec == 'u') && num < 0)
		new_num = ft_ulong_to_ascii(num);
	else if (pf->spec == 'd' || pf->spec == 'i' || pf->spec == 'u')
		new_num = ft_long_to_ascii(num);
	return (new_num);
}

long long	ft_modificators(va_list ap, t_pf *pf)
{
	long long	num;

	if (pf->h || pf->l || pf->hh || pf->ll || pf->j || pf->z)
		num = ft_apply_modificator(ap, pf);
	else
	{
		num = va_arg(ap, long long);
		((pf->spec == 'd') || (pf->spec == 'i')) ? (num = (int)num) : (num = (unsigned int)num); /* тернарник нужен для перевода спецификаторов 'ouxX'*/
	}
	return (num);
}

void	ft_decimal(va_list ap, int *count, t_pf *pf)
{
	char		*new_num;

	new_num = NULL;
	new_num = ft_create_num(ft_modificators(ap, pf), pf);
	if ((ft_check_nothing(new_num, pf, count)) == 1)
	{
		free(new_num);
		return ;
	}
	ft_cmp_wid_prec_num(pf, new_num);
	if (pf->znak == 0)
	{
		if (pf->minus)
			ft_print_sit_2(pf, new_num, count);
		else
			ft_print_sit_6(pf, new_num, count);
		free(new_num);
		return ;
	}
	ft_complex_constructor(pf, new_num, count);
	free(new_num);
}

void	ft_char(va_list ap, int *count, t_pf *pf) /* изменила 28.04 */
{
	char	ch;

	ch = (char)va_arg(ap, int);
	pf->wid = pf->wid - 1;
	if (pf->minus)
	{
		ft_putchar_pf(ch, count);
		ft_type_space(pf->wid, count);
	}
	else
	{
		(pf->nul == 1) ? ft_type_sp_nul(pf->wid, count) : ft_type_space(pf->wid, count);
		ft_putchar_pf(ch, count);
	}
}

void	ft_char_2(char p, int *count, t_pf *pf)
{
	char	ch;

	ch = p;
	pf->wid = pf->wid - 1;
	if (pf->minus)
	{
		ft_putchar_pf(ch, count);
		ft_type_space(pf->wid, count);
	}
	else
	{
		(pf->nul == 1) ? ft_type_sp_nul(pf->wid, count) : ft_type_space(pf->wid, count); // 17.05
		ft_putchar_pf(ch, count);
	}
}

void	ft_print_string(t_pf *pf, char *str, int *count)
{
	if (pf->minus)
	{
		while (pf->prec-- > 0 && *str != '\0')
			ft_putchar_pf(*str++, count);
		ft_type_space(pf->wid, count);
	}
	else
	{
		(pf->nul == 1 ) ? ft_type_sp_nul(pf->wid, count) : ft_type_space(pf->wid, count);
		while (pf->prec-- > 0 && *str != '\0')
			ft_putchar_pf(*str++, count);
	}
}

void	ft_string(va_list ap, int *count, t_pf *pf)
{
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	if (*str == '\0')
	{
		ft_type_space(pf->wid, count);
		return ;
	}
	len = ft_strlen(str);
	if (pf->dot == 0)
		pf->prec = len;
	if (pf->prec > len)
		pf->prec = len;
	((pf->wid - pf->prec) <= 0 ) ? (pf->wid = 0) : (pf->wid = pf->wid - pf->prec);
	ft_print_string(pf, str, count);
}

void	ft_print_pointer(t_pf *pf, char *new_pnt, int pnt, int *count)
{
	if (pf->minus)
	{
		ft_putstr_pf("0x", count);
		ft_type_nul(pf->prec, count);
		if (!(pf->dot && pf->prec == 0 && pnt == 0))
			ft_putstr_pf(new_pnt, count);
		ft_type_space(pf->wid, count);
	}
	else
	{
		ft_type_space(pf->wid, count);
		ft_putstr_pf("0x", count);
		ft_type_nul(pf->prec, count);
		if (!(pf->dot && pf->prec == 0 && pnt == 0))
			ft_putstr_pf(new_pnt, count);
	}
}

void	ft_pointer(va_list ap, int *count, t_pf *pf)
{
	long long	pnt;
	char		*new_pnt;
	int			len;
	pnt = va_arg(ap, long long);
	new_pnt = convert_v_16(pnt, pf);
	len = ft_strlen(new_pnt);
	if (pf->dot && pf->prec == 0 && pnt == 0)
		pf->wid++;
	((pf->prec - len) < 0) ? (pf->prec = 0) : (pf->prec = pf->prec - len);
	((pf->wid - (pf->prec + len + 2)) < 0) ? (pf->wid = 0) : (pf->wid = pf->wid - (pf->prec + len + 2));
	ft_print_pointer(pf, new_pnt, pnt, count);
	free(new_pnt);
}

int	ft_check_specificator(char *ptr)
{
	if (*ptr != 'c' && *ptr != 's' && *ptr != 'p' &&
	*ptr != 'd' && *ptr != 'D' && *ptr != 'i' && *ptr != 'o'
	&& *ptr != 'O' && *ptr != 'u' && *ptr != 'U' && *ptr != 'x'
	&& *ptr != 'X' && *ptr != 'f')
	{
		return (1);
	}
	return (0);
}

void	ft_search_modificator_h(char *ptr, t_pf *pf)
{
	int 	count_h;

	count_h = 0;
	while (ft_check_specificator(ptr) && *ptr != '\0')
	{
		if (*ptr == 'h' && pf->h != 1)
		{
			pf->h = 1;
			count_h++;
			ptr++;
			while (ft_check_specificator(ptr) && *ptr != '\0')
			{
				if (*ptr != 'h' && pf->h == 1)
					break ;
				else if (*ptr == 'h')
					count_h++;
				ptr++;
				((count_h % 2) == 0) ? ((pf->hh = 1) && (pf->h = 0)) : (pf->h = 1);
			}
		}
		ptr++;
	}
}

void	ft_check_modificator(t_pf *pf, char *ptr) /* Проверяет флаги hh(1), h(2), ll(3), l(4)*/
{
	ft_search_modificator_h(ptr, pf);
	while (ft_check_specificator(ptr) && *ptr != '\0')
	{
		if (*ptr == 'l')
		{
			if (*(ptr + 1) == 'l')
			{
				pf->ll = 1;
				return ;
			}
			else
			{
				pf->l = 1;
				return ;
			}
		}
		else if (*ptr == 'j')
			pf->j = 1;
		else if (*ptr == 'z')
			pf->z = 1;
		ptr++;
	}
}

int		ft_search_before_spec(char *p, char c)
{
	while (ft_check_specificator(p) && *p != '\0') // 17.05 add DO
	{
		if (*p == c)
			return (1);
		else
			p++;
	}
	return (0);
}

void	ft_initialization(t_pf *temp)
{
	temp->dot = 0;
	temp->znak = 0;
	temp->spec = 0;
	temp->resh = 0;
	temp->j = 0;
	temp->z = 0;
	temp->hh = 0;
	temp->h = 0;
	temp->ll = 0;
	temp->l = 0;
	temp->minus = 0;
	temp->plus = 0;
	temp->space = 0;
	temp->nul = 0;
	temp->bl = 0;
	temp->ml = 0;
	temp->procent = 0;
	temp->wid = 0;
	temp->prec = 0;
}

t_pf	*ft_create_struct_printf(void)
{
	t_pf	*temp;

	if ((temp = (t_pf *)malloc(sizeof(t_pf))) == NULL)
		return (NULL);
	ft_initialization(temp);
	return (temp);
}

void	ft_analyze(t_pf *pf)
{
	if (pf->spec == 'D' || pf->spec == 'O' || pf->spec == 'U')
	{
		pf->spec += 32;
		pf->l = 1;
	}
	if (pf->ll || pf->l || pf->z || pf->j)
	{
		pf->h = 0;
		pf->hh = 0;
	}
	else if (pf->h)
		pf->hh = 0;
	if (pf->spec != 0 && pf->spec != 'f' && pf->spec != 'c' && pf->spec != 's' && !pf->procent && pf->dot && pf->nul) /* вопрос с float остается открытым */
		pf->nul = 0;
}

void	ft_fill_width(t_pf *pf, char **p)
{
	pf->wid = 0;
	while (**p >= '0' && **p <= '9')
	{
		pf->wid = pf->wid * 10 + **p - '0';
		(*p)++;
	}
	(*p)--;	/* чтобы не перескочить спецификатор */
}

void	ft_fill_precision(t_pf *pf, char **p)
{
	pf->dot = 1;
	pf->prec = 0;
	while (**p >= '0' && **p <= '9')
	{
		pf->prec = pf->prec * 10 + **p - '0';
		(*p)++;
	}
	(*p)--;	/* чтобы не перескочить спецификатор */
}

void	ft_fill_flags(t_pf *pf, char *p)
{
	if (*p == '-')
		pf->minus = 1;
	else if (*p == '+')
		pf->plus = 1;
	else if (*p == '#')
		pf->resh = 1;
	else if (*p == ' ')
		pf->space = 1;
	else if (*p == 'L')
		pf->bl = 1;
	else if (*p == '%')
		pf->procent = 1;
}

void	ft_fill_struct(t_pf *pf, char *p)
{
	ft_check_modificator(pf, p);
	while (ft_check_specificator(p) && *p != '\0') /* добавила != '\0' для процента */
	{
		if (*p == '0') /* нужно записать ноль раньше ширины, не заходя в запись ширины вопрос с float остается открытым */
			pf->nul = 1;
		else if (pf->dot == 0 && *p >= '0' && *p <= '9')
			ft_fill_width(pf, &p);
		else if (*(p - 1) == '.' && *p >= '0' && *p <= '9')
			ft_fill_precision(pf, &p);
		else if (*p == '.' && (*p < '0' || *p > '9'))
		{
			pf->dot = 1;
			pf->prec = 0;
		}
		else
			ft_fill_flags(pf, p);
		p++;
	}
	pf->spec = *p;
	ft_analyze(pf);
}

void	ft_percent(int *count, t_pf *pf) /* добавила функцию 28.04 */
{
	pf->wid--;
	if (pf->minus)
	{
		ft_putchar_pf('%', count);
		ft_type_space(pf->wid, count);
	}
	else
	{
		(pf->nul != 0) ? (ft_type_sp_nul(pf->wid, count)) : (ft_type_space(pf->wid, count));
		ft_putchar_pf('%', count);
	}
}

char	*ft_strjoin_float(char *str1, char *str2, t_pf *pf)
{
	char	*tab;
	int		i;
	int		k;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	i = -1;
	k = 0;
	if ((tab = (char*)malloc(ft_strlen(str1) + ft_strlen(str2) + 2)) == NULL)
		return (NULL);
	while (str1[++i] != 0)
		tab[i] = str1[i];
	if (*str2 != '\0' || pf->resh == 1)
		tab[i++] = '.';
	while (str2[k] != 0)
		tab[i++] = str2[k++];
	tab[i] = '\0';
	return (tab);
}

void	ft_inf_minus(t_pf *pf, char *new_num, int znak, int *count)
{
	if (pf->plus && znak == 1)
	{
		ft_putchar_pf('+', count);
		pf->wid--;
	}
	else if (pf->space && znak == 1)
	{
		ft_putchar_pf(' ', count);
		pf->wid--;
	}
	ft_putstr_pf(new_num, count);
	ft_type_space(pf->wid, count);
}

void	ft_inf_without_minus(t_pf *pf, char *new_num, int znak, int *count)
{
	((pf->plus || pf->space) && znak == 1) ? pf->wid-- : (pf->wid = pf->wid);
	ft_type_space(pf->wid, count);
	if (pf->plus && znak == 1)
		ft_putchar_pf('+', count);
	else if (pf->space && znak == 1)
		ft_putchar_pf(' ', count);
	ft_putstr_pf(new_num, count);
}

int		ft_analyze_inf(long double num, int *znak)
{
	long double	inf_p;
	long double	inf_m;

	inf_p = 42.0 / 0.0;
	inf_m = -42.0 / 0.0;
	if (num == inf_p)
		return (1);
	else if (num == inf_m)
	{
		*znak = -1;
		return (-1);
	}
	return (0);
}

int		ft_check_inf(t_pf *pf, long double num, int *count)
{
	long double	inf_p;
	long double	inf_m;
	char		*new_num;
	int			znak;

	inf_p = 42.0 / 0.0;
	inf_m = -42.0 / 0.0;
	new_num = NULL;
	znak = 1;
	if (num == inf_m || num == inf_p)
	{
		if (ft_analyze_inf(num, &znak) != 0)
			(ft_analyze_inf(num, &znak) == 1) ? (new_num = "inf") : (new_num = "-inf");
		pf->wid = ((ft_strcmp("-inf", new_num) == 0) ? (pf->wid - 4) : (pf->wid - 3));
		if (pf->minus)
			ft_inf_minus(pf, new_num, znak, count);
		else if (!pf->minus)
			ft_inf_without_minus(pf, new_num, znak, count);
		return (1);
	}
	return (0);
}

long double	ft_fraction(va_list ap, t_pf *pf)
{
	long double	fraction;
	char		*znak;
	
	if (pf->bl)
	{
		fraction = va_arg(ap, long double);
		znak = (char *)&fraction;
		znak += 9;
		pf->znak = ((*znak < 0) ? -1 : 1);
	}
	else
	{
		fraction = va_arg(ap, double);
		znak = (char *)&fraction;
		znak += 9;
		pf->znak = ((*znak < 0) ? -1 : 1);
	}
	return (fraction);
}

void	ft_float(va_list ap, int *count, t_pf *pf)
{
	int			i;
	int			prec;
	int			rounding;
	long long	temp;
	long long	whole;
	long double	fraction;
	char 		fr[5000];
	char		*wh;
	char		*new_float;
	
	prec = 0;
	fraction = ft_fraction(ap, pf);
	if (ft_check_inf(pf, fraction, count) == 1)
		return ;
	whole = (long long)fraction;
	if ((fraction = fraction - whole) < 0)
		fraction = fraction * (-1);
	i = 0;
	(pf->dot == 0) ? (prec = 7) : (prec = pf->prec + 1); /* чтобы записать цифру по которой будем округлять +1 */
	while (prec > 0)
	{
		fraction = fraction * 10;
		fr[i] = (int)fraction + '0';
		temp = (long long)fraction;
		fraction = fraction - temp;
		prec--;
		i++;
	}
	i--;
	rounding = fr[i] - '0';
	fr[i] = '\0';
	i--;
	if (rounding >= 5)
	{
		fr[i]++;
		while (((fr[i] - '0') == 10) && (i >= 0)) /* i - 1 проверка на то, что мы дошли до первого (нулевого) элемента массива */
		{
			fr[i] = '0';
			if (i == 0)
				(whole >= 0) ? (whole++) : (whole--);
			else
				fr[i - 1]++;
			i--;
		}
		if (pf->dot && pf->prec == 0)
			(whole >= 0) ? (whole++) : (whole--);
	}
	wh = ft_long_to_ascii(whole);
	pf->prec = 0;
	new_float = ft_strjoin_float(wh, fr, pf);
	ft_cmp_wid_prec_num(pf, new_float);
	ft_complex_constructor(pf, new_float, count);
	free(wh);
	free(new_float);
}

int		ft_valid_simbols(char c)
{
	if (ft_strchr("cspdDioOuUxXflhzj -+0123456789#%.", c) != NULL)
		return (1);
	return (0);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	ap; /* указывает на очередной безымянный аргумент */
	t_pf	*pf;
	char	*p;
	int 	count;
	int		valid;

	p = (char *)fmt;
	count = 0;
	va_start(ap, fmt); /* устанавливает ap на 1-й безымянный аргумент */
	while (!p) // 17.05 NULL
	{
		return (-1); // 17.05 NULL
	}
	while (*p)
	{
		if (*p =='%')
		{
			p++;
			pf = ft_create_struct_printf();
			ft_fill_struct(pf, p);
			while (*p && (valid = ft_valid_simbols(*p)) == 1)
			{
				if (*p == 'd' || *p == 'D' || *p == 'i' || *p == 'o' || *p == 'O' || *p == 'u' || *p == 'U' || *p == 'x' || *p == 'X')
				{
					ft_decimal(ap, &count, pf);
					free(pf);
					break ;
				}
				if (*p == 'c')
				{
					ft_char(ap, &count, pf);
					free(pf);
					break ;
				}
				if (*p == 's')
				{
					ft_string(ap, &count, pf);
					free(pf);
					break ;
				}
				if (*p == 'p')
				{
					ft_pointer(ap, &count, pf);
					free(pf);
					break ;
				}
				if (*p == 'f')
				{
					ft_float(ap, &count, pf);
					free(pf);
					break ;
				}
				if (*p == '%')
				{
					ft_percent(&count, pf);
					free(pf);
					break ;
				}
				p++;
			}
			if (valid == 0 && *p)
			{
				ft_char_2(*p, &count, pf);
				free(pf);
			}
		}
		else
			ft_putchar_pf(*p, &count);
		if (*p)
			p++;
	}
	va_end(ap);
	return (count);
}
