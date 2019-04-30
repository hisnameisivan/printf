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
	int count;

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

t_wp	ft_cmp_width_prec_num(t_flags *flags, char *num)
{
	t_wp	temp;
	int		count; /* количество цифр без учета знака */

	temp.znak = 0;
	temp.nul = 0;
	temp.sp = 0;
	if ((flags->spec == 'd' || flags->spec == 'i') && ft_strchr(num, '-'))
	{
		temp.znak = -1;
		ft_modul_char(num);
	}
	else if ((flags->spec == 'd' || flags->spec == 'i') && !(ft_strchr(num, '-')))
		temp.znak = 1;
	count = ft_strlen(num);
	// if (temp.znak == -1)
	// 	count = count - 1;
	((flags->precision - count) < 0) ? (temp.nul = 0) : (temp.nul = flags->precision - count); /* чтобы учесть отрицательный результат precision - count, т к дальше сломается!!!*/
	((flags->width - (temp.nul + count)) < 0) ? (temp.sp = 0) : (temp.sp = flags->width - (temp.nul + count));
	//temp.sp = flags->width - (temp.nul + count);
	if ((flags->plus && (flags->spec == 'd' || flags->spec == 'i')) || (flags->spec == 'o' && flags->resh == 1)
	|| ((flags->spec == 'd' || flags->spec == 'i') && (temp.znak == -1)))
		(((temp.sp) - 1) > 0) ? ((temp.sp)--) : (temp.sp = 0);
	if (((flags->spec == 'x') || (flags->spec == 'X')) && (flags->resh == 1))
		(((temp.sp) - 2) > 0) ? ((temp.sp) = (temp.sp) - 2) : (temp.sp = 0); /* с решеткой шестнадцатиричная выводится с 0x */
	return (temp);
}

// 26.04 изменил функции ft_type_, вместо структуры подаем int
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

// void	ft_constructor_16(t_flags *flags, t_wp temp, char *num, int *count)
// {
// 	if (flags->minus)
// 	{
// 		if (ft_strcmp("0", num) && (!flags->dot || (flags->dot && temp.nul))) /* если подан не 0 и (нет точки от точности или (есть точность )) */
// 		{
// 			ft_putchar_pf('0', count);
// 			ft_putchar_pf(flags->spec, count);
// 		}
// 		ft_putstr_pf(num, count);
// 		while (temp.nul > 0)
// 		{
// 			ft_putchar_pf('0', count);
// 			temp.nul--;
// 		}
// 		while (temp.sp > 0)
// 		{
// 			ft_putchar_pf(' ', count);
// 			temp.sp--;
// 		}
// 	}
// 	else
// 	{
// 		while (temp.sp > 0)
// 		{
// 			ft_putchar_pf(' ', count);
// 			temp.sp--;
// 		}
// 		if (ft_strcmp("0", num) && (!flags->dot || (flags->dot && temp.nul)))
// 		{
// 			ft_putchar_pf('0', count);
// 			ft_putchar_pf(flags->spec, count);
// 		}
// 		while (temp.nul > 0)
// 		{
// 			ft_putchar_pf('0', count);
// 			temp.nul--;
// 		}
// 		if (!flags->dot || (flags->dot && temp.nul))
// 			ft_putstr_pf(num, count);
// 	}
// }

// void	ft_constructor_8(t_flags *flags, t_wp temp, char *num, int *count)
// {
// 	int		spaces;
// 	int		nulls;

// 	spaces = temp.sp;
// 	nulls = temp.nul;

// 	if (flags->minus)
// 	{
// 		ft_putchar_pf('0', count);
// 		ft_putstr_pf(num, count);
// 		while (spaces--)
// 			ft_putchar_pf(' ', count);
// 		while (nulls--)
// 			ft_putchar_pf('0', count);
// 	}
// 	else
// 	{
// 		while (spaces > 0)
// 		{
// 			ft_putchar_pf(' ', count);
// 			spaces--;
// 		}
// 		while (nulls > 0)
// 		{
// 			ft_putchar_pf('0', count);
// 			nulls--;
// 		}
// 		ft_putchar_pf('0', count);
// 		ft_putstr_pf(num, count);
// 	}
// }

