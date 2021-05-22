# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 13:37:58 by aparolar          #+#    #+#              #
#    Updated: 2021/05/22 15:54:41 by aparolar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLRST		=	"\033[0m"
CLBGGFGW	=	"\033[1;42m"

MAKE		=	@make -s

LIBFT		=	libft

LIBS		=	$(LIBFT)/libft.a

SRCS		=	ft_printf.c\
				ft_getwidth.c\
				ft_getpadding.c\
				ft_getprecision.c\

OBJS		=	$(SRCS:.c=.o)

CC			=	@gcc $(FLAGS) -I. -I./$(LIBFT)

FLAGS		=	-Wall -Wextra -Werror

DBFLAGS		=	$(FLAGS) -g3

NAME		=	libftprintf.a

TEST_NAME	=	test

$(NAME):		$(OBJS)
				@printf $(CLBGGFGW)"%68s"$(CLRST)"\n" ""
				@printf $(CLBGGFGW)"%68s"$(CLRST)"\n" ""
				@printf $(CLBGGFGW)"%68s"$(CLRST)"\n" ""
				@printf $(CLBGGFGW)"%40s%28s"$(CLRST)"\n" "Making libftprintf" ""
				@printf $(CLBGGFGW)"%68s"$(CLRST)"\n" ""
				@printf $(CLBGGFGW)"%68s"$(CLRST)"\n" ""
				@printf $(CLBGGFGW)"%68s"$(CLRST)"\n" ""
				@printf "\n\n"
				@$(MAKE) -C $(LIBFT)
				@ar rcs $(NAME) $(OBJS)

all:			$(NAME)
				@rm -rf $(OBJS)

clean:			
				@$(MAKE) -C $(LIBFT) clean
				@rm -fr $(OBJS)

fclean:			
				@$(MAKE) clean
				@$(MAKE) -C $(LIBFT) fclean
				@rm -fr $(NAME)

re:				fclean all

test:			all
				@$(CC) -O3 main.c -o $(TEST_NAME) $(NAME) $(LIBS)
				@rm -rf *.o
				@chmod u+x test
				./test

test_asm:		all
				@$(CC) -S -O3  main.c -o $(TEST_NAME).s $(NAME) $(LIBS)

ctest:			
				@rm -rf $(TEST_NAME)

.PHONY:			all clean faclean re
