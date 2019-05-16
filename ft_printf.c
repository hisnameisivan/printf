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

	temp.znak = flags->znak; /* для float достали знак из битов раньше */
	temp.nul = 0;
	temp.sp = 0;
	if ((flags->spec == 'd' || flags->spec == 'i' || flags->spec == 'f') && ft_strchr(num, '-')) /* float оставили т.к. нужен модуль */
	{
		temp.znak = -1;
		ft_modul_char(num);
	}
	else if ((flags->spec == 'd' || flags->spec == 'i') && !(ft_strchr(num, '-'))) /* убрали float т.к. менялся знак */
		temp.znak = 1;
	count = ft_strlen(num);
	if (flags->spec == 'o' && flags->resh == 1)
	{
		flags->precision--;
		flags->width--;
	}
	((flags->precision - count) < 0) ? (temp.nul = 0) : (temp.nul = flags->precision - count); /* чтобы учесть отрицательный результат precision - count, т к дальше сломается!!!*/
	((flags->width - (temp.nul + count)) < 0) ? (temp.sp = 0) : (temp.sp = flags->width - (temp.nul + count));
	//temp.sp = flags->width - (temp.nul + count);
	if ((flags->plus && (flags->spec == 'd' || flags->spec == 'i' || flags->spec == 'f')) /*|| (flags->spec == 'o' && flags->resh == 1)*/
	|| ((flags->spec == 'd' || flags->spec == 'i' || flags->spec == 'f') && (temp.znak == -1)))
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
		else if (temp.znak == 0 && flags->spec != 'u' && flags->spec != 'U' && flags->resh)
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
		if (((flags->spec == 'f' && flags->nul == 0)) || (flags->dot == 1 && (flags->spec == 'd' || flags->spec == 'i')) || (flags->dot == 0 && flags->nul == 0)) /* 4a */
			ft_type_space(temp.sp, count);
		if (temp.znak == -1)
			ft_putchar_pf('-', count);
		else if (temp.znak == 1 && flags->plus)
			ft_putchar_pf('+', count);
		if ((flags->dot == 0 && flags->nul == 1) || (flags->spec == 'f' && flags->nul == 1)) /* 4b */
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
		if (((flags->spec == 'f' && flags->nul == 0)) || (flags->dot == 1 && (flags->spec != 'f')) || (flags->dot == 0 && flags->nul == 0))
			ft_type_space(temp.sp, count); /* sit 6b отсюда начинается */
		if (temp.znak == 0 && flags->spec != 'u' && flags->spec != 'U' && flags->resh)
		{
			if (flags->spec == 'o')
			{
				ft_putchar_pf('0', count);
				//temp.nul--;
			}
			else
			{
				ft_putchar_pf('0', count);	
				ft_putchar_pf(flags->spec, count);
			}
			// ft_putchar_pf('0', count);
			// if (flags->spec != 'o') /* для шестнадцатиричной */
			// 	ft_putchar_pf(flags->spec, count);
		}
		if ((flags->dot == 0 && flags->nul == 1) || (flags->spec == 'f' && flags->nul == 1)) /* если точность указана Флаг '0' ignore -> нужно, чтобы не было точки */
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
	if (flags->h && flags->spec != 'U')
		(flags->spec == 'd' || flags->spec == 'i') ? (num = (short)num) : (num = (unsigned short)num);
	else if (flags->hh && flags->spec != 'U')
		(flags->spec == 'd' || flags->spec == 'i') ? (num = (char)num) : (num = (unsigned char)num);
	else if (flags->l || flags->spec == 'U')
		(flags->spec == 'd' || flags->spec == 'i' || flags->spec == 'U') ? (num = (long)num) : (num = (unsigned long)num);
	else if (flags->ll || flags->spec == 'U')
		(flags->spec == 'd' || flags->spec == 'i' || flags->spec == 'U') ? (num = (long long)num) : (num = (unsigned long long)num);
	else if (flags->j && flags->spec != 'U')
		num = (unsigned long)num; /* новый флаг j */
	else if (flags->z && flags->spec != 'U')
		num = (size_t)num;
	return (num);
}

long long	ft_sqr(int base, int power)
{
	long long	result;

	result = 1;
	while (power > 0)
	{
		result = result * base;
		power--;
	}
	return (result);
}

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
	oct_num[i + 1] = '\0';
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

