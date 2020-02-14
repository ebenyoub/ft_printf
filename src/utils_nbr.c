/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:34:48 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/02/14 12:34:53 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_putnbr(long long nb, t_list *list)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	if (nb != -2147483648)
	{
		if (nb < 0)
		{
			write_char('-', list);
			nb = -nb;
		}
		if (nb < 10)
			write_char(nb + 48, list);
		if (nb >= 10)
		{
			ft_putnbr(nb / 10, list);
			ft_putnbr(nb % 10, list);
		}
	}
}

int		len_nbr(long long n)
{
	int		len;

	len = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int		ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int		ft_isflag(char c, char *symbol)
{
	int i;

	i = 0;
	while (symbol[i])
	{
		if (c == symbol[i])
			return (1);
		i++;
	}
	return (0);
}
