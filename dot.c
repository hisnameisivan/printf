#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"
#include <stdlib.h>
#include "printf.h"

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

void	ft_putnbrll(long long n)
{
	if ((n / 10) > 0)
	{
		ft_putnbrll(n / 10);
	}
	ft_putchar((n % 10) + '0');
}

long long	ft_modul(long long num) /* возможно придется изменить на long long*/
{
	if (num < 0)
		return(num * (-1));
	return (num);
}

t_wp	ft_cmp_width_prec_num(t_flags *flags, long long num)
{
	t_wp	temp;
	int		count; /* количество цифр с учетом знака */

	if (num < 0)
		temp.znak = -1;
	else
		temp.znak = 1;
	num = ft_modul(num);
	count = count_of_digits(num);
	//temp.nul = flags->precision - count;
	((flags->precision - count) < 0) ? (temp.nul = 0) : (temp.nul = flags->precision - count); /* чтобы учесть отрицательный результат precision - count, т к дальше сломается!!!*/
	temp.sp = flags->width - (temp.nul + count);
	if ((flags->plus && (flags->spec == 'd' || flags->spec == 'i' || flags->spec == 'u')) || (flags->spec == 'o' && flags->resh == 1))
		(temp.sp)--;
	//printf("\n__noliki %d, probely %d__\n", temp.nul, temp.sp);
	return (temp);
}

void	ft_type_space(t_wp temp) /* печатаем ширину пробелмаи */
{
	while (temp.sp > 0)
	{
		ft_putchar(' ');
		temp.sp--;
	}
}

void	ft_type_nul(t_wp temp) /* печатаем точность нулями */
{
	while (temp.nul > 0)
	{
		ft_putchar('0');
		temp.nul--;
	}
}

void	ft_type_sp_nul(t_wp temp) /* печатаем ширину нулями */
{
	while (temp.sp > 0)
	{
		ft_putchar('0');
		temp.sp--;
	}
}

void	ft_constructor(t_flags *flags, t_wp temp, int sit, long long num)
{
	if (sit == 1)
	{
		if (num < 0)
			ft_putchar('-');
		else if (num >= 0 && flags->plus)
			ft_putchar('+');
		ft_type_nul(temp);
		ft_putnbrll(ft_modul(num));
		ft_type_space(temp);
	}
	else if (sit == 2)
	{
		ft_putchar(' '); /* флаг пробел */
		ft_type_nul(temp);
		ft_putnbrll(ft_modul(num));
		temp.nul--; /* флаг пробел съел один пробел */
		ft_type_space(temp);
	}
	else if (sit == 3)
	{
		ft_type_nul(temp);
		ft_putnbrll(ft_modul(num));
		ft_type_space(temp);
	}
	else if (sit == 4)
	{
		ft_type_space(temp);
		if (num < 0)
			ft_putchar('-');
		else if (num >= 0 && flags->plus)
			ft_putchar('+');
		ft_type_nul(temp);
		ft_putnbrll(ft_modul(num));
	}
	else if (sit == 5)
	{
		if (num < 0)
			ft_putchar('-');
		else if (num >= 0 && flags->plus)
			ft_putchar('+');
		ft_type_sp_nul(temp);
		ft_putnbrll(ft_modul(num));
	}
	else if (sit == 6)
	{
		ft_putchar(' '); /* флаг пробел */
		temp.nul--; /* флаг пробел съел один пробел */
		ft_type_space(temp);
		ft_type_nul(temp);
		ft_putnbrll(ft_modul(num));
	}
	else if (sit == 7)
	{
		ft_type_space(temp);
		ft_type_nul(temp);
		ft_putnbrll(ft_modul(num));
	}
	else if (sit == 8)
	{
		ft_putchar(' '); /* флаг пробел */
		temp.sp--; /* флаг пробел съел один пробел */
		ft_type_sp_nul(temp);
		ft_putnbrll(ft_modul(num));
	}
	else if (sit == 9)
	{
		ft_type_sp_nul(temp);
		ft_putnbrll(ft_modul(num));
	}
}