int		ft_constructor_nothing(t_flags *flags, int sit, int *count)
{
	if (sit == 1)
	{
		ft_putchar_pf('+', count);
		ft_type_space(flags->width - 1, count);
	}
	else if (sit == 2)
	{
		// if (flags->resh == 0)
		// {
			// if (flags->spec == 'o' && flags->resh == 1)
			// {
			// 	ft_putchar_pf('0', count);
			// 	flags->width;
			// }
			if (flags->space == 1 && !flags->plus) /* флаг пробел игнор, когда есть флаг + */
			{
				ft_putchar_pf(' ', count);
				flags->width--;
			}
			ft_type_space(flags->width, count);
		// }
		// else
		// {
		// 	ft_putchar_pf('0', count);	
		// 	ft_type_space(flags->width - 1, count);
		// }
	}
	else if (sit == 3)
	{
		if (flags->plus == 1)
			ft_putchar_pf('+', count);
		else if (flags->plus == 0 && flags->space == 1)
			ft_putchar_pf(' ', count);
		ft_putchar_pf('0', count);
		ft_type_space(flags->width - 2, count);
	}
	else if (sit == 4)
	{
		flags->width = flags->width - ((flags->precision - 1 < 0) ? 0 : flags->precision - 1);
		if (flags->precision)
			ft_type_nul(flags->precision - 1, count);
		ft_putchar_pf('0', count);
		ft_type_space(flags->width - 1, count);
	}
	else if (sit == 5)
	{
		flags->width = flags->width - ((flags->precision - 1 < 0) ? 0 : flags->precision - 1);
		(flags->dot == 0 && flags->nul == 1) ? ft_type_sp_nul(flags->width - 1, count) : ft_type_space(flags->width - 1, count);
		//ft_type_space(flags->width - 1, count);
		if (flags->precision)
			ft_type_nul(flags->precision - 1, count);
		ft_putchar_pf('0', count);
	}
	else if (sit == 6)
	{
		ft_putchar_pf('+', count);
		ft_type_sp_nul(flags->width - 2, count);
		ft_putchar_pf('0', count);
	}
	// else if (sit == 7)
	// {
	// 	flags->width = flags->width - ((flags->precision - 1 < 0) ? 0 : flags->precision - 1);
	// 	(flags->dot == 0) ? ft_type_sp_nul(flags->width - 1, count) : ft_type_space(flags->width - 1, count);
	// 	if (flags->precision)
	// 		ft_type_nul(flags->precision - 1, count);
	// 	ft_putchar_pf('0', count);
	// }
	else if (sit == 8)
	{
		ft_type_space(flags->width - 2, count);
		ft_putchar_pf('+', count);
		ft_putchar_pf('0', count);
	}
	else if (sit == 9)
	{
		ft_type_space(flags->width - 1, count);
		ft_putchar_pf('+', count);
	}
	return (1);
}

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
				if (flags->spec == 'd' || flags->spec == 'i')
				{
					if (flags->plus == 1)
						return (ft_constructor_nothing(flags, 1, count));
					else if (flags->plus == 0)
						return (ft_constructor_nothing(flags, 2, count));
				}
				else if (flags->resh != 0 && flags->spec == 'o') /* восьмиричная с # выводит 0 (остальные выводят пустоту)*/
					return (ft_constructor_nothing(flags, 4, count));
				else
					return (ft_constructor_nothing(flags, 2, count)); /* для o, x, u с .0 или . */
			}
			else if (/*flags->dot == 0 && */(flags->spec == 'x' || flags->spec == 'X' || flags->spec == 'o') && flags->resh) /* чтобы с нулем и решеткой не выводилась приставка оx */
				return (ft_constructor_nothing(flags, 4, count));
			// else if (flags->dot == 0)
			// {
			// 	if (flags->spec == 'd' || flags->spec == 'i')
			// 	{
			// 		if (flags->plus == 1)
			// 			return (ft_constructor_nothing(flags, 3, count));
			// 		if (flags->plus == 0)
			// 		{
			// 			if (flags->space == 1)
			// 				return (ft_constructor_nothing(flags, 3, count));
			// 			if (flags->space == 0)
			// 				return (ft_constructor_nothing(flags, 4, count));
			// 		}
			// 	}
				// else
				// 	return (ft_constructor_nothing(flags, 4, count)); /* для o, x, u без точности */
			//}
		}
		else /* нет флага минус */
		{
			if (flags->dot != 0 && flags->precision == 0)
			{
				if (flags->spec == 'd' || flags->spec == 'i')
				{
					if (flags->plus == 1)
						return (ft_constructor_nothing(flags, 9, count));
					else if (flags->plus == 0)
						return (ft_constructor_nothing(flags, 2, count));
				}
				else if (flags->resh != 0 && flags->spec == 'o') /* восьмиричная с # выводит 0 (остальные выводят пустоту)*/
					return (ft_constructor_nothing(flags, 5, count));
				else /* для o (без реш), для x и u */
					return (ft_constructor_nothing(flags, 2, count));
			}
			else if ((flags->spec == 'x' || flags->spec == 'X' || flags->spec == 'o') && flags->resh) /* чтобы с нулем и решеткой не выводилась приставка оx */
				return (ft_constructor_nothing(flags, 5, count));
				//return ((flags->nul == 1) ? ft_constructor_nothing(flags, 7, count) : ft_constructor_nothing(flags, 5, count));
			// else if (flags->dot == 0)
			// {
			// 	if (flags->spec == 'd' || flags->spec == 'i')
			// 	{
			// 		if (flags->plus == 1)
			// 		{
			// 			if (flags->nul == 1)
			// 				return (ft_constructor_nothing(flags, 6, count));
			// 			else if (flags->nul == 0)
			// 				return (ft_constructor_nothing(flags, 8, count));
			// 		}
			// 		else if (flags->plus == 0)
			// 		{
			// 			if (flags->nul == 1)
			// 			{
			// 				if (flags->space == 1)
			// 					return (ft_constructor_nothing(flags, 6, count));
			// 				if (flags->space == 0)
			// 					return (ft_constructor_nothing(flags, 7, count));
			// 			}
			// 			if (flags->nul == 0)
			// 			{
			// 				if (flags->space == 1)
			// 					return (ft_constructor_nothing(flags, 6, count));
			// 				else if (flags->space == 0)
			// 					return (ft_constructor_nothing(flags, 5, count));
			// 			}
			// 		}
			// 	}
			// 	else /* для o u x */
			// 	{
			// 		if (flags->nul == 1)
			// 			return (ft_constructor_nothing(flags, 7, count));
			// 		else if (flags->nul == 0)
			// 			return (ft_constructor_nothing(flags, 5, count));
			// 	}
			// }
		}
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

