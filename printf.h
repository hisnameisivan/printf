/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:58:56 by draudrau          #+#    #+#             */
/*   Updated: 2019/04/17 17:37:16 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# define FT_MAX_UCHAR 255
# define FT_MAX_USHORT 65535
# define FT_MAX_ULONG 18446744073709551615ul
# define FT_MAX_UINT 4294967295
# include "libft/libft.h"
#include "limits.h"

typedef struct	s_flags
{
	int			dot;
	int			resh;
	int			h;
	int			l;
	int			hh;
	int			ll;
	int			minus;
	int			plus;
	int			space;
	int			nul;
	int			bl; /* для float */
	int			ml; /* для float */
	int			procent;
	int			width; /* для ширины */
	int			precision; /* для точности */
	//va_list		ap;
}				t_flags;

typedef struct	s_wp
{
	int			nul;
	int			sp;
	int			znak; /* знак исходного числа (до применения модуля) */
}				t_wp;

void	ft_putnbrll(long long n);
void	ft_decimal(va_list ap, int *count, t_flags *flags);
//void	ft_string(va_list ap, int *count);
//void	ft_char(va_list ap, int *count);
//void	ft_pointer(va_list ap, int *count);
int		minprintf(char *fmt, ...);
int		ft_check_specification(char *c);
int		ft_count_all(char *fmt, int count);
char	*ft_itoa_long(unsigned long long n);
void    ft_write_width_precision(t_flags *flags, char *p);
int		ft_search_before_spec(char *p, char c);
void	ft_initialization(t_flags *temp);
t_flags	*ft_create_struct_printf(void);
void	ft_fill_struct(t_flags *flags, char *p);
long long	count_of_digits(long long n);

#endif