long long	ft_apply_modificator(va_list ap, t_flags *flags) /* long long вместо int для num */
{
	long long	num;

	num = va_arg(ap, long long);
	if (flags->hh)
		(flags->spec == 'u' || flags->spec == 'o') ? (num = (unsigned char)num) : (num = (char)num);
	else if (flags->h)
		(flags->spec == 'u' || flags->spec == 'o') ? (num = (unsigned short)num) : (num = (short)num);
	else if (flags->l)
		(flags->spec == 'u' || flags->spec == 'o') ? (num = (unsigned long)num) : (num = (long)num);
	else if (flags->ll)
		(flags->spec == 'u' || flags->spec == 'o') ? (num = (unsigned long long)num) : (num = (long long)num);
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

unsigned long long	convert_v_8(long long num, int *count, t_flags *flags)  /* Из десятичной в восьмиричную */
{
	int					i;
	int					ost[23];
	unsigned long long	max;
	unsigned long long	temp;
	unsigned long long	result;

	temp = num;
	i = 0;
	result = 0;
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
	while (i >= 0)
	{
		result = result + ft_sqr(10, i) * ost[i];
		i--;
	}
	return (result);
}

char	*convert_v_16(long long num, int *count, t_flags *flags) /* Из десятичной в шестнадцатиричную */
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
			*hex_num = (char)ost[i] - 10 + ((flags->spec == 'x') ? 'a' : 'A');
			//ft_putchar((char)ost[i] - 10 + ((x == 'x') ? 'a' : 'A')); /* (ost[i] - 10) - это сдвиг либо от 'a' (если x), либо от 'A' */
		i--;
		hex_num++;
	}
	return (hex_temp);
}

void	ft_decimal(va_list ap, int *count, t_flags *flags)
{
	long long	num;
	char		*hex_num;
	t_wp		temp;

	hex_num = NULL;
	if (flags->h || flags->l || flags->hh || flags->ll)
		num = ft_apply_modificator(ap, flags);
	else
	{
		num = va_arg(ap, int);
		(flags->spec == 'u') ? (num = (unsigned int)num) : (num = (int)num); /* последнее условие в тернарнике не несет смысла (просто чтобы тернарник работал)*/
	}
	if (flags->spec == 'x' || flags->spec == 'X')
	{
		hex_num = convert_v_16(num, count, flags);
		ft_putstr(hex_num);
		free(hex_num);
	}
	else
	{
		if (flags->spec == 'o')
			num = convert_v_8(num, count, flags);
	//	if (flags->width || flags->precision) /* выяснить зачем */
		// {
		temp = ft_cmp_width_prec_num(flags, num);
		if (flags->minus) /* есть флаг "-" */
		{
			if (num < 0) /* num отрицательный, есть флаг '-', флаг '+' не важен */
				ft_constructor(flags, temp, 1, num); /* ветка 1 */
			else
			{
				if (flags->plus) /* num положительный, есть флаг '-' и флаг '+' */
					ft_constructor(flags, temp, 1, num); /* ветка 2 */
				else
				{
					if (flags->space)
						ft_constructor(flags, temp, 2, num); /* ветка 3 */
					else if (!(flags->space))
						ft_constructor(flags, temp, 3, num); /* ветка 4 */
				}
			}
		}
		else
		{
			if (num < 0) /* num отрицательный, НЕТ флага '-', флаг '+' не важен */
			{
				if (flags->nul)
				{
					if (flags->dot)
						ft_constructor(flags, temp, 4, num); /* ветка 5.1 */
					else if (!(flags->dot))
						ft_constructor(flags, temp, 5, num); /* ветка 6 */
				}
				else if (!(flags->nul))
					ft_constructor(flags, temp, 4, num); /* ветка 5.2 */
			}
			else if (num >= 0)
			{
				if (flags->plus) /* num положительный, НЕТ флага '-' и ЕСТЬ флаг '+'  */
				{
					if (flags->nul)
					{
						if (flags->dot)
							ft_constructor(flags, temp, 4, num); /* ветка 7.1 */
						else if (!(flags->dot))
							ft_constructor(flags, temp, 5, num); /* ветка 8 */
					}
					else if (!(flags->nul))
						ft_constructor(flags, temp, 4, num); /* ветка 7.2 */
				}
				else if (!(flags->plus))/* num положительный, НЕТ флага '-' и НЕТ флага '+'  */
				{
					if (flags->nul)
					{
						if (flags->dot)
						{
							if (flags->space)
								ft_constructor(flags, temp, 6, num); /* ветка 9 */
							else if (!(flags->space))
								ft_constructor(flags, temp, 7, num); /* ветка 10.1 */
						}
						else if (!(flags->dot))
						{
							if (flags->space)
								ft_constructor(flags, temp, 8, num); /* ветка 11 */
							else if (!(flags->space))
								ft_constructor(flags, temp, 9, num); /* ветка 12 */
						}
					}
					else if (!(flags->nul))
					{
						if (flags->space)
							ft_constructor(flags, temp, 6, num); /* ветка 13 */
						else if (!(flags->space))
							ft_constructor(flags, temp, 7, num); /* ветка 10.2 */
					}
				}
			}
		}
		/*if (!(flags->minus))
		{
			while (temp.sp > 0)
			{
				ft_putchar(' ');
				temp.sp--;
			}
		}
		if (num < 0)
			ft_putchar('-');
		else if (num > 0 && flags->plus)
			ft_putchar('+');
		while (temp.nul > 0)
		{
			ft_putchar('0');
			temp.nul--;
		}
		ft_putnbr(ft_modul(num));
		if (flags->minus)
		{
			while (temp.sp > 0)
			{
				ft_putchar(' ');
				temp.sp--;
			}
		}*/
	// }
	/*else
	{
		ft_putnbr(num);
		*count = *count + count_of_digits(num);
	}*/
	}
	free(flags);
}