char	*ft_convert_negative_u(long long *num, t_flags *flags)
{
	unsigned long long	max;
	unsigned long long	temp_num;

	if (flags->hh)
		max = FT_MAX_UCHAR;
	if (flags->h)
		max = FT_MAX_USHORT;
	if (flags->l || flags->ll || flags->spec == 'U')
		max = FT_MAX_ULONG;
	else
		max = FT_MAX_UINT;
	temp_num = max + *num + 1; /* Отрицательный long long делаем unsigned long long */
	return (ft_ulong_to_ascii(temp_num));
}

void	ft_complex_constructor(t_flags *flags, t_wp temp, char *new_num, int *count)
{
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
}

void	ft_decimal(va_list ap, int *count, t_flags *flags)
{
	long long	num;
	char		*new_num;
	t_wp		temp;

	new_num = NULL;
	if (flags->h || flags->l || flags->hh || flags->ll || flags->j || flags->z  || flags->spec == 'U') /* добавила флаг j */
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
	else if ((flags->spec == 'u' || flags->spec == 'U') && num < 0)
		new_num = ft_convert_negative_u(&num, flags);
	else if (flags->spec == 'd' || flags->spec == 'i' || flags->spec == 'u' || flags->spec == 'U')
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
	ft_complex_constructor(flags, temp, new_num, count);
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
		// if (flags->minus) /* есть флаг "-" */
		// {
		// 	if (temp.znak == -1) /* num отрицательный, есть флаг '-', флаг '+' не важен */
		// 		ft_constructor(flags, temp, 1, new_num, count); /* ветка 1 */
		// 	else
		// 	{
		// 		if (flags->plus) /* num положительный, есть флаг '-' и флаг '+' */
		// 			ft_constructor(flags, temp, 1, new_num, count); /* ветка 2 */
		// 		else
		// 		{
		// 			ft_constructor(flags, temp, 2, new_num, count);
		// 		}
		// 	}
		// }
		// else
		// {
		// 	if (temp.znak == -1) /* num отрицательный, НЕТ флага '-', флаг '+' не важен */
		// 	{
		// 		ft_constructor(flags, temp, 4, new_num, count);
		// 	}
		// 	else /* когда znak == 1 или 0 */
		// 	{
		// 		if (flags->plus) /* num положительный, НЕТ флага '-' и ЕСТЬ флаг '+'  */
		// 		{
		// 			ft_constructor(flags, temp, 4, new_num, count);
		// 		}
		// 		else if (!(flags->plus))/* num положительный, НЕТ флага '-' и НЕТ флага '+'  */
		// 		{
		// 			ft_constructor(flags, temp, 6, new_num, count);
		// 		}
		// 	}
		// }
	free(flags);
}