void	ft_constructor(t_flags *flags, t_wp temp, int sit, char *num, int *count)
{
	if (sit == 1)
	{
		if (temp.znak == -1)
			ft_putchar_pf('-', count);
		else if (temp.znak == 1 && flags->plus)
			ft_putchar_pf('+', count);
		ft_type_nul(temp.nul, count);
		ft_putstr_pf(num, count);
		ft_type_space(temp.sp, count);
		//printf("\nsit 1\n");
	}
	else if (sit == 2)
	{
		if (temp.znak == 1 && flags->space) /* (sit 2a) znak == 1 - значит число либо d или i */
		{
			ft_putchar_pf(' ', count); /* флаг пробел (флаг пробел не работает с восьмиричной и шестнадцатиричной*/
			temp.sp--; /* флаг пробел съел один пробел */
		}
		else if (temp.znak == 0 && flags->spec != 'u' && flags->resh)
		{
			ft_putchar_pf('0', count);
			if (flags->spec != 'o') /* для шестнадцатиричной */
				ft_putchar_pf(flags->spec, count);
		}
		ft_type_nul(temp.nul, count); /* sit 2b - отсюда начинается не заходя в if*/
		ft_putstr_pf(num, count);
		ft_type_space(temp.sp, count);
		//printf("\nsit 2\n");
	}
	// else if (sit == 3)
	// {
	// 	ft_type_nul(temp);
	// 	ft_putstr(num);
	// 	ft_type_space(temp);
	// 	printf("\nsit 3\n");
	// }
	else if (sit == 4)
	{
		if (flags->dot == 1 || (flags->dot == 0 && flags->nul == 0)) /* 4a */
			ft_type_space(temp.sp, count);
		if (temp.znak == -1)
			ft_putchar_pf('-', count);
		else if (temp.znak == 1 && flags->plus)
			ft_putchar_pf('+', count);
		if (flags->dot == 0 && flags->nul == 1) /* 4b */
			ft_type_sp_nul(temp.sp, count);
		ft_type_nul(temp.nul, count);
		ft_putstr_pf(num, count);
		//printf("\nsit 4\n");
	}
	// else if (sit == 5) /* можно закоментить ничего не ломается */
	// {
	// 	if (temp.znak == -1)
	// 		ft_putchar_pf('-', count);
	// 	else if (temp.znak == 1 && flags->plus)
	// 		ft_putchar_pf('+', count);
	// 	ft_type_sp_nul(temp, count);
	// 	ft_putstr_pf(num, count);
	// 	//printf("\nsit 5\n");
	// }
	else if (sit == 6)
	{
		if (temp.znak == 1 && flags->space) /* sit 6a znak == 1 - значит число либо d или i */
		{
			ft_putchar_pf(' ', count); /* флаг пробел (флаг пробел не работает с восьмиричной и шестнадцатиричной*/
			temp.sp--; /* флаг пробел съел один пробел */
		}
		if (flags->dot == 1 || (flags->dot == 0 && flags->nul == 0))
			ft_type_space(temp.sp, count); /* sit 6b отсюда начинается */
		if (temp.znak == 0 && flags->spec != 'u' && flags->resh)
		{
			ft_putchar_pf('0', count);
			if (flags->spec != 'o') /* для шестнадцатиричной */
				ft_putchar_pf(flags->spec, count);
		}
		if (flags->nul && flags->dot == 0) /* если точность указана Флаг '0' ignore -> нужно, чтобы не было точки */
			ft_type_sp_nul(temp.sp, count); /* sit 6c или sit 6d*/
		else
		ft_type_nul(temp.nul, count);
		ft_putstr_pf(num, count);
		//printf("\nsit 6\n");
	}
	// else if (sit == 7)
	// {
	// 	ft_type_space(temp);
	// 	ft_type_nul(temp);
	// 	ft_putstr(num);
	// 	printf("\nsit 7\n");
	// }
	// else if (sit == 8)
	// {
	// 	if (temp.znak == 1 && flags->space) /* sit 6a znak == 1 - значит число либо d или i */
	// 	{
	// 		ft_putchar_pf(' ', count); /* флаг пробел (флаг пробел не работает с восьмиричной и шестнадцатиричной*/
	// 		temp.sp--; /* флаг пробел съел один пробел */
	// 	}
	// 	ft_type_sp_nul(temp, count);
	// 	ft_putstr_pf(num, count);
	// 	//printf("\nsit 8\n");
	// }
	// else if (sit == 9) /* */ склеилась с 8
	// {
	// 	ft_type_sp_nul(temp);
	// 	ft_putstr(num);
	// 	printf("\nsit 9\n");
	// }
}

long long	ft_apply_modificator(va_list ap, t_flags *flags) /* long long вместо int для num */
{
	long long	num;

	num = va_arg(ap, long long);
	if (flags->hh)
		(flags->spec == 'd' || flags->spec == 'i') ? (num = (char)num) : (num = (unsigned char)num);
	else if (flags->h)
		(flags->spec == 'd' || flags->spec == 'i') ? (num = (short)num) : (num = (unsigned short)num);
	else if (flags->l)
		(flags->spec == 'd' || flags->spec == 'i') ? (num = (long)num) : (num = (unsigned long)num);
	else if (flags->ll)
		(flags->spec == 'd' || flags->spec == 'i') ? (num = (long long)num) : (num = (unsigned long long)num);
	else if (flags->j)
		num = (unsigned long)num; /* новый флаг j */
	return (num);
}

// long long	ft_sqr(int base, int power)
// {
// 	long long	result;

// 	result = 1;
// 	while (power > 0)
// 	{
// 		result = result * base;
// 		power--;
// 	}
// 	return (result);
// }

char	*convert_v_8(long long num, t_flags *flags)  /* Из десятичной в восьмиричную */
{
	int					i;
	int					ost[23];
	char				*oct_num;
	char				*oct_temp;
	unsigned long long	max;
	unsigned long long	temp;

	oct_num = NULL;
	temp = num;
	i = 0;
	if (num < 0)
	{
		if (flags->hh)
			max = FT_MAX_UCHAR;
		if (flags->h)
			max = FT_MAX_USHORT;
		if (flags->l || flags->ll)
			max = FT_MAX_ULONG;
		else
			max = FT_MAX_UINT;
		temp = max + num + 1; /* Отрицательный long long делаем unsigned long long */
	}
	while (temp > 7)
	{
		ost[i] = temp % 8;
		temp = temp / 8;
		i++;
	}
	ost[i] = temp;
	oct_num = (char *)malloc(sizeof(char) * (i + 2));
	oct_temp = oct_num;
	while (i >= 0)
	{
		*oct_num = (char)ost[i] + '0';
		i--;
		oct_num++;
	}
	return (oct_temp);
}