void	ft_char(va_list ap, int *count, t_flags *flags)
{
	int		ch;
	t_wp	temp;

	ch = va_arg(ap, int);
	if (flags->width)
		temp.sp = flags->width - 1;
	if (flags->minus) /* есть флаг "-" */
	{
		ft_putchar((char)ch);
		while (temp.sp > 0)
		{
			ft_putchar(' ');
			temp.sp--;
			(*count)++;
		}
	}
	else
	{
		while (temp.sp > 0)
		{
			ft_putchar(' ');
			temp.sp--;
			(*count)++;
		}
		ft_putchar((char)ch);
	}
	(*count)++;
}

void	ft_string(va_list ap, int *count, t_flags *flags)
{
	char	*str;
	t_wp	temp;

	str = va_arg(ap, char *);
	*count = *count + ft_strlen(str);
	if (flags->width)
		temp.sp = flags->width - ft_strlen(str);
	if (flags->minus) /* есть флаг "-" */
	{
		ft_putstr(str);
		while (temp.sp > 0)
		{
			ft_putchar(' ');
			temp.sp--;
			(*count)++;
		}
	}
	else
	{
		while (temp.sp > 0)
		{
			ft_putchar(' ');
			temp.sp--;
			(*count)++;
		}
		ft_putstr(str);
	}
}

void	ft_pointer(va_list ap, int *count, t_flags *flags) /* дописать перевод в шестнадцатиричную */
{
	long long	pnt;
	t_wp		temp;

	pnt = va_arg(ap, long long);
	*count = *count + count_of_digits(pnt);
	if (flags->width)
		temp.sp = flags->width - count_of_digits(pnt);
	if (flags->minus) /* есть флаг "-" */
	{
		ft_putnbrll(pnt);
		while (temp.sp > 0)
		{
			ft_putchar(' ');
			temp.sp--;
			(*count)++;
		}
	}
	else
	{
		while (temp.sp > 0)
		{
			ft_putchar(' ');
			temp.sp--;
			(*count)++;
		}
		ft_putnbrll(pnt);
	}
}

void	ft_check_modificator(t_flags *flags, char *ptr) /* Проверяет флаги hh(1), h(2), ll(3), l(4)*/
{
	while (*ptr != 'c' && *ptr != 's' && *ptr != 'p' && *ptr != 'd' && *ptr != 'i' && *ptr != 'o'
	&& *ptr != 'u' && *ptr != 'x' && *ptr != 'X' && *ptr != 'f')
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
		ptr++;
	}
}

