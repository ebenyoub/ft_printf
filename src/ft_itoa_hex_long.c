/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex_long.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:31:09 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/02/14 12:31:11 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				len_nb_long(unsigned long int n)
{
	int			len;

	len = 0;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

void			convert_long(char *base, unsigned long int nb, t_list *list)
{
	if (nb >= 16)
	{
		convert_long(base, nb / 16, list);
		convert_long(base, nb % 16, list);
	}
	else if (nb <= 16)
		write_char(base[nb], list);
}

void			ft_itoa_hex_long(unsigned long int n, char x, t_list *list)
{
	char		*base;
	int			len;

	base = NULL;
	len = len_nb_long(n);
	if (x == 'x')
		base = list->var.basex;
	else if (x == 'X')
		base = list->var.baseX;
	convert_long(base, n, list);
}
