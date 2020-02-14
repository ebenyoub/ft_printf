/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:46:46 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/02/14 15:46:52 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	write_sp(int size, t_list *list)
{
	int		i;

	i = 0;
	if (size < 0)
		size = 0;
	while (i++ < size)
	{
		write(1, " ", 1);
		list->var.ret += 1;
	}
}

void	write_z(int size, t_list *list)
{
	int		i;

	i = 0;
	while (i++ < size)
	{
		write(1, "0", 1);
		list->var.ret += 1;
	}
}

void	write_char(char c, t_list *list)
{
	write(1, &c, 1);
	list->var.ret += 1;
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
