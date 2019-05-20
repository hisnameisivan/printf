/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waddam <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 21:47:16 by draudrau          #+#    #+#             */
/*   Updated: 2019/05/20 22:43:55 by waddam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_complex_constructor(t_pf *pf, char *new_num, int *count)
{
	if (pf->minus)
	{
		if (pf->znak == -1)
			ft_print_sit_1(pf, new_num, count);
		else
		{
			if (pf->plus)
				ft_print_sit_1(pf, new_num, count);
			else
				ft_print_sit_2(pf, new_num, count);
		}
	}
	else
	{
		if (pf->znak == -1)
			ft_print_sit_4(pf, new_num, count);
		else
		{
			if (pf->plus)
				ft_print_sit_4(pf, new_num, count);
			else if (!(pf->plus))
				ft_print_sit_6(pf, new_num, count);
		}
	}
}

char		*ft_create_num(long long num, t_pf *pf)
{
	char	*new_num;

	new_num = NULL;
	if (pf->spec == 'x' || pf->spec == 'X')
		new_num = ft_convert_v_16(num, pf);
	else if (pf->spec == 'o')
		new_num = ft_convert_v_8(num);
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
	{
		num = ft_apply_modificator(ap, pf);
		return (num);
	}
	else
	{
		num = (int)va_arg(ap, int);
		//if (num )
		num = (((pf->spec == 'd') || (pf->spec == 'i')) ?
		(int)num : (unsigned int)num);

		return ((int)num);
	}
}
//(int)num : (unsigned int)num);

void		ft_decimal(va_list ap, int *count, t_pf *pf)
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