char	*convert_v_16(long long num, t_flags *flags) /* Из десятичной в шестнадцатиричную */
{
	int					i;
	int					ost[23];
	char				*hex_num;
	char				*hex_temp;
	unsigned long long	max;
	unsigned long long	temp;
	unsigned long long	result;

	temp = num;
	i = 0;
	result = 0;
	hex_num = NULL;
	if (num < 0)
	{
		if (flags->hh)
			max = FT_MAX_UCHAR;
		if (flags->h)
			max = FT_MAX_USHORT;
		if (flags->l || flags->ll)
			max = FT_MAX_ULONG;
		else
			max = FT_MAX_UINT;
		temp = max + num + 1; /* Отрицательный long long делаем unsigned long long */
	}
	while (temp > 15)
	{
		ost[i] = temp % 16;
		temp = temp / 16;
		i++;
	}
	ost[i] = temp;
	hex_num = (char *)malloc(sizeof(char) * (i + 2));
	hex_temp = hex_num;
	hex_num[i + 1] = '\0';
	while (i >= 0)
	{
		if (ost[i] < 10)
			*hex_num = (char)ost[i] + '0';
		else
			*hex_num = (char)ost[i] - 10 + ((flags->spec == 'X') ? 'A' : 'a');
			//ft_putchar((char)ost[i] - 10 + ((x == 'x') ? 'a' : 'A')); /* (ost[i] - 10) - это сдвиг либо от 'a' (если x), либо от 'A' */
		i--;
		hex_num++;
	}
	return (hex_temp);
}
// 26.04 изменил ft_check_nothing, немного сократил
int		ft_check_nothing(char *num, t_flags *flags, int *count)
{
	if (num == NULL)
		return (0);
	if (ft_strcmp("0", num) == 0)
	{
		if (flags->minus)
		{
			if (flags->dot != 0 && flags->precision == 0)
			{
				if ((flags->spec == 'd' || flags->spec == 'i') && flags->plus == 1)
				{
					flags->width--;
					ft_putchar_pf('+', count);
					ft_type_space(flags->width, count);
					return (1);
				}

				ft_type_space(flags->width, count);
				return (1);
			}
			else if (flags->dot == 0) /* добавила 28.04 */
			{
				if ((flags->spec == 'd' || flags->spec == 'i') && flags->plus == 1)
				{
					flags->width = flags->width - 2; /* вычитаем под знак и под ноль */
					ft_putchar_pf('+', count);
					ft_putchar_pf('0', count);
					ft_type_space(flags->width, count);
					return (1);
				}
				ft_putchar_pf('0', count);
				ft_type_space(--flags->width, count);
				return (1);
			}
		}
		else
		{
			if (flags->dot != 0 && flags->precision == 0)
			{
				if ((flags->spec == 'd' || flags->spec == 'i') && flags->plus == 1)
				{
					flags->width--;
					ft_type_space(flags->width, count);
					ft_putchar_pf('+', count);
					return (1);
				}
				if (flags->resh != 0 && flags->spec == 'o') /* восьмиричная с # выводит 0 (остальные выводят пустоту)*/
					flags->width--;
				ft_type_space(flags->width, count);
				if (flags->resh != 0 && flags->spec == 'o')
					ft_putchar_pf('0', count);
				return (1);
			}
			else if (flags->dot == 0) /* добавила 28.04 */
			{
				if ((flags->spec == 'd' || flags->spec == 'i') && flags->plus == 1)
				{
					flags->width = flags->width - 2; /* вычитаем под знак и под ноль */
					ft_type_space(flags->width, count);
					ft_putchar_pf('+', count);
					ft_putchar_pf('0', count);
					return (1);
				}
				flags->width--;
				ft_type_space(flags->width, count);
				ft_putchar_pf('0', count);
				return (1);
			}

		}
	}
	return (0);
}

unsigned long long	ucount_of_digits(unsigned long long n)
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

char	*ft_ulong_to_ascii(unsigned long long n)
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

char	*ft_convert_negative_u(long long *num, t_flags *flags)
{
	unsigned long long	max;
	unsigned long long	temp_num;

	if (flags->hh)
		max = FT_MAX_UCHAR;
	if (flags->h)
		max = FT_MAX_USHORT;
	if (flags->l || flags->ll)
		max = FT_MAX_ULONG;
	else
		max = FT_MAX_UINT;
	temp_num = max + *num + 1; /* Отрицательный long long делаем unsigned long long */
	return (ft_ulong_to_ascii(temp_num));
}


void	ft_decimal(va_list ap, int *count, t_flags *flags)
{
	long long	num;
	char		*new_num;
	t_wp		temp;

	new_num = NULL;
	if (flags->h || flags->l || flags->hh || flags->ll || flags->j) /* добавила флаг j */
		num = ft_apply_modificator(ap, flags);
	else
	{
		num = va_arg(ap, int);
		((flags->spec == 'd') || (flags->spec == 'i')) ? (num = (int)num) : (num = (unsigned int)num); /* тернарник нужен для перевода спецификаторов 'ouxX'*/
	}
	if (flags->spec == 'x' || flags->spec == 'X')
		new_num = convert_v_16(num, flags);
	else if (flags->spec == 'o')
		new_num = convert_v_8(num, flags);
	else if (flags->spec == 'u' && num < 0)
		new_num = ft_convert_negative_u(&num, flags);
	else if (flags->spec == 'd' || flags->spec == 'i' || flags->spec == 'u')
		new_num = ft_long_to_ascii(num);
	if ((ft_check_nothing(new_num, flags, count)) == 1)
		return ;
	temp = ft_cmp_width_prec_num(flags, new_num);
	if (temp.znak == 0)
	{
		if (flags->minus)
			ft_constructor(flags, temp, 2, new_num, count);
		else
			ft_constructor(flags, temp, 6, new_num, count);
		free(flags);
		return ;
	}

	// if (temp.znak == 0 && (flags->spec == 'x' || flags->spec == 'X') && flags->resh)
	// {
	// 	ft_constructor_16(flags, temp, new_num, count);
	// 	free(flags);
	// 	return ;
	// }
	// if (temp.znak == 0 && flags->spec == 'o' && flags->resh)
	// {
	// 	ft_constructor_8(flags, temp, new_num, count);
	// 	free(flags);
	// 	return ;
	// }
	//	if (flags->width || flags->precision) /* выяснить зачем */
		if (flags->minus) /* есть флаг "-" */
		{
			if (temp.znak == -1) /* num отрицательный, есть флаг '-', флаг '+' не важен */
				ft_constructor(flags, temp, 1, new_num, count); /* ветка 1 */
			else
			{
				if (flags->plus) /* num положительный, есть флаг '-' и флаг '+' */
					ft_constructor(flags, temp, 1, new_num, count); /* ветка 2 */
				else
				{
					ft_constructor(flags, temp, 2, new_num, count);
				}
			}
		}
		else
		{
			if (temp.znak == -1) /* num отрицательный, НЕТ флага '-', флаг '+' не важен */
			{
				ft_constructor(flags, temp, 4, new_num, count);
			}
			else /* когда znak == 1 или 0 */
			{
				if (flags->plus) /* num положительный, НЕТ флага '-' и ЕСТЬ флаг '+'  */
				{
					ft_constructor(flags, temp, 4, new_num, count);
				}
				else if (!(flags->plus))/* num положительный, НЕТ флага '-' и НЕТ флага '+'  */
				{
					ft_constructor(flags, temp, 6, new_num, count);
				}
			}
		}
	free(flags);
}

