# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aparolar <aparolar@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/08 17:36:51 by aparolar          #+#    #+#              #
#    Updated: 2021/05/03 00:48:41 by aparolar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c\
				ft_memchr.c ft_memcmp.c ft_memmove.c ft_strlen.c\
				ft_isalpha.c ft_tolower.c ft_toupper.c ft_isalnum.c\
				ft_isascii.c ft_isprint.c ft_isdigit.c ft_strchr.c\
				ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_strlcpy.c\
				ft_strlcat.c ft_calloc.c ft_atoi.c ft_strdup.c\
				ft_substr.c ft_strjoin.c ft_strtrim.c ft_putchar_fd.c\
				ft_putstr_fd.c ft_putendl_fd.c ft_itoa.c ft_putnbr_fd.c\
				ft_strmapi.c ft_split.c ft_intlen.c ft_longlen.c\
				ft_atol.c

SRCS_BONUS	=	ft_lstnew.c ft_lstadd_front.c\
				ft_lstsize.c ft_lstlast.c\
				ft_lstadd_back.c ft_lstdelone.c\
				ft_lstclear.c ft_lstiter.c\
				ft_lstmap.c

OBJS		=	$(SRCS:.c=.o)

OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

CC			=	gcc $(FLAGS) -I. 

FLAGS		=	-Wall -Wextra -Werror

DBGFLAGS	=	$(FLAGS) -g3

DEBFLAGSX	=	$(FLAGS) -g3 -fsanitize=address

NAME		=	libft.a

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)
			make clean

all:		$(NAME)

bonus:		$(OBJS) $(OBJS_BONUS)
			ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)
			#make clean

clean:
			rm -f $(OBJS)
			rm -f $(OBJS_BONUS)

# for test with
test:		re
			gcc $(DBGFLAGS) -I. libft.a mmain.c -o a.out
			./a.out
			rm -f *.o

# for linux
so:			re
			$(CC) -fPIC $(CFLAGS) $(SRCS)
			gcc -shared -o libft.so $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: 	all clean fclean re
