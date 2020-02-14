/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:57:13 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/02/14 12:57:18 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void		width_up_cut_down_u(long nb, t_list *list)
{
	if (list->var.sign == 0 && list->var.zero == 0)
		write_sp(list->var.width - list->var.size_len, list);
	if (list->var.sign == 0 && list->var.zero == 1
			&& list->var._cut == 1)
		write_sp(list->var.width - list->var.size_len, list);
	if (list->var.zero == 1 && list->var._cut == 0)
		write_z(list->var.width - list->var.size_len, list);
	if (list->var.cut == 0 && nb == 0 && list->var._cut == 1)
		write(1, " ", 0);
	else
		ft_putnbr(nb, list);
	if (list->var.sign == 1)
		write_sp(list->var.width - list->var.size_len, list);
}

void		width_up_u(long long num, t_list *list)
{
	if (list->var.cut > list->var.size_len)
	{
		if (list->var.sign == 0)
			write_sp(list->var.width - list->var.cut, list);
		write_z(list->var.size_z, list);
		ft_putnbr(num, list);
		if (list->var.sign == 1)
			write_sp(list->var.width - list->var.cut, list);
	}
	else
		width_up_cut_down_u(num, list);
}

void		width_down_u(long long num, t_list *list)
{
	if (list->var.cut > list->var.size_len)
	{
		write_z(list->var.size_z, list);
		ft_putnbr(num, list);
	}
	else
		ft_putnbr(num, list);
}

long long	convertion(long long num)
{
	if (num < 0)
		num = 4294967296 - (-num);
	return (num);
}

void		ft_printf_u(t_list *list)
{
	int			a;
	long long	num;

	a = va_arg(list->ap, int);
	num = convertion((long long)a);
	list->var.size_len = len_nbr(num);
	if (list->var.size_len == 0)
		list->var.size_len = 1;
	if (list->var._cut == 1 && list->var.cut == 0 && num == 0)
		list->var.size_len = 0;
	list->var.size_z = list->var.cut - list->var.size_len;
	list->var._s = 0;
	if (list->var.width >= list->var.size_len)
		width_up_u(num, list);
	else if (list->var.width < list->var.size_len)
		width_down_u(num, list);
}
