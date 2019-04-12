/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:56:36 by draudrau          #+#    #+#             */
/*   Updated: 2019/04/12 20:57:17 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_decimal(va_list ap, int *count, int flag)
{
	long long	num;

	num = va_arg(ap, long long);
	if (flag == 1)
	{
		ft_putnbr((char)num);
		*count = *count + count_of_digits((char)num);
	}
	else if (flag == 2)
	{
		ft_putnbr((short)num);
		*count = *count + count_of_digits((short)num);
	}
	else if (flag == 3)
	{
		ft_putnbrll((long)num);
		*count = *count + count_of_digits((long)num);
	}
	else if (flag == 4)
	{
		ft_putnbrll((long long)num);
		*count = *count + count_of_digits((long long)num);
	}
	else
	{
		ft_putnbr(num);
		*count = *count + count_of_digits(num);
	}
}

void	ft_string(va_list ap, int *count)
{
    char	*str;

    str = va_arg(ap, char *);
    ft_putstr(str);
	*count = *count + ft_strlen(str);
}

void	ft_char(va_list ap, int *count)
{
    char	symbol;

    symbol = va_arg(ap, int);
    ft_putchar(symbol);
	(*count)++;
}

void	ft_pointer(va_list ap, int *count) /* Перевести в шестнадцатиричную */
{
    long long	ptr;

	ptr = va_arg(ap, long long);
	ft_putnbrll(ptr);
	*count = *count + count_of_digits(ptr);
}

int		ft_check_specification(char *c)
{
	if (*c == 'c' || *c == 's' || *c == 'p'
	|| *c == 'd' || *c == 'i' || *c == 'o'
	|| *c == 'u' || *c == 'x' || *c == 'X')
		return (1);
	else if ((*c == 'h' || *c == 'l') && (*(c + 1) == 'd' || *(c + 1) == 'i' ||
	*(c + 1) == 'o' || *(c + 1) == 'u' || *(c + 1) == 'x' || *(c + 1) == 'X'))
		return (2);
	else if (((*c == 'h' && *(c + 1) == 'h') || (*c == 'l' && *(c + 1) == 'l')) &&
	(*(c + 2) == 'd' || *(c + 2) == 'i' || *(c + 2) == 'o' || *(c + 2) == 'u' ||
	*(c + 2) == 'x' || *(c + 2) == 'X'))
		return (3);
	return (0);
}

int		ft_count_all(char *fmt, int count)
{
	while (*fmt)
	{
		if (*fmt != '%')
			count++;
		else if (*fmt == '%' && *(fmt + 1) == '%')
		{
			count++;
			fmt++;
		}
		else if (*fmt == '%' && *(fmt + 1) != '%')
			fmt += ft_check_specification(fmt + 1);
		fmt++;
	}
	return (count);
}

int		ft_check_flags(char *ptr) /* Проверяет флаги hh(1), h(2), ll(3), l(4), нет флага(0)*/
{
	if (*ptr == 'h')
	{
		if (*(ptr + 1) == 'h')
			return (1);
		else
			return (2);
	}
	else if (*ptr == 'l')
	{
		if (*(ptr + 1) == 'l')
			return (3);
		else
			return (4);
	}
	return (0);
}

int		minprintf(char *fmt, ...)
{
    va_list	ap; /* указывает на очередной безымянный аргумент */
    char	*p;
	int		count;
	int		flag;

    p = fmt;
	count = 0;
    va_start(ap, fmt); /* устанавливает ap на 1-й безымянный аргумент */
    while (*p)
    {
		if (*p =='%')
		{
			p++;
			while (*p)
			{
				flag = ft_check_flags(p);
				//ft_decimal(ap, &count, flag);
				if (flag == 1 || flag == 3) /* флаг hh или ll */
					p += 2;
				else if (flag == 2 || flag == 4)
					p += 1;
				if(*p == 'd' || *p == 'i')
				{
					ft_decimal(ap, &count, flag);
					break;
				}
				if (*p == 's')
				{
					ft_string(ap, &count);
					break ;
				}
				if (*p == 'c')
				{
					ft_char(ap, &count);
					break ;
				}
				if (*p == 'p')
				{
					ft_pointer(ap, &count);
					break ;
				}
				p++;
			}
        }
        else
			ft_putchar(*p);
		p++;
    }
    va_end(ap); /* очистка, когда все сделано */
	count = ft_count_all(fmt, count);
	return (count);
}