void    ft_write_width_precision(t_flags *flags, char *p)
{
    int width;
	int	precision;

	width = 0;
	precision = 0;
    while (*p != 'c' && *p != 's' && *p != 'p' && *p != 'd' && *p != 'i' && *p != 'o'
	&& *p != 'u' && *p != 'x' && *p != 'X' && *p != 'f')
    {
        if (*p >= '0' && *p <= '9')
        {
            while (*p >= '0' && *p <= '9')
			{
				flags->width = width * 10 + *p - '0';
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
	&& *p != 'u' && *p != 'x' && *p != 'X' && *p != 'f')
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
	&& *p != 'u' && *p != 'x' && *p != 'X' && *p != 'f')
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

// void	ft_unsigned(va_list ap, int *count, t_flags *flags)
// {

// }

int		minprintf(char *fmt, ...)
{
    va_list	ap; /* указывает на очередной безымянный аргумент */
    char	*p;
	t_flags	*flags;
	int count;

	p = fmt;
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
				// if (*p == 'u')
				// {
				// 	ft_unsigned(ap, &count, flags);
				// 	break ;
				// }
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
				p++;
			}
        }
        else
			ft_putchar(*p);
		p++;
    }
    va_end(ap);
	//count = ft_count_all(fmt, count);
	return (0);
}

int main(void)
{
    //minprintf("%-+8.6d\n", -123);
	//minprintf("%-+8.6d\n", 123);
	//minprintf("%-8.6d\n", 123);
	//minprintf("%+8.6d\n", -123);
	//minprintf("%+8.6d\n", 123);
	//minprintf("%8.6d\n", 123);
	//printf("%+d\n", 0);

	// minprintf("%+5.3d\n", 12);
	// minprintf("%+5d\n", 12);

	char	*str = "hello";

	// ft_putnbr(minprintf("rabotaet %15c\n", '1'));
	// ft_putstr("\n");
	// ft_putnbr(minprintf("rabotaet %-15c\n", '1'));
	// ft_putstr("\n");

	// ft_putnbr(minprintf("rabotaet %15p\n", str));
	// ft_putstr("\n");
	// ft_putnbr(minprintf("rabotaet %-15p\n", str));
	// ft_putstr("\n");

	// ft_putnbr(minprintf("rabotaet %15s\n", "lsp"));
	// ft_putstr("\n");
	// ft_putnbr(minprintf("rabotaet %-15s\n", "lsp"));
	// ft_putstr("\n");

	// ft_putnbr(printf("rabotaet %15c\n", '1'));
	// ft_putstr("\n");
	// ft_putnbr(printf("rabotaet %-15c\n", '1'));
	// ft_putstr("\n");
	// ft_putnbr(printf("rabotaet %15p\n", str));
	// ft_putstr("\n");
	// ft_putnbr(printf("rabotaet %-15p\n", str));
	// ft_putstr("\n");
	// ft_putnbr(printf("rabotaet %15s\n", "lsp"));
	// ft_putstr("\n");
	// ft_putnbr(printf("rabotaet %-15s\n", "lsp"));

	// minprintf("%-+8.6d\n", -123);
	// printf("%-+8.6d\n", -123);
	// minprintf("%-+8.6d\n", 123);
	// printf("%-+8.6d\n", 123);
	// minprintf("%-8.6d\n", 123);
	// printf("%-8.6d\n", 123);
	// minprintf("%+8.6d\n", -123);
	// printf("%+8.6d\n", -123);
	// minprintf("%+8.6d\n", 123);
	// printf("%+8.6d\n", 123);
	// minprintf("%8.6d\n", 123);
	// printf("%8.6d\n", 123);

	// minprintf("%+8.6hhd\n", (char)2212322212322212311);
	// printf("%+8.6hhd\n", (char)2212322212322212311);
	minprintf("%x\n", 255);
	printf("%x\n", 255);
	minprintf("%hho\n", 255);
	printf("%x\n", 255);
	return (0);
}
