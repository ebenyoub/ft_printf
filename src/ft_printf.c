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

void	tab_init(int i, t_list *list)
{
	t_tab	tab;

	tab.ft_tab[0] = &ft_printf_str;
	tab.ft_tab[1] = &ft_printf_char;
	tab.ft_tab[2] = &ft_printf_nbr;
	tab.ft_tab[3] = &ft_printf_nbr;
	tab.ft_tab[4] = &ft_printf_x;
	tab.ft_tab[5] = &ft_printf_xx;
	tab.ft_tab[6] = &ft_printf_p;
	tab.ft_tab[7] = &ft_printf_u;
	tab.ft_tab[8] = &ft_printf_per;
	tab.ft_tab[i](list);
}

void	data_init(t_list *list)
{
	ft_strcpy(list->var.basex, "0123456789abcdef");
	ft_strcpy(list->var.baseX, "0123456789ABCDEF");
	ft_strcpy(list->var.index, "scdixXpu%");
	list->var.size_len = 0;
	list->var.size_z = 0;
	list->var.width = 0;
	list->var.star = 0;
	list->var._cut = 0;
	list->var.sign = 0;
	list->var.zero = 0;
	list->var.cut = 0;
	list->var._s = 0;
}

int		find_index(char *tab, char element)
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

int		get_flag(int i, const char *str, t_list *list)
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

int		ft_printf(const char *str, ...)
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
