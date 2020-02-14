/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:15 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/02/14 12:33:24 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		find_nbr_while(const char *str, int *i, int *a, t_list *list)
{
	int b;

	b = 0;
	while (str[*i])
	{
		if (ft_isdigit(str[*i]))
		{
			while (ft_isdigit(str[*i + b]))
			{
				*a = *a * 10 + str[*i + b] - 48;
				b += 1;
			}
			break ;
		}
		else if (str[*i] == '*')
		{
			*a = va_arg(list->ap, int);
			b += 1;
			break ;
		}
		else if (ft_isflag(str[*i], list->var.index) || str[*i] == '%')
			break ;
		*i += 1;
	}
	return (b);
}

int		find_nbr(const char *str, int i, t_list *list)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	b = find_nbr_while(str, &i, &a, list);
	list->var.size = a;
	return (i + b - 1);
}
