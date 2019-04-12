/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:58:56 by draudrau          #+#    #+#             */
/*   Updated: 2019/04/12 20:34:46 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# define FT_MAX_UCHAR 255
# define FT_MAX_USHORT 65535
# define FT_MAX_ULONG 18446744073709551615ul
# define FT_MAX_UINT 4294967295
# include "libft/libft.h"

typedef union       u_flags
{
	char		sym;
	short int	sh;
	int			integer;
	long		longs;
	long long	llong;
}					t_flags;

void	ft_putnbrll(long long n);
void	ft_decimal(va_list ap, int *count, int flag);
void	ft_string(va_list ap, int *count);
void	ft_char(va_list ap, int *count);
void	ft_pointer(va_list ap, int *count);
int		minprintf(char *fmt, ...);
int		ft_check_specification(char *c);
int		ft_count_all(char *fmt, int count);
char	*ft_itoa_long(unsigned long long n);

#endif
