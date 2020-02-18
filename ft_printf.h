/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebenyoub <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 12:36:23 by ebenyoub          #+#    #+#             */
/*   Updated: 2020/02/15 12:36:28 by ebenyoub         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>

typedef struct	s_var
{
	char		basex[16];
	char		basexx[16];
	char		index[9];
	int			size_len;
	int			size_z;
	int			width;
	int			star;
	int			zero;
	int			sign;
	int			size;
	int			cut;
	int			icut;
	int			ret;
	int			is;
	int			b;
}				t_var;

typedef struct	s_list
{
	va_list		ap;
	t_var		var;
}				t_list;

typedef struct	s_tab
{
	void		(*ft_tab[9])(t_list *);
}				t_tab;

int				ocut(const char *str, int i, t_list *list);
int				onbr(const char *str, int i, t_list *list);
int				osign(const char *str, int i, t_list *list);
int				ozero(const char *str, int i, t_list *list);

char			*ft_strcpy(char *dest, const char *src);
void			ft_itoa_hex_long(unsigned long int n, char x, t_list *list);
void			ft_itoa_hex_int(unsigned int n, char x, t_list *list);
void			ft_putnbr(long long nb, t_list *list);
void			write_sp(int size, t_list *list);
void			write_char(char c, t_list *list);
void			write_z(int size, t_list *list);
void			tab_init(int i, t_list *list);
void			data_init(t_list *list);
int				find_nbr(const char *str, int i, t_list *list);
int				len_nb_long(unsigned long int n);
int				ft_isflag(char c, char *symbol);
int				len_nb_int(unsigned int n);
int				ft_strlen(char *str);
int				len_nbr(long long n);
int				ft_isdigit(int c);

void			ft_printf_str(t_list *list);
void			ft_printf_char(t_list *list);
void			ft_printf_nbr(t_list *list);
void			ft_printf_x(t_list *list);
void			ft_printf_xx(t_list *list);
void			ft_printf_p(t_list *list);
void			ft_printf_u(t_list *list);
void			ft_printf_per(t_list *list);
int				ft_printf(const char *str,
				...) __attribute__((format(printf,1,2)));

#endif