void	ft_char(va_list ap, int *count, t_flags *flags) /* изменила 28.04 */
{
	char	ch;

	ch = (char)va_arg(ap, int);
	flags->width = flags->width - 1;
	if (flags->minus)
	{
		ft_putchar_pf(ch, count);
		ft_type_space(flags->width, count);
	}
	else
	{
		(flags->nul == 1) ? ft_type_sp_nul(flags->width, count) : ft_type_space(flags->width, count);
		ft_putchar_pf(ch, count);
	}
}

void	ft_char_2(char p, int *count, t_flags *flags) /* изменила 28.04 */
{
	char	ch;

	ch = p;
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
	//int		spaces;
	//int		cnt;
	int		len;
	//char	*temp_n;
	int		flag_null;

	//spaces = 0;
	//temp_n = "(null)";
	flag_null = 0;
	str = va_arg(ap, char *);
	if (!str)
	{
		str = "(null)";
		flag_null = 1;
	}
	if (*str == '\0')
	{
		ft_type_space(flags->width, count);
		return ;
	}
	len = ft_strlen(str);
	// if (flags->precision == 0)
	// 	flags->precision = len;
	//cnt = ((flags->precision > len) ? len : flags->precision);
	if (flags->dot == 0)
		flags->precision = len;
	if (flags->precision > len)
		flags->precision = len;
	((flags->width - flags->precision) <= 0 ) ? (flags->width = 0) : (flags->width = flags->width - flags->precision);
	if (flags->minus)
	{
		while (flags->precision-- > 0 && *str != '\0') /* добавила условие != '\0'*/
			ft_putchar_pf(*str++, count);
		ft_type_space(flags->width, count);
	}
	else
	{
		(flags->nul == 1 && flag_null == 0) ? ft_type_sp_nul(flags->width, count) : ft_type_space(flags->width, count);
		while (flags->precision-- > 0 && *str != '\0') /* добавила условие != '\0'*/
			ft_putchar_pf(*str++, count);
	}
}

void	ft_pointer(va_list ap, int *count, t_flags *flags)
{
	long long	pnt;
	char		*new_pnt;
	int			len;
	// t_wp		temp;

	pnt = va_arg(ap, long long);
	new_pnt = convert_v_16(pnt, flags);
	len = ft_strlen(new_pnt);
	//temp = ft_cmp_width_prec_num(flags, new_pnt);
	//if (flags->width)
	//	flags->width = flags->width - ft_strlen(new_pnt) - 2; /* -2 для приставки 0x */
	if (flags->dot && flags->precision == 0 && pnt == 0)
		flags->width++;
	((flags->precision - len) < 0) ? (flags->precision = 0) : (flags->precision = flags->precision - len);
	((flags->width - (flags->precision + len + 2)) < 0) ? (flags->width = 0) : (flags->width = flags->width - (flags->precision + len + 2));
	if (flags->minus)
	{
		
		ft_putstr_pf("0x", count);
		ft_type_nul(flags->precision, count);
		if (!(flags->dot && flags->precision == 0 && pnt == 0)) 
			ft_putstr_pf(new_pnt, count);
		ft_type_space(flags->width, count);
	}
	else
	{
		ft_type_space(flags->width, count);
		ft_putstr_pf("0x", count);
		ft_type_nul(flags->precision, count);
		if (!(flags->dot && flags->precision == 0 && pnt == 0)) 
			ft_putstr_pf(new_pnt, count);
	}
	free(new_pnt);
}

