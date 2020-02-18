# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: ebenyoub <ebenyoub@student.le-101.fr>      +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/12/16 18:30:23 by ebenyoub     #+#   ##    ##    #+#        #
#    Updated: 2020/02/14 11:55:00 by ebenyoub    ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME	= libftprintf.a

FLAGS	= -Wall -Wextra -Werror

CC		= gcc

DIR_S	= src

DIR_O	= temporary

HEADER	= ft_printf.h

SOURCES	= 	ft_printf_nbr.c		find_nbr.c\
			ft_printf_p.c		ft_printf_str.c\
			ft_printf_u.c		ft_printf_x.c\
			ft_printf_xx.c		ft_printf.c\
			ft_itoa_hex_int.c	ft_itoa_hex_long.c\
			utils_str.c			utils_nbr.c\
			save_flag.c

SRCS	= $(addprefix $(DIR_S)/,$(SOURCES))

SOBJS	= $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(SOBJS) $(HEADER)
	ar rc $(NAME) $(SOBJS)
	ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(SOBJS)
	@rm -rf $(DIR_O)

fclean: clean
	@rm -f $(NAME)

re: fclean all