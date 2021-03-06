/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:30:02 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/02/14 12:30:04 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	width_upicut_down_x(unsigned int nb, t_list *list)
{
	if (list->var.sign == 0 && list->var.zero == 0)
		write_sp(list->var.width - list->var.size_len, list);
	if (list->var.sign == 0 && list->var.zero == 1
			&& list->var.icut == 1)
		write_sp(list->var.width - list->var.size_len, list);
	if (list->var.sign == 0 && list->var.zero == 1
			&& list->var.icut == 0)
		write_z(list->var.width - list->var.size_len, list);
	if (list->var.cut != 0 && list->var.icut == 1)
		ft_itoa_hex_int(nb, 'x', list);
	else if (list->var.cut == 0 && nb == 0 && list->var.icut == 1)
		write(1, " ", 0);
	else
		ft_itoa_hex_int(nb, 'x', list);
	if (list->var.sign == 1)
		write_sp(list->var.width - list->var.size_len, list);
}

void	width_up_x(unsigned int nb, t_list *list)
{
	if (list->var.cut > list->var.size_len)
	{
		if (list->var.sign == 0)
			write_sp(list->var.width - list->var.cut, list);
		write_z(list->var.size_z, list);
		ft_itoa_hex_int(nb, 'x', list);
		if (list->var.sign == 1)
			write_sp(list->var.width - list->var.cut, list);
	}
	else
		width_upicut_down_x(nb, list);
}

void	width_down_x(unsigned int nb, t_list *list)
{
	if (list->var.cut > list->var.size_len)
	{
		write_z(list->var.size_z, list);
		ft_itoa_hex_int(nb, 'x', list);
	}
	else
		ft_itoa_hex_int(nb, 'x', list);
}

void	ft_printf_x(t_list *list)
{
	int		nb;

	nb = va_arg(list->ap, int);
	list->var.size_len = len_nb_int((unsigned int)nb);
	if (list->var.size_len == 0)
		list->var.size_len = 1;
	if (list->var.icut == 1 && list->var.cut == 0 && nb == 0)
		list->var.size_len = 0;
	list->var.size_z = list->var.cut - list->var.size_len;
	if (list->var.width >= list->var.size_len)
		width_up_x(nb, list);
	else if (list->var.width < list->var.size_len)
		width_down_x(nb, list);
}