void	ft_check_modificator(t_flags *flags, char *ptr) /* Проверяет флаги hh(1), h(2), ll(3), l(4)*/
{
	int 	count_h;
	char	*temp;

	temp = ptr;
	count_h = 0;
	while (*ptr != 'c' && *ptr != 's' && *ptr != 'p' && *ptr != 'd' && *ptr != 'i' && *ptr != 'o'
	&& *ptr != 'u' && *ptr != 'U' && *ptr != 'x' && *ptr != 'X' && *ptr != 'f' && *ptr != '\0') /* добавила != '\0' для процента*/
	{
		if (*ptr == 'h' && flags->h != 1)
		{
			flags->h = 1;
			count_h++;
			ptr++;
			while (*ptr != 'c' && *ptr != 's' && *ptr != 'p' && *ptr != 'd' && *ptr != 'i' && *ptr != 'o'
			&& *ptr != 'u' && *ptr != 'U' && *ptr != 'x' && *ptr != 'X' && *ptr != 'f' && *ptr != '\0')
			{
				if (*ptr != 'h' && flags->h == 1)
					break ;
				else if (*ptr == 'h')
					count_h++;
				ptr++;
				((count_h % 2) == 0) ? ((flags->hh = 1) && (flags->h = 0)) : (flags->h = 1);
			}
		}
		ptr++;
	}
	ptr = temp;
	while (*ptr != 'c' && *ptr != 's' && *ptr != 'p' && *ptr != 'd' && *ptr != 'i' && *ptr != 'o'
	&& *ptr != 'u' && *ptr != 'U' && *ptr != 'x' && *ptr != 'X' && *ptr != 'f' && *ptr != '\0') /* добавила != '\0' для процента*/
	{
		if (*ptr == 'l')
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
		else if (*ptr == 'z')
			flags->z = 1;
		ptr++;
	}
}

void	ft_write_width_precision(t_flags *flags, char *p)
{
	int	precision;

	precision = 0;
	while (*p != 'c' && *p != 's' && *p != 'p' && *p != 'd' && *p != 'i' && *p != 'o'
	&& *p != 'u' && *p != 'U' && *p != 'x' && *p != 'X' && *p != 'f')
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
	&& *p != 'u' && *p != 'U' && *p != 'x' && *p != 'X' && *p != 'f' && *p != '\0')
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

void	ft_analyze(t_flags *flags)
{
	if (flags->ll || flags->l || flags->z || flags->j)
	{
		flags->h = 0;
		flags->hh = 0;
	}
	else if (flags->h)
		flags->hh = 0;
}

