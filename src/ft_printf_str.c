/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:29:20 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/02/14 12:29:22 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_printf_char(t_list *list)
{
	int		c;

	c = va_arg(list->ap, int);
	if (list->var.sign == 0)
		write_sp(list->var.width - 1, list);
	write_char(c, list);
	if (list->var.sign == 1)
		write_sp(list->var.width - 1, list);
}

void	ft_printf_per(t_list *list)
{
	if (list->var.sign == 0 && list->var.zero == 0)
		write_sp(list->var.width - 1, list);
	if (list->var.sign == 0 && list->var.zero == 1)
		write_z(list->var.width - 1, list);
	write_char('%', list);
	if (list->var.sign == 1)
		write_sp(list->var.width - 1, list);
}

void	ft_str_null(t_list *list)
{
	list->var.cut > 0 ? write(1, "(", 1) : 0;
	list->var.cut > 1 ? write(1, "n", 1) : 0;
	list->var.cut > 2 ? write(1, "u", 1) : 0;
	list->var.cut > 3 ? write(1, "l", 1) : 0;
	list->var.cut > 4 ? write(1, "l", 1) : 0;
	list->var.cut > 5 ? write(1, ")", 1) : 0;
}

void	ft_str_write(char *str, int a, t_list *list)
{
	int i;

	i = 0;
	if (str == NULL)
	{
		if (list->var.icut == 0)
		{
			write(1, "(null)", 6);
			list->var.ret += 6;
		}
		else
		{
			ft_str_null(list);
			if (list->var.cut > 6)
				list->var.ret += 6;
			else
				list->var.ret += list->var.cut;
		}
	}
	else
		while (i < a)
			write_char(str[i++], list);
}

void	ft_printf_str(t_list *list)
{
	char	*str;
	int		a;
	int		i;

	i = 0;
	a = 0;
	str = va_arg(list->ap, char *);
	if (str != NULL)
		a = ft_strlen(str);
	else
		a = 6;
	if (a > list->var.cut && list->var.icut == 1)
		a = list->var.cut;
	if (list->var.width > a && list->var.sign == 0)
		write_sp(list->var.width - a, list);
	ft_str_write(str, a, list);
	if (list->var.width > a && list->var.sign == 1)
		write_sp(list->var.width - a, list);
}
