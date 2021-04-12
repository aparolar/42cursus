# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 17:36:51 by aparolar          #+#    #+#              #
#    Updated: 2021/04/12 20:27:36 by aparolar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			= ft_bzero.c \
			  ft_isalnum.c \
			  ft_isalpha.c \
			  ft_isascii.c \
			  ft_isdigit.c \
			  ft_isprint.c \
			  ft_memccpy.c \
			  ft_memchr.c \
			  ft_memcmp.c \
			  ft_memcpy.c \
			  ft_memmove.c \
			  ft_memset.c \
			  ft_strchr.c \
			  ft_strlen.c \
			  ft_strnstr.c \
			  ft_strrchr.c \
			  ft_tolower.c \
			  ft_toupper.c \
			  ft_strncmp.c main.c

OBJS		=	$(SRC:.c=.o)

CC			=	gcc $(FLAGS) -I.

FLAGS		=	-Wall -Wextra -Werror

NAME		= libft.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

so:
		$(CC) -fPIC $(CFLAGS) $(SRC)
		gcc -shared -o libft.so $(OBJS)

.PHONY: 	all clean fclean re
