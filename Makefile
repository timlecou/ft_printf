# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timlecou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/17 13:59:56 by timlecou          #+#    #+#              #
#    Updated: 2020/05/04 18:06:54 by timlecou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c pf_ft_print_x.c pf_ft_print_c.c pf_ft_print_s.c\
	   pf_ft_print_d.c pf_ft_print_u.c pf_ft_print_per.c\
	   pf_ft_print_p.c pf_utilities_1.c pf_utilities_p.c\
	   pf_utilities_u.c pf_utilities_x.c pf_fill_op.c pf_print_conversion.c\
	   pf_utilities_2.c pf_utilities_3.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Werror -Wall -Wextra

%.o: %.c
	gcc -c $(FLAGS) $< -o $@

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft all
	cp libft/libft.a .
	mv libft.a libftprintf.a
	gcc -c $(SRCS) $(FLAGS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	make clean

clean:
	/bin/rm -f $(OBJ)
	make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: clean fclean all re
