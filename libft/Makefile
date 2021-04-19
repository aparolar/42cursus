# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 17:36:51 by aparolar          #+#    #+#              #
#    Updated: 2021/04/19 09:46:48 by aparolar         ###   ########.fr        #
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
			$(CC) -g libft.a -o a.out
			./a.out
			rm -f *.o

so:		re
		$(CC) -fPIC $(CFLAGS) $(SRCS)
		gcc -shared -o libft.so $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re
