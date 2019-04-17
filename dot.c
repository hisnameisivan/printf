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

int		ft_modul(int num) /* возможно придется изменить на long long*/
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
	if (flags->plus)
		(temp.sp)--;
	//printf("\n__noliki %d, probely %d__\n", temp.nul, temp.sp);
	return (temp);
}

void	ft_decimal(va_list ap, int *count, t_flags *flags)
{
	int		num; /* long long не работает, но нужен */
	t_wp	temp;

	num = va_arg(ap, int); /* long long не работает, но нужен */
	/*if (flags->plus && num >= 0)
	{
		ft_putchar('+');
		(*count)++;
	}*/
	if (flags->width || flags->precision)
	{
		temp = ft_cmp_width_prec_num(flags, num);
		// if (flags->minus) /* есть флаг "-" */
		// {
		// 	if (temp.znak == -1 ) /* num отрицательный, есть флаг '-', флаг '+' не важен */
		// 	{
		// 		ft_putchar('-');
		// 		while (temp.nul > 0)
		// 		{
		// 			ft_putchar('0');
		// 			temp.nul--;
		// 		}
		// 		ft_putnbr(ft_modul(num));
		// 		while (temp.sp > 0)
		// 		{
		// 			ft_putchar(' ');
		// 			temp.sp--;
		// 		}
		// 	}
		// 	else
		// 	{
		// 		if (flags->plus) /* num положительный, есть флаг '-' и флаг '+' */
		// 		{
		// 			ft_putchar('+');
		// 			while (temp.nul > 0)
		// 			{
		// 				ft_putchar('0');
		// 				temp.nul--;
		// 			}
		// 			ft_putnbr(ft_modul(num));
		// 			while (temp.sp > 0)
		// 			{
		// 				ft_putchar(' ');
		// 				temp.sp--;
		// 			}
		// 		}
		// 		else
		// 		{
		// 			while (temp.nul > 0)
		// 			{
		// 				ft_putchar('0');
		// 				temp.nul--;
		// 			}
		// 			ft_putnbr(ft_modul(num));
		// 			while (temp.sp > 0)
		// 			{
		// 				ft_putchar(' ');
		// 				temp.sp--;
		// 			}
		// 		}
		// 	}
		// }
		// else
		// {
		// 	if (temp.znak == -1) /* num отрицательный, НЕТ флага '-', флаг '+' не важен */
		// 	{
		// 		while (temp.sp > 0)
		// 		{
		// 			ft_putchar(' ');
		// 			temp.sp--;
		// 		}
		// 		ft_putchar('-');
		// 		while (temp.nul > 0)
		// 		{
		// 			ft_putchar('0');
		// 			temp.nul--;
		// 		}
		// 		ft_putnbr(ft_modul(num));
		// 	}
		// 	else
		// 	{
		// 		if (flags->plus) /* num положительный, НЕТ флага '-' и ЕСТЬ флаг '+'  */
		// 		{
		// 			while (temp.sp > 0)
		// 			{
		// 				ft_putchar(' ');
		// 				temp.sp--;
		// 			}
		// 			ft_putchar('+');
		// 			while (temp.nul > 0)
		// 			{
		// 				ft_putchar('0');
		// 				temp.nul--;
		// 			}
		// 			ft_putnbr(ft_modul(num));
		// 		}
		// 		else /* num положительный, НЕТ флага '-' и НЕТ флага '+'  */
		// 		{
		// 			while (temp.sp > 0)
		// 			{
		// 				ft_putchar(' ');
		// 				temp.sp--;
		// 			}
		// 			while (temp.nul > 0)
		// 			{
		// 				ft_putchar('0');
		// 				temp.nul--;
		// 			}
		// 			ft_putnbr(ft_modul(num));
		// 		}
		// 	}
		// }
		if (!(flags->minus))
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
		}
	}

	if (flags->hh)
	{
		ft_putnbr((char)num);
		*count = *count + count_of_digits((char)num);
	}
	else if (flags->h)
	{
		ft_putnbr((short)num);
		*count = *count + count_of_digits((short)num);
	}
	else if (flags->l)
	{
		ft_putnbrll((long)num);
		*count = *count + count_of_digits((long)num);
	}
	else if (flags->ll)
	{
		ft_putnbrll((long long)num);
		*count = *count + count_of_digits((long long)num);
	}
	/*else
	{
		ft_putnbr(num);
		*count = *count + count_of_digits(num);
	}*/
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

void	ft_pointer(va_list ap, int *count, t_flags *flags)
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
	if (*ptr == 'h')
	{
		if (*(ptr + 1) == 'h')
			flags->hh = 1;
		else
			flags->h = 1;
	}
	else if (*ptr == 'l')
	{
		if (*(ptr + 1) == 'l')
			flags->ll = 1;
		else
			flags->l = 1;
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
	int		flag_dot;

	width = 0;
	flag_dot = 0;
	if ((flag_dot = ft_search_before_spec(p, '.')) == 1)
	{
		ft_write_width_precision(flags, p);
		flags->dot = 1;
	}
	ft_check_modificator(flags, p);
    while (*p != 'c' && *p != 's' && *p != 'p' && *p != 'd' && *p != 'i' && *p != 'o'
	&& *p != 'u' && *p != 'x' && *p != 'X' && *p != 'f')
	{
		if (*p >= '0' && *p <= '9' && flag_dot == 0)
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
		else if (*p == '0')
			flags->nul = 1;
		else if (*p == 'L')
			flags->bl = 1;
		else if (*p == '%')
			flags->procent = 1;
		p++;
	}
}

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
				if (*p == 'd' || *p == 'i')
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

	char	*str;

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

	minprintf("%-+8.6d\n", -123);
	minprintf("%-+8.6d\n", 123);
	minprintf("%-8.6d\n", 123);
	minprintf("%+8.6d\n", -123);
	minprintf("%+8.6d\n", 123);
	minprintf("%8.6d\n", 123);
	return (0);
}
