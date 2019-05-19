/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draudrau <draudrau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:58:56 by draudrau          #+#    #+#             */
/*   Updated: 2019/05/19 18:43:28 by draudrau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"

typedef struct	s_pf
{
	char		spec;
	int			znak;
	int			dot;
	int			resh;
	int			j;
	int			z;
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
	int			wid; /* для ширины */
	int			prec; /* для точности */
}				t_pf;

// void	ft_putnbrll(long long n);
// void	ft_decimal(va_list ap, int *count, t_flags *flags);
// //void	ft_string(va_list ap, int *count);
// //void	ft_char(va_list ap, int *count);
// //void	ft_pointer(va_list ap, int *count);
// int		minprintf(char *fmt, ...);
// int		ft_check_specification(char *c);
// int		ft_count_all(char *fmt, int count);
// char	*ft_itoa_long(unsigned long long n);
// void    ft_write_width_precision(t_flags *flags, char *p);
// int		ft_search_before_spec(char *p, char c);
// void	ft_initialization(t_flags *temp);
// t_flags	*ft_create_struct_printf(void);
// void	ft_fill_struct(t_flags *flags, char *p);
// long long	count_of_digits(long long n);

#endif
