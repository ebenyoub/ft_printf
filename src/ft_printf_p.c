/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:28:50 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/02/14 12:28:52 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	width_upicut_down(unsigned long int nb, t_list *list)
{
	if (list->var.sign == 0 && list->var.zero == 0)
		write_sp(list->var.width - list->var.size_len, list);
	if (list->var.sign == 0 && list->var.zero == 1
			&& list->var.icut == 1)
		write_sp(list->var.width - list->var.size_len, list);
	write(1, "0x", 2);
	list->var.ret += 2;
	if (list->var.sign == 0 && list->var.zero == 1
			&& list->var.icut == 0)
		write_z(list->var.width - list->var.size_len, list);
	if (list->var.cut != 0 && list->var.icut == 1)
		ft_itoa_hex_long(nb, 'x', list);
	else if (list->var.cut == 0 && list->var.icut == 1 && nb == 0)
		write(1, "", 0);
	else
		ft_itoa_hex_long(nb, 'x', list);
	if (list->var.sign == 1)
		write_sp(list->var.width - list->var.size_len, list);
}

void	width_up_p(unsigned long int nb, t_list *list)
{
	if (list->var.cut > list->var.size_len)
	{
		if (list->var.sign == 0)
			write_sp(list->var.width - list->var.cut, list);
		write(1, "0x", 2);
		list->var.ret += 2;
		write_z(list->var.size_z, list);
		ft_itoa_hex_long(nb, 'x', list);
		if (list->var.sign == 1)
			write_sp(list->var.width - list->var.cut, list);
	}
	else
		width_upicut_down(nb, list);
}

void	width_down_p(unsigned long int nb, t_list *list)
{
	if (list->var.cut > list->var.size_len)
	{
		write(1, "0x", 2);
		list->var.ret += 2;
		write_z(list->var.size_z, list);
		ft_itoa_hex_long(nb, 'x', list);
	}
	else
	{
		write(1, "0x", 2);
		list->var.ret += 2;
		if (nb == 0 && list->var.cut == 0 && list->var.icut == 1)
			write(1, "", 0);
		else
			ft_itoa_hex_long(nb, 'x', list);
	}
}

void	ft_printf_p(t_list *list)
{
	void					*pointer;
	unsigned long int		nb;

	pointer = va_arg(list->ap, char *);
	nb = (uintmax_t)pointer;
	list->var.size_len = len_nb_long(nb);
	if (nb == 0 && list->var.icut == 0)
		list->var.width -= 1;
	list->var.width -= 2;
	list->var.size_z = list->var.cut - list->var.size_len;
	if (list->var.width > list->var.size_len)
		width_up_p(nb, list);
	else if (list->var.width < list->var.size_len)
		width_down_p(nb, list);
}
