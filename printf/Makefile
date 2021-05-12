# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 13:37:58 by aparolar          #+#    #+#              #
#    Updated: 2021/05/12 16:29:09 by aparolar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT		=	../libft

LIBS		=	$(LIBFT)/libft.a

SRCS		=	ft_printf.c

OBJS		=	$(SRCS:.c=.o)

CC			=	gcc $(FLAGS) -I. $(LIBS)

FLAGS		=	-Wall -Wextra -Werror

DBFLAGS		=	$(FLAGS) -g3

NAME		=	libftprintf.a

$(NAME):		
				$(MAKE) -C $(LIBFT)
				$(OBJS)
				ar rcs $(NAME) $(OBJS)

all:			$(NAME)

clean:			
				make -C $(LIBFT) clean
				rm -f $(OBJS)

fclean:			clean
				make -C $(LIBFT) fclean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
