/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:27:22 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/02/14 12:27:47 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		ft_printf_char(t_list *list)
{
	int		c;

	c = va_arg(list->ap, int);
	if (list->var.sign == 0)
		write_sp(list->var.width - 1, list);
	write_char(c, list);
	if (list->var.sign == 1)
		write_sp(list->var.width - 1, list);
}

void		ft_printf_per(t_list *list)
{
	if (list->var.sign == 0 && list->var.zero == 0)
		write_sp(list->var.width - 1, list);
	if (list->var.sign == 0 && list->var.zero == 1)
		write_z(list->var.width - 1, list);
	write_char('%', list);
	if (list->var.sign == 1)
		write_sp(list->var.width - 1, list);
}