void	ft_char(va_list ap, int *count, t_flags *flags) /* изменила 28.04 */
{
	char	ch;
	//char	ch[2];
	//t_wp	temp;

	ch = (char)va_arg(ap, int);
	//ch[0] = (char)va_arg(ap, int);
	//ch[1] = 0;
	//temp = ft_cmp_width_prec_num(flags, ch);
	//if (flags->width)
	//	temp.sp = flags->width - 1;
	flags->width = flags->width - 1;
	if (flags->minus)
	{
		ft_putchar_pf(ch, count);
		ft_type_space(flags->width, count);
	}
	else
	{
		ft_type_space(flags->width, count);
		ft_putchar_pf(ch, count);
	}
}

void	ft_string(va_list ap, int *count, t_flags *flags)
{
	char	*str;
	int		spaces;

	spaces = 0;
	str = va_arg(ap, char *);
	if (!str)
	{
		ft_putstr_pf("(null)", count);
		return ;
	}
	if (*str == '\0')
	{
		ft_type_space(flags->width, count);
		return ;
	}
	if (flags->precision == 0)
		flags->precision = ft_strlen(str);
	((flags->width - flags->precision) <= 0 ) ? (spaces = 0) : (spaces = flags->width - flags->precision);
	if (flags->minus)
	{
		while (flags->precision-- > 0 && *str != '\0') /* добавила условие != '\0'*/
			ft_putchar_pf(*str++, count);
		ft_type_space(spaces, count);
	}
	else
	{
		ft_type_space(spaces, count);
		while (flags->precision-- > 0 && *str != '\0') /* добавила условие != '\0'*/
			ft_putchar_pf(*str++, count);
	}
}

void	ft_pointer(va_list ap, int *count, t_flags *flags)
{
	long long	pnt;
	char		*new_pnt;
	t_wp		temp;

	pnt = va_arg(ap, long long);
	new_pnt = convert_v_16(pnt, flags);
	temp = ft_cmp_width_prec_num(flags, new_pnt);
	if (flags->width)
		temp.sp = flags->width - count_of_digits(pnt);
	if (flags->minus)
	{
		ft_putstr_pf("0x", count);
		ft_putstr_pf(new_pnt, count);
		while (--temp.sp > 0)
			ft_putchar_pf(' ', count);
	}
	else
	{
		while (--temp.sp > 0)
			ft_putchar_pf(' ', count);
		ft_putstr_pf("0x", count);
		ft_putstr_pf(new_pnt, count);
	}
	free(new_pnt);
}

// void	ft_float(va_list ap, int *count, t_flags *flags)
// {
// 	long double	num;
// 	int			temp_num;
// 	char		*new_pnt;
// 	t_wp		temp;

// 	num = va_arg(ap, long double);
// 	temp
// }

void	ft_check_modificator(t_flags *flags, char *ptr) /* Проверяет флаги hh(1), h(2), ll(3), l(4)*/
{
	while (*ptr != 'c' && *ptr != 's' && *ptr != 'p' && *ptr != 'd' && *ptr != 'i' && *ptr != 'o'
	&& *ptr != 'u' && *ptr != 'x' && *ptr != 'X' && *ptr != 'f' && *ptr != '\0') /* добавила != '\0' для процента*/
	{
		if (*ptr == 'h')
		{
			if (*(ptr + 1) == 'h')
			{
				flags->hh = 1;
				return ;
			}
			else
			{
				flags->h = 1;
				return ;
			}
		}
		else if (*ptr == 'l')
		{
			if (*(ptr + 1) == 'l')
			{
				flags->ll = 1;
				return ;
			}
			else
			{
				flags->l = 1;
				return ;
			}
		}
		else if (*ptr == 'j') /* новый флаг j */
			flags->j = 1;
		ptr++;
	}
}

void	ft_write_width_precision(t_flags *flags, char *p)
{
	int	precision;

	precision = 0;
	while (*p != 'c' && *p != 's' && *p != 'p' && *p != 'd' && *p != 'i' && *p != 'o'
	&& *p != 'u' && *p != 'x' && *p != 'X' && *p != 'f')
	{
		if (*p >= '0' && *p <= '9')
		{
			while (*p >= '0' && *p <= '9')
			{
				flags->width = flags->width * 10 + *p - '0';
				p++;
			}
		}
		if (*p == '.')
		{
			while (*(p + 1) >= '0' && *(p + 1) <= '9')
			{
				precision = precision * 10 + *(p + 1) - '0';
				p++;
			}
			flags->precision = precision;
			break ;
		}
		p++;
	}
}

int		ft_search_before_spec(char *p, char c)
{
	while (*p != 'c' && *p != 's' && *p != 'p' && *p != 'd' && *p != 'i' && *p != 'o'
	&& *p != 'u' && *p != 'x' && *p != 'X' && *p != 'f'&& *p != '\0')
	{
		if (*p == c)
			return (1);
		else
			p++;
	}
	return (0);
}

void	ft_initialization(t_flags *temp)
{
	temp->dot = 0;
	temp->spec = 0;
	temp->resh = 0;
	temp->j = 0;
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
	temp->width = 0;
	temp->precision = 0;
}

t_flags	*ft_create_struct_printf(void)
{
	t_flags	*temp;

	if ((temp = (t_flags *)malloc(sizeof(t_flags))) == NULL)
		return (NULL);
	ft_initialization(temp);
	return (temp);
}

