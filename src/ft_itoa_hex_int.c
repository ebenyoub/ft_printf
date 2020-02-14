/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:31:01 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/02/14 12:31:04 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int				len_nb_int(unsigned int n)
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

void			convert_int(char *base, unsigned int nb, t_list *list)
{
	if (nb >= 16)
	{
		convert_int(base, nb / 16, list);
		convert_int(base, nb % 16, list);
	}
	else if (nb <= 16)
		write_char(base[nb], list);
}

void			ft_itoa_hex_int(unsigned int n, char x, t_list *list)
{
	char		*base;
	int			len;

	base = NULL;
	len = len_nb_int(n);
	if (x == 'x')
		base = list->var.basex;
	else if (x == 'X')
		base = list->var.baseX;
	convert_int(base, n, list);
}
