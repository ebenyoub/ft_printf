/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:26:39 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/02/14 12:27:11 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				find_index(char *tab, char element)
{
	int			index;

	index = 0;
	while (tab[index])
	{
		if (tab[index] == element)
			return (index);
		index++;
	}
	return (-1);
}

int				get_flag(int i, const char *str, t_list *list)
{
	while (str[i])
	{
		if ((str[i] > '0' && str[i] <= '9') || str[i] == '*')
			i = onbr(str, i, list);
		else if (str[i] == '.')
			i = ocut(str, i, list);
		else if (str[i] == '0')
			i = ozero(str, i, list);
		else if (str[i] == '-')
			i = osign(str, i, list);
		else if (ft_isflag(str[i], list->var.index))
			return (i);
		i++;
	}
	return (i);
}

int				ft_printf(const char *str, ...)
{
	t_list		list;
	int			tmp;
	int			i;

	i = 0;
	va_start(list.ap, str);
	list.var.ret = 0;
	while (str[i])
	{
		data_init(&list);
		if (str[i] == '%')
		{
			i = get_flag(++i, str, &list);
			tmp = find_index(list.var.index, str[i]);
			if (tmp != -1)
				tab_init(tmp, &list);
		}
		else
			write_char(str[i], &list);
		i++;
	}
	va_end(list.ap);
	return (list.var.ret);
}