void	ft_fill_struct(t_flags *flags, char *p)
{
	int		width;

	width = 0;
	if ((flags->dot = ft_search_before_spec(p, '.')) == 1)
		ft_write_width_precision(flags, p);
	ft_check_modificator(flags, p);
	while (*p != 'c' && *p != 's' && *p != 'p' && *p != 'd' && *p != 'i' && *p != 'o'
	&& *p != 'u' && *p != 'x' && *p != 'X' && *p != 'f' && *p != '\0') /* добавила != '\0' для процента */
	{
		if (*p == '0') /* нужно записать ноль раньше ширины, не заходя в запись ширины */
			flags->nul = 1;
		else if (*p >= '0' && *p <= '9' && flags->dot == 0)
		{
			while (*p >= '0' && *p <= '9')
			{
				width = width * 10 + *p - '0';
				p++;
			}
			flags->width = width;
			p--;	/* чтобы не перескочить спецификатор */
		}
		else if (*p == '-')
			flags->minus = 1;
		else if (*p == '+')
			flags->plus = 1;
		else if (*p == '#')
			flags->resh = 1;
		else if (*p == ' ')
			flags->space = 1;
		else if (*p == 'L')
			flags->bl = 1;
		else if (*p == '%')
			flags->procent = 1;
		p++;
	}
	flags->spec = *p;
}

void	ft_percent(int *count, t_flags *flags) /* добавила функцию 28.04 */
{
	flags->width--;
	if (flags->minus)
	{
		ft_putchar_pf('%', count);
		ft_type_space(flags->width, count);
	}
	else
	{
		(flags->nul != 0) ? (ft_type_sp_nul(flags->width, count)) : (ft_type_space(flags->width, count));
		ft_putchar_pf('%', count);
	}
}

void	ft_float(va_list ap, int *count, t_flags *flags)
{
	int		temp;
	double	fraction;

	fraction = va_arg(ap, double);
	temp = (int)fraction;
	fraction = fraction - temp;
	if (flags->dot != 0 && flags->precision == 0) /* дописать */
		temp++;
	printf("%d\n", temp);
	printf("%f", fraction);
	count++;
}

int		ft_printf(const char *fmt, ...)
{
	va_list	ap; /* указывает на очередной безымянный аргумент */
	t_flags	*flags;
	char	*p;
	int count;

	p = (char *)fmt;
	count = 0;
	va_start(ap, fmt); /* устанавливает ap на 1-й безымянный аргумент */
	while (*p)
	{
		if (*p =='%')
		{
			p++;
			flags = ft_create_struct_printf();
			ft_fill_struct(flags, p);
			while (*p)
			{
				if (*p == 'd' || *p == 'i' || *p == 'u')
				{
					ft_decimal(ap, &count, flags);
					break ;
				}
				if (*p == 'c')
				{
					ft_char(ap, &count, flags);
					break ;
				}
				if (*p == 's')
				{
					ft_string(ap, &count, flags);
					break ;
				}
				if (*p == 'p')
				{
					ft_pointer(ap, &count, flags);
					break ;
				}
				if (*p == 'o')
				{
					ft_decimal(ap, &count, flags);
					break ;
				}
				if (*p == 'x' || *p == 'X')
				{
					ft_decimal(ap, &count, flags);
					break ;
				}
				if (*p == 'f')
				{
					ft_float(ap, &count, flags);
					break ;
				}
				if (*p == '%')
				{
					ft_percent(&count, flags);
					break ;
				}
				p++;
			}
		}
		else
			ft_putchar_pf(*p, &count);
		p++;
	}
	va_end(ap);
	return (count);
}

