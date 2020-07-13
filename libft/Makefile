# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timlecou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/21 13:17:02 by timlecou          #+#    #+#              #
#    Updated: 2020/05/01 17:32:52 by timlecou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c\
	ft_isdigit.c ft_isprint.c ft_itoa.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
	ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c\
	ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c\
	ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c\
	ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c\
	ft_tolower.c ft_toupper.c ft_strndup.c

SRCS2 = ft_lstsize_bonus.c\
		ft_lstadd_front_bonus.c\
		ft_lstadd_back_bonus.c\
		ft_lstnew_bonus.c\
		ft_lstlast_bonus.c\
		ft_lstdelone_bonus.c\
		ft_lstclear_bonus.c\
		ft_lstiter_bonus.c\
		ft_lstmap_bonus.c

OBJ = $(SRCS:.c=.o)

OBJ2 = $(SRCS2:.c=.o)

FLAGS = -Werror -Wall -Wextra

%.o: %.c
	gcc -c $(FLAGS) $< -o $@

all : $(OBJ)
	gcc -c $(SRCS) $(FLAGS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(NAME) : $(OBJ)
	gcc -c $(SRCS) $(FLAGS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: clean
	gcc -c $(SRCS2) $(SRCS) $(FLAGS)
	ar rc $(NAME) $(OBJ2) $(OBJ)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ) $(OBJ2)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
