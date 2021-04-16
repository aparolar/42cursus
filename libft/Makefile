# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aparolar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 17:36:51 by aparolar          #+#    #+#              #
#    Updated: 2021/04/16 09:34:53 by aparolar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	$(wildcard *.c)

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc $(FLAGS) -I. 

FLAGS		=	-Wall -Wextra -Werror -g

NAME		=	libft.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			rm -f $(OBJS)

test:		re
			$(CC) -g  libft.a -o a.out
			./a.out

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re