// int main(void)
// {
// 	/* тесты для десятичной записи */

	// printf("01 stroka: %-+8.6d\n", -123);
	// ft_printf("01 stroka: %-+8.6d\n", -123);
	// printf("02 stroka: % -+8.6d\n", -123);
	// ft_printf("02 stroka: % -+8.6d\n", -123);
	// printf("03 stroka: %-+8.6d\n", 123);
	// ft_printf("03 stroka: %-+8.6d\n", 123);
	// printf("04 stroka: % -+8.6d\n", 123);
	// ft_printf("04 stroka: % -+8.6d\n", 123);
	// printf("05 stroka: %-8.6d\n", 123);
	// ft_printf("05 stroka: %-8.6d\n", 123);
	// printf("06 stroka: % -8.6d\n", 123);
	// ft_printf("06 stroka: % -8.6d\n", 123);
	// printf("07 stroka: %+8.6d\n", -123);
	// ft_printf("07 stroka: %+8.6d\n", -123);
	// printf("08 stroka: % +8.6d\n", -123);
	// ft_printf("08 stroka: % +8.6d\n", -123);
	// printf("09 stroka: %+8.6d\n", 123);
	// ft_printf("09 stroka: %+8.6d\n", 123);
	// printf("10 stroka: % +8.6d\n", 123);
	// ft_printf("10 stroka: % +8.6d\n", 123);
	// printf("11 stroka: %8.6d\n", 123);
	// ft_printf("11 stroka: %8.6d\n", 123);
	// printf("12 stroka: % 8.6d\n", 123);
	// ft_printf("12 stroka: % 8.6d\n", 123);
	// printf("13 stroka: %+8d\n", -123);
	// ft_printf("13 stroka: %+8d\n", -123);
	// printf("14 stroka: % +8d\n", -123);
	// ft_printf("14 stroka: % +8d\n", -123);
	// printf("15 stroka: %8.6d\n", 123);
	// ft_printf("15 stroka: %8.6d\n", 123);
	// printf("16 stroka: % 8.6d\n", 123);
	// ft_printf("16 stroka: % 8.6d\n", 123);
	// printf("17 stroka: %+ 8.6d\n", 123);
	// ft_printf("17 stroka: %+ 8.6d\n", 123);
	// printf("18 stroka: % 8.6 d\n", 123);
	// ft_printf("18 stroka: % 8.6 d\n", 123);
	// printf("19 stroka: %      8d\n", -123);
	// ft_printf("19 stroka: %      8d\n", -123);
	// printf("20 stroka: % 8.6d\n", 123);
	// ft_printf("20 stroka: % 8.6d\n", 123);
	// printf("21 stroka: % d\n", -123);
	// ft_printf("21 stroka: % d\n", -123);
	// printf("22 stroka: %      d\n", -123);
	// ft_printf("22 stroka: %      d\n", -123);
	// printf("23 stroka: %08.6d\n", 123);
	// ft_printf("23 stroka: %08.6d\n", 123);
	// printf("24 stroka: %-010d\n", 123);
	// ft_printf("24 stroka: %-010d\n", 123);
	// printf("25 stroka: % 010d\n", 123);
	// ft_printf("25 stroka: % 010d\n", 123);
	// printf("26 stroka: % 010.5d\n", 123);
	// ft_printf("26 stroka: % 010.5d\n", 123);
	// printf("27 stroka: %9 0d\n", 123);
	// ft_printf("27 stroka: %9 0d\n", 123);
	// printf("28 stroka: %9d\n", 123);
	// ft_printf("28 stroka: %9d\n", 123);
	// printf("29 stroka: % 08.6d\n", 123);
	// ft_printf("29 stroka: % 08.6d\n", 123);
	// printf("30 stroka: % 06d\n", 123);
	// ft_printf("30 stroka: % 06d\n", 123);
	// printf("31 stroka: %+08.6d\n", 123);
	// ft_printf("31 stroka: %+08.6d\n", 123);
	// printf("32 stroka: % 15s\n", "privet");
	// ft_printf("32 stroka: % 15s\n", "privet");
	// printf("33 stroka: % c\n", 'c');
	// ft_printf("33 stroka: % c\n", 'c');
	// printf("34 stroka: % 08.6hhd\n", (char)128);
	// ft_printf("34 stroka: % 08.6hhd\n", (char)128);
	// printf("35 stroka: % 06hhd\n", (char)212);
	// ft_printf("35 stroka: % 06hhd\n", (char)212);
	// printf("36 stroka: %+08.6hhd\n", (char)212);
	// ft_printf("36 stroka: %+08.6hhd\n", (char)212);
	// ft_printf("37 stroka: % 1.2d\n", -1);
	// printf("37 stroka: % 1.2d\n", -1);
	// printf("38 stroka: %9.5d\n", 345);
	// ft_printf("38 stroka: %9.5d\n", 345);

	/* тесты для восьмиричной записи */

	// printf("01 stroka: %-+8.6o\n", -123);
	// ft_printf("01 stroka: %-+8.6o\n", -123);
    // printf("02 stroka: % -+8.6o\n", -123);
	// ft_printf("02 stroka: % -+8.6o\n", -123);
	// printf("03 stroka: %-+8.6o\n", 123);
	// ft_printf("03 stroka: %-+8.6o\n", 123);
	// printf("04 stroka: % -+8.6o\n", 123);
	// ft_printf("04 stroka: % -+8.6o\n", 123);
	// printf("05 stroka: %-8.6o\n", 123);
	// ft_printf("05 stroka: %-8.6o\n", 123);
	// printf("06 stroka: % -8.6o\n", 123);
	// ft_printf("06 stroka: % -8.6o\n", 123);
	// printf("07 stroka: %+8.6o\n", -123);
	// ft_printf("07 stroka: %+8.6o\n", -123);
	// printf("08 stroka: % +8.6o\n", -123);
	// ft_printf("08 stroka: % +8.6o\n", -123);
	// printf("09 stroka: %+8.6o\n", 123);
	// ft_printf("09 stroka: %+8.6o\n", 123);
	// printf("10 stroka: % +8.6o\n", 123);
	// ft_printf("10 stroka: % +8.6o\n", 123);
	// printf("11 stroka: %8.6o\n", 123);
	// ft_printf("11 stroka: %8.6o\n", 123);
	// printf("12 stroka: % 8.6o\n", 123);
	// ft_printf("12 stroka: % 8.6o\n", 123);
	// printf("13 stroka: %+8o\n", -123);
	// ft_printf("13 stroka: %+8o\n", -123);
	// printf("14 stroka: % +8o\n", -123);
	// ft_printf("14 stroka: % +8o\n", -123);
	// printf("15 stroka: %8.6o\n", 123);
	// ft_printf("15 stroka: %8.6o\n", 123);
	// printf("16 stroka: % 8.6o\n", 123);
	// ft_printf("16 stroka: % 8.6o\n", 123);
	// printf("17 stroka: %+ 8.6o\n", 123);
	// ft_printf("17 stroka: %+ 8.6o\n", 123);
	// printf("18 stroka: % 8.6 o\n", 123);
	// ft_printf("18 stroka: % 8.6 o\n", 123);
	// printf("19 stroka: %      15o\n", -123);
	// ft_printf("19 stroka: %      15o\n", -123);
	// printf("20 stroka: % 8.6o\n", 123);
	// ft_printf("20 stroka: % 8.6o\n", 123);
	// printf("21 stroka: % o\n", -123);
	// ft_printf("21 stroka: % o\n", -123);
	// printf("22 stroka: %      o\n", -123);
	// ft_printf("22 stroka: %      o\n", -123);
	// printf("23 stroka: %08.6o\n", 123);
	// ft_printf("23 stroka: %08.6o\n", 123);
	// printf("24 stroka: %-010o\n", 123);
	// ft_printf("24 stroka: %-010o\n", 123);
	// printf("25 stroka: % 010o\n", 123);
	// ft_printf("25 stroka: % 010o\n", 123);
	// printf("26 stroka: % 010.5o\n", 123);
	// ft_printf("26 stroka: % 010.5o\n", 123);
	// printf("27 stroka: %9 0o\n", 123);
	// ft_printf("27 stroka: %9 0o\n", 123);
	// printf("28 stroka: %9o\n", 123);
	// ft_printf("28 stroka: %9o\n", 123);
	// printf("29 stroka: % 08.6o\n", 123);
	// ft_printf("29 stroka: % 08.6o\n", 123);
	// printf("30 stroka: % 06o\n", 123);
	// ft_printf("30 stroka: % 06o\n", 123);
	// printf("31 stroka: %+08.6o\n", 123);
	// ft_printf("31 stroka: %+08.6o\n", 123);
	// printf("32 stroka: % 15s\n", "privet");
	// ft_printf("32 stroka: % 15s\n", "privet");
	// printf("33 stroka: % c\n", 'c');
	// ft_printf("33 stroka: % c\n", 'c');
	// printf("34 stroka: % 08.6hho\n", (char)128);
	// ft_printf("34 stroka: % 08.6hho\n", (char)128);
	// printf("35 stroka: % 06hho\n", (char)212);
	// ft_printf("35 stroka: % 06hho\n", (char)212);
	// printf("36 stroka: %+08.6hho\n", (char)212);
	// ft_printf("36 stroka: %+08.6hho\n", (char)212);
	// printf("37 stroka: % 1.2o\n", -1);
	// ft_printf("37 stroka: % 1.2o\n", -1);
	// printf("38 stroka: % -8hho\n", (char)255);
	// ft_printf("38 stroka: % -8hho\n", (char)255);
	// printf("39 stroka: % -8hho\n", (char)255);
	// ft_printf("39 stroka: % -8hho\n", (char)255);
	// printf("40 stroka: %9.5o\n", 345);
	// ft_printf("40 stroka: %9.5o\n", 345);

	/* тесты для char */

	// char	ch = 'x';
	// printf("kolichestvo %d\n", printf("01 stroka: %c\n", ch));
	// printf("kolichestvo %d\n", ft_printf("01 stroka: %c\n", ch));
	// printf("kolichestvo %d\n", printf("02 stroka: %15.6c\n", ch));
	// printf("kolichestvo %d\n", ft_printf("02 stroka: %15.6c\n", ch));
	// printf("kolichestvo %d\n", printf("03 stroka: %-15c\n", ch));
	// printf("kolichestvo %d\n", ft_printf("03 stroka: %-15c\n", ch));
	// printf("kolichestvo %d\n", printf("04 stroka: % -15c\n", ch));
	// printf("kolichestvo %d\n", ft_printf("04 stroka: % -15c\n", ch));
	// printf("kolichestvo %d\n", printf("05 stroka: % -015c\n", ch));
	// printf("kolichestvo %d\n", ft_printf("05 stroka: % -015c\n", ch));

	/* тесты для string */

	// char	*str = "hello";
	// printf("kolichestvo %d\n", printf("01 stroka: %s\n", str));
	// printf("kolichestvo %d\n", ft_printf("01 stroka: %s\n", str));
	// printf("kolichestvo %d\n", printf("02 stroka: %15.6s\n", str));
	// printf("kolichestvo %d\n", ft_printf("02 stroka: %15.6s\n", str));
	// printf("kolichestvo %d\n", printf("03 stroka: %-15s\n", str));
	// printf("kolichestvo %d\n", ft_printf("03 stroka: %-15s\n", str));
	// printf("kolichestvo %d\n", printf("04 stroka: % -15s\n", str));
	// printf("kolichestvo %d\n", ft_printf("04 stroka: % -15s\n", str));
	// printf("kolichestvo %d\n", printf("05 stroka: % -015s\n", str));
	// printf("kolichestvo %d\n", ft_printf("05 stroka: % -015s\n", str));

	/* тесты для pointer */

	// char	*str = "hello";
	// printf("kolichestvo %d\n", printf("01 stroka: %p\n", str));
	// printf("kolichestvo %d\n", ft_printf("01 stroka: %p\n", str));
	// printf("kolichestvo %d\n", printf("02 stroka: %15.6p\n", str));
	// printf("kolichestvo %d\n", ft_printf("02 stroka: %15.6p\n", str));
	// printf("kolichestvo %d\n", printf("03 stroka: %-15p\n", str));
	// printf("kolichestvo %d\n", ft_printf("03 stroka: %-15p\n", str));
	// printf("kolichestvo %d\n", printf("04 stroka: % -15p\n", str));
	// printf("kolichestvo %d\n", ft_printf("04 stroka: % -15p\n", str));
	// printf("kolichestvo %d\n", printf("05 stroka: % -015p\n", str));
	// printf("kolichestvo %d\n", ft_printf("05 stroka: % -015p\n", str));

	/* тесты для count */

	// printf("kolichestvo %d\n", printf("01 stroka: %-+8.6d\n", -123));
	// printf("kolichestvo %d\n", ft_printf("01 stroka: %-+8.6d\n", -123));
	// printf("kolichestvo %d\n", printf("02 stroka: % -+8.6d\n", -123));
	// printf("kolichestvo %d\n", ft_printf("02 stroka: % -+8.6d\n", -123));
	// printf("kolichestvo %d\n", printf("03 stroka: %-+8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("03 stroka: %-+8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("04 stroka: % -+8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("04 stroka: % -+8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("05 stroka: %-8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("05 stroka: %-8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("06 stroka: % -8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("06 stroka: % -8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("07 stroka: %+8.6d\n", -123));
	// printf("kolichestvo %d\n", ft_printf("07 stroka: %+8.6d\n", -123));
	// printf("kolichestvo %d\n", printf("08 stroka: % +8.6d\n", -123));
	// printf("kolichestvo %d\n", ft_printf("08 stroka: % +8.6d\n", -123));
	// printf("kolichestvo %d\n", printf("09 stroka: %+8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("09 stroka: %+8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("10 stroka: % +8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("10 stroka: % +8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("11 stroka: %8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("11 stroka: %8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("12 stroka: % 8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("12 stroka: % 8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("13 stroka: %+8d\n", -123));
	// printf("kolichestvo %d\n", ft_printf("13 stroka: %+8d\n", -123));
	// printf("kolichestvo %d\n", printf("14 stroka: % +8d\n", -123));
	// printf("kolichestvo %d\n", ft_printf("14 stroka: % +8d\n", -123));
	// printf("kolichestvo %d\n", printf("15 stroka: %8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("15 stroka: %8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("16 stroka: % 8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("16 stroka: % 8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("17 stroka: %+ 8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("17 stroka: %+ 8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("18 stroka: % 8.6 d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("18 stroka: % 8.6 d\n", 123));
	// printf("kolichestvo %d\n", printf("19 stroka: %      8d\n", -123));
	// printf("kolichestvo %d\n", ft_printf("19 stroka: %      8d\n", -123));
	// printf("kolichestvo %d\n", printf("20 stroka: % 8.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("20 stroka: % 8.6d\n", 123));
	// printf("kolichestvo %d\n", printf("21 stroka: % d\n", -123));
	// printf("kolichestvo %d\n", ft_printf("21 stroka: % d\n", -123));
	// printf("kolichestvo %d\n", printf("22 stroka: %      d\n", -123));
	// printf("kolichestvo %d\n", ft_printf("22 stroka: %      d\n", -123));
	// printf("kolichestvo %d\n", printf("23 stroka: %08.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("23 stroka: %08.6d\n", 123));
	// printf("kolichestvo %d\n", printf("24 stroka: %-010d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("24 stroka: %-010d\n", 123));
	// printf("kolichestvo %d\n", printf("25 stroka: % 010d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("25 stroka: % 010d\n", 123));
	// printf("kolichestvo %d\n", printf("26 stroka: % 010.5d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("26 stroka: % 010.5d\n", 123));
	// printf("kolichestvo %d\n", printf("27 stroka: %9 0d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("27 stroka: %9 0d\n", 123));
	// printf("kolichestvo %d\n", printf("28 stroka: %9d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("28 stroka: %9d\n", 123));
	// printf("kolichestvo %d\n", printf("29 stroka: % 08.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("29 stroka: % 08.6d\n", 123));
	// printf("kolichestvo %d\n", printf("30 stroka: % 06d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("30 stroka: % 06d\n", 123));
	// printf("kolichestvo %d\n", printf("31 stroka: %+08.6d\n", 123));
	// printf("kolichestvo %d\n", ft_printf("31 stroka: %+08.6d\n", 123));
	// printf("kolichestvo %d\n", printf("32 stroka: % 15s\n", "privet"));
	// printf("kolichestvo %d\n", ft_printf("32 stroka: % 15s\n", "privet"));
	// printf("kolichestvo %d\n", printf("33 stroka: % c\n", 'c'));
	// printf("kolichestvo %d\n", ft_printf("33 stroka: % c\n", 'c'));
	// printf("kolichestvo %d\n", printf("34 stroka: % 08.6hhd\n", (char)128));
	// printf("kolichestvo %d\n", ft_printf("34 stroka: % 08.6hhd\n", (char)128));
	// printf("kolichestvo %d\n", printf("35 stroka: % 06hhd\n", (char)212));
	// printf("kolichestvo %d\n", ft_printf("35 stroka: % 06hhd\n", (char)212));
	// printf("kolichestvo %d\n", printf("36 stroka: %+08.6hhd\n", (char)212));
	// printf("kolichestvo %d\n", ft_printf("36 stroka: %+08.6hhd\n", (char)212));
	// printf("kolichestvo %d\n", ft_printf("37 stroka: % 1.2d\n", -1));
	// printf("kolichestvo %d\n", printf("37 stroka: % 1.2d\n", -1));
	// printf("kolichestvo %d\n", printf("38 stroka: %9.5d\n", 345));
	// printf("kolichestvo %d\n", ft_printf("38 stroka: %9.5d\n", 345));
	// ft_printf("%.0d\n", 0);
	// ft_printf("%.0x\n", 0);
	// ft_printf("%.0o\n", 0);
	// ft_printf("%.0x\n", 0);
	// ft_printf("%#.0d\n", 0);
	// ft_printf("%#.0x\n", 0);
	// ft_printf("%#.0o\n", 0);
	// ft_printf("%#.0x\n", 0);
