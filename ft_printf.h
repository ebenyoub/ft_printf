/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ebenyoub <ebenyoub@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/26 20:14:59 by ebenyoub     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/13 18:36:53 by ebenyoub    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>

/*____________________________________________________________
**				VARIABLES
**____________________________________________________________
*/

typedef struct	s_var
{
	char		basex[16];
	char		baseX[16];
	char		index[9];
	int			ret;
	int			cut;
	int			_cut;
	int			width;
	int			star;
	int			zero;
	int			sign;
	int			size;
	int			size_len;
	int			size_z;
	int			_s;
	int			b;
}				t_var;

/*____________________________________________________________
**				STRUCURES
**____________________________________________________________
*/

typedef struct	s_list
{
	va_list		ap;
	t_var		var;
}				t_list;

/*____________________________________________________________
**				TABLEAU DE POINTEUR DE FONCTIONS
**____________________________________________________________
*/

typedef struct	s_tab
{
	void		(*ft_tab[9])(t_list *);
}				t_tab;

/*____________________________________________________________
**				SAVE FLAGS
**____________________________________________________________
*/

int				ocut(const char *str, int i, t_list *list);
int     		onbr(const char *str, int i, t_list *list);
int				osign(const char *str, int i, t_list *list);
int				ozero(const char *str, int i, t_list *list);

/*____________________________________________________________
**				LIBFT
**____________________________________________________________
*/

char			*ft_strcpy(char *dest, const char *src);
void			tab_init(int i, t_list *list);
void			data_init(t_list *list);
void			write_sp(int size, t_list *list);
int     		find_nbr(const char *str, int i, t_list *list);
int				ft_isdigit(int c);
void			ft_itoa_hex_long(unsigned long int n, char x, t_list *list);
void			ft_itoa_hex_int(unsigned int n, char x, t_list *list);
void			write_char(char c, t_list *list);
void			write_z(int size, t_list *list);
int				ft_strlen(char *str);
int     		ft_isflag(char c, char *symbol);
void			ft_putnbr(long long nb, t_list *list);
int				len_nbr(long long n);
int				len_nb_int(unsigned int n);
int				len_nb_long(unsigned long int n);


/*____________________________________________________________
**				CONVERSIONS
**____________________________________________________________
*/

void			ft_printf_str(t_list *list);
void			ft_printf_char(t_list *list);
void			ft_printf_nbr(t_list *list);
void			ft_printf_x(t_list *list);
void			ft_printf_xx(t_list *list);
void			ft_printf_p(t_list *list);
void			ft_printf_u(t_list *list);
void			ft_printf_per(t_list *list);
int		        ft_printf(const char *str, ...) 
				__attribute__((format(printf, 1, 2)));

#endif
