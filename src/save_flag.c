/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_flag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:32:28 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/02/14 12:32:34 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ocut(const char *str, int i, t_list *list)
{
	list->var.icut = 1;
	list->var.b = find_nbr(str, i, list);
	list->var.cut = list->var.size;
	if (list->var.cut < 0)
	{
		list->var.cut = 0;
		list->var.icut = 0;
	}
	return (list->var.b);
}

int		onbr(const char *str, int i, t_list *list)
{
	list->var.b = find_nbr(str, i, list);
	list->var.width = list->var.size;
	if (list->var.width < 0)
	{
		list->var.sign = 1;
		list->var.width *= -1;
	}
	return (list->var.b);
}

int		osign(const char *str, int i, t_list *list)
{
	(void)str;
	list->var.sign = 1;
	return (i);
}

int		ozero(const char *str, int i, t_list *list)
{
	(void)str;
	list->var.zero = 1;
	return (i);
}
