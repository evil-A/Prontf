/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evila-ro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:47:52 by evila-ro          #+#    #+#             */
/*   Updated: 2020/02/11 13:07:34 by evila-ro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	hexx(t_some *some)
{
	unsigned int	d;

	d = va_arg(some->args, unsigned int);
	if (d == 0 && !some->val && some->point)
		z_val(some);
	else
	{
		some->str = ft_itoxx(d);
		some->len = ft_strlen(some->str);
	}
	fix(some);
	if (some->hyphen)
		f_hyp(some);
	else if (some->zero)
		f_z(some);
	else if (!some->hyphen)
	{
		f_left(some);
		ft_putstr_fd(some->str, 1);
	}
	some->pos++;
	some->posline += some->len;
}