// 	ft_printf("01 %#hhx\n", (char)256);
// 	ft_printf("02 %hh#x\n", (char)256);
// 	printf("04 %#hhx\n", (char)256);
// 	printf("05 %hh#x\n", (char)256);
// 	printf("%%\n");
// 	printf("%5%\n");
// 	printf("%-5%\n");
// 	printf("%.0%\n");

	//printf("\n#0074\n");
	// ft_printf("%.2c", NULL);
	// ft_printf("%.2c", 0);
	// printf("\n#0075\n");
	// printf("%s %s", NULL, "string");
	// printf("\n#0079\n");
	// printf("@moulitest: %c", 0);
	// printf("\n#0080\n");
	// printf("%2c", 0);
	// printf("\n#0081\n");
	// printf("null %c and text", 0);
	// printf("\n#0082\n");
	// printf("% c", 0);
	//ft_printf("%+d\n", 0);
	//ft_printf("%+0d\n", 0);
	//printf("%+0d\n", 0);
	//ft_printf("%#8x\n", 0);
	//printf("%#8x\n", 0);
	// ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
	//printf("@moulitest: %#.o %#.0o\n", 0, 0);
	//printf("@moulitest: %#.x %#.0x", 0, 0);
	//ft_printf("%.o\n", 0);
	//printf("%#.x\n", 0);
	//printf("%#.0o\n", 0);

	// printf("%d\n", printf("%llu\n", (long long)-42));
	// ft_printf("%d\n",ft_printf("%llu\n", (long long)-42));

	// ft_printf("%d\n", ft_printf("%.8s\n", "hello"));
	// printf("%d\n", printf("%.8s\n", "hello"));

// 	return (0);
// }