void	convert_v_8(long long c, int flag) /* Из десятичной в восьмиричную */
{
	int			ost[23];
	int			i;
	unsigned long long	result;
	unsigned long long	max;
	unsigned long long	temp;

	i = 0;
	result = 0;
	temp = c;
	if (c < 0)
	{
		if (flag == 1)
			max = FT_MAX_UCHAR;
		if (flag == 2)
			max = FT_MAX_USHORT;
		if (flag == 3 || flag == 4)
			max = FT_MAX_ULONG;
		else
			max = FT_MAX_UINT;
		temp = max + c; /* Отрицательный long long делаем unsigned long long */
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
		ft_putnbr(ost[i]); /* Выводим число с конца, т.к. нам надо его перевернуть */
		i--;
	}
}

void	convert_v_16(long long c, int flag) /* Из десятичной в шестнадцатиричную */
{
	int					ost[23];
	int					i;
	unsigned long long	result;
	unsigned long long	max;
	unsigned long long	temp;

	i = 0;
	result = 0;
	temp = c;
	if (c < 0)
	{
		if (flag == 1)
			max = FT_MAX_UCHAR;
		if (flag == 2)
			max = FT_MAX_USHORT;
		if (flag == 3 || flag == 4)
			max = FT_MAX_ULONG;
		else
			max = FT_MAX_UINT;
		temp = max + c; /* Отрицательный long long делаем unsigned long long */
	}
	while (temp > 15)
	{
		ost[i] = temp % 16;
		temp = temp / 16;
		i++;
	}
	ost[i] = temp;
	while (i >= 0)
	{
		if (ost[i] < 10)
			ft_putnbr(ost[i]); /* Выводим число с конца, т.к. нам надо его перевернуть */
		else
			ft_putchar((char)ost[i] - 10 + 'a');		
		i--;
	}
}


int		main()
{
	int		original;
	int		subject;
	/*int		l;
	char	*s;

	l = 29034;
	s = (char*)malloc(6);
	ft_memcpy(s, "hello", 6);*/
	/*minprintf("%d %d", 29034, 21);
	printf("\n");
	minprintf("%c %c", 'r', 'w');
	minprintf("%p", &l);
	printf("\n");
	printf("\nsubject %d\n", minprintf("%d", 456));
	printf("\noriginal %d\n", printf("%d", 123));
	subject = minprintf("hh nash %hhi", (char)32766);
	original = printf("\nhh zavod %hhi\n", (char)32765);
	printf("subj = %d, orig = %d\n", subject, original);
	subject = minprintf("h nash %hi", (short)32766);
	original = printf("\nh zavod %hi\n", (short)32765);
	printf("subj = %d, orig = %d\n", subject, original);
	subject = minprintf("ll nash %lli", (long long)212121232766);
	original = printf("\nll zavod %lli\n", (long long)212121232765);
	printf("subj = %d, orig = %d\n", subject, original);
	subject = minprintf("l nash %li", (long)212121232766);
	original = printf("\nl zavod %li\n", (long)212121232765);
	printf("subj = %d, orig = %d\n", subject, original);
	subject = minprintf("i nash %i", 2121232766);
	original = printf("\ni zavod %i\n", 2121232765);
	printf("subj = %d, orig = %d\n", subject, original);*/

	//printf("%llo %llo %#llo\n", 17223372036854775808ull, 17223372036854775808ull, 17223372036854775808ull);
	//printf("%lo %lo %#lo\n", 9223372036854775806, 9223372036854775806, 9223372036854775806);
	//
	/*printf("%d\n", convert_v_8(125, 1));
	printf("%hho\n", (char)125);
	printf("%d\n", convert_v_8(58, 2));
	printf("%d\n", convert_v_8(0, 3));*/
	convert_v_16(-2, 4);
	/*printf("%d\n", convert_v_8(-58, 4));
	printf("%d\n", convert_v_8(-8, 0));*/
	return (0);
}