/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:28:11 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/02/14 12:28:16 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	width_upicut_down_d(long nb, t_list *list)
{
	if (list->var.sign == 0 && list->var.zero == 0)
		write_sp(list->var.width - list->var.size_len, list);
	if (list->var.sign == 0 && list->var.zero == 1
			&& list->var.icut == 1)
		write_sp(list->var.width - list->var.size_len, list);
	if (list->var.is == 1)
		write_char('-', list);
	if (list->var.sign == 0 && list->var.zero == 1
			&& list->var.icut == 0)
		write_z(list->var.width - list->var.size_len, list);
	if (list->var.cut != 0 && list->var.icut == 1)
		ft_putnbr(nb, list);
	else if (list->var.cut == 0 && list->var.icut == 1 && nb == 0)
		write(1, "", 0);
	else if (list->var.icut == 0)
		ft_putnbr(nb, list);
	else
		ft_putnbr(nb, list);
	if (list->var.sign == 1)
		write_sp(list->var.width - list->var.size_len, list);
}

void	width_up(long num, t_list *list)
{
	if (list->var.cut > list->var.size_len)
	{
		if (list->var.sign == 0)
			write_sp(list->var.width - list->var.cut, list);
		if (list->var.is == 1)
			write_char('-', list);
		write_z(list->var.size_z, list);
		ft_putnbr(num, list);
		if (list->var.sign == 1)
			write_sp(list->var.width - list->var.cut, list);
	}
	else
		width_upicut_down_d(num, list);
}

void	width_down(long num, t_list *list)
{
	if (list->var.cut > list->var.size_len)
	{
		if (list->var.is == 1)
			write_char('-', list);
		write_z(list->var.size_z, list);
		ft_putnbr(num, list);
	}
	else
	{
		if (list->var.is == 1)
			write_char('-', list);
		if (list->var.cut != 0 && list->var.icut == 1)
			ft_putnbr(num, list);
		else if (list->var.cut == 0 && list->var.icut == 1)
			ft_putnbr(num, list);
		else if (list->var.icut == 0)
			ft_putnbr(num, list);
		else
			write_char(' ', list);
	}
}

void	ft_printf_nbr(t_list *list)
{
	long		num;

	num = va_arg(list->ap, int);
	list->var.size_len = len_nbr(num);
	if (list->var.size_len == 0)
		list->var.size_len = 1;
	if (list->var.icut == 1 && list->var.cut == 0 && num == 0)
		list->var.size_len = 0;
	list->var.size_z = list->var.cut - list->var.size_len;
	list->var.is = 0;
	if (num < 0)
	{
		list->var.width -= 1;
		num = -num;
		list->var.is = 1;
	}
	if (list->var.width >= list->var.size_len)
		width_up(num, list);
	else if (list->var.width < list->var.size_len)
		width_down(num, list);
}