void	ft_fill_struct(t_flags *flags, char *p)
{
	int		width;

	width = 0;
	if ((flags->dot = ft_search_before_spec(p, '.')) == 1)
		ft_write_width_precision(flags, p);
	ft_check_modificator(flags, p);
	while (*p != 'c' && *p != 's' && *p != 'p' && *p != 'd' && *p != 'i' && *p != 'o'
	&& *p != 'u' && *p != 'U' && *p != 'x' && *p != 'X' && *p != 'f' && *p != '\0') /* добавила != '\0' для процента */
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
	ft_analyze(flags);
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

char	*ft_strjoin_float(char *str1, char *str2, t_flags *flags)
{
	char	*tab;
	int		i;
	int		k;

	if (str1 == NULL && str2 == NULL)
		return (NULL);
	i = 0;
	k = 0;
	if ((tab = (char*)malloc(ft_strlen(str1) + ft_strlen(str2) + 2)) == NULL)
		return (NULL);
	while (str1[i] != 0)
	{
		tab[i] = str1[i];
		i++;
	}
	if (*str2 != '\0' || flags->resh == 1)
	{
		tab[i] = '.';
		i++;
	}
	while (str2[k] != 0)
	{
		tab[i] = str2[k];
		i++;
		k++;
	}
	tab[i] = '\0';
	return (tab);
}

int		ft_check_nan_inf(t_flags *flags, long double num, int *count)
{
	long double	inf_p;
	long double	inf_m;
	char		*new_num;
	int			znak;
	
	inf_p = 18.0 / 0.0;
	inf_m = -18.0 / 0.0;
	new_num = NULL;
	znak = 1;
	if (num == inf_m || num == inf_p)
	{
		if (num == inf_p)
			new_num = "inf";
		else if (num == inf_m)
		{
			new_num = "-inf";
			znak = -1;
		}
		flags->width = ((ft_strcmp("-inf", new_num) == 0) ? (flags->width - 4) : (flags->width - 3));
		if (flags->minus)
		{
			if (flags->plus && znak == 1)
			{
				ft_putchar_pf('+', count);
				flags->width--;
			}
			else if (flags->space && znak == 1)
			{
				ft_putchar_pf(' ', count);
				flags->width--;
			}
			ft_putstr_pf(new_num, count);
			ft_type_space(flags->width, count);
		}
		else if (!flags->minus)
		{
			((flags->plus || flags->space) && znak == 1) ? flags->width-- : (flags->width = flags->width);
			ft_type_space(flags->width, count);
			if (flags->plus && znak == 1)
			{
				ft_putchar_pf('+', count);
				// flags->width--;
			}
			else if (flags->space && znak == 1)
			{
				ft_putchar_pf(' ', count);
				//flags->width--;
			}
			ft_putstr_pf(new_num, count);
		}
		return (1);
	}
	return (0);
}

void	ft_float(va_list ap, int *count, t_flags *flags)
{
	int			i;
	int			precision;
	int			rounding;
	long long	temp;
	long long	whole;
	long double	fraction;
	char 		fr[5000];
	char		*wh;
	char		*new_float;
	t_wp		cmp_f;
	char		*znak;

	precision = 0;
	if (flags->bl)
	{
		fraction = va_arg(ap, long double);
		znak = (char *)&fraction;
		znak += 9;
		flags->znak = ((*znak < 0) ? -1 : 1);
		//flag_znak = ((((znak[9]) & (1 << 7)) != 0) ? -1 : 0);
	}
	else
	{
		fraction = va_arg(ap, double);
		znak = (char *)&fraction;
		znak += 9;
		flags->znak = ((*znak < 0) ? -1 : 1);
		//flag_znak = (((znak[7] & (1 << 7)) != 0) ? (char)'+' : (char)'-');
	}
	if (ft_check_nan_inf(flags, fraction, count) == 1)
		return ;
	whole = (long long)fraction;
	if ((fraction = fraction - whole) < 0)
		fraction = fraction * (-1);
	i = 0;
	(flags->dot == 0) ? (precision = 7) : (precision = flags->precision + 1); /* чтобы записать цифру по которой будем округлять +1 */
	while (precision > 0)
	{
		fraction = fraction * 10;
		fr[i] = (int)fraction + '0';
		temp = (long long)fraction;
		fraction = fraction - temp;
		precision--;
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
		if (flags->dot && flags->precision == 0)
			(whole >= 0) ? (whole++) : (whole--);
	}
	wh = ft_long_to_ascii(whole);
	// printf("%lld\n", whole);
	// printf("%d\n", rounding);
	// //printf("%lld\n", temp2);
	// printf("%Lf\n", fraction);
	// i = 0;
	// while (fr[i])
	// {
	// 	printf("%c ",fr[i]);
	// 	i++;
	// }
	//printf("\n");
	flags->precision = 0;
	new_float = ft_strjoin_float(wh, fr, flags);
	cmp_f = ft_cmp_width_prec_num(flags, new_float);
	// cmp_f.znak = flag_znak;
	// if (cmp_f.znak == -1 && flags->plus == 0 && (!ft_strcmp(new_float, "0.0") || !ft_strcmp(new_float, "0."))
	// {
	// 	cmp_f.sp--;
	// }
	ft_complex_constructor(flags, cmp_f, new_float, count);
	// printf("%s", new_float);
	// printf("\n");

}

int		ft_valid_simbols(char c)
{
	if (ft_strchr("cspdiouUxXflhzj -+0123456789#%.", c) != NULL)
		return (1);
	return (0);
}

int		ft_printf(const char *fmt, ...)
{
	va_list	ap; /* указывает на очередной безымянный аргумент */
	t_flags	*flags;
	char	*p;
	int 	count;
	int		valid;

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
			while (*p && (valid = ft_valid_simbols(*p)) == 1)
			{
				if (*p == 'd' || *p == 'i' || *p == 'u' || *p == 'U')
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
			if (valid == 0 && *p)
				ft_char_2(*p, &count, flags);
		}
		else
			ft_putchar_pf(*p, &count);
		if (*p)
			p++;
	}
	va_end(ap);
	return (count);
}
