# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aparolar <aparolar@student.42madrid>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/12 13:37:58 by aparolar          #+#    #+#              #
#    Updated: 2021/07/11 12:45:53 by aparolar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLRST		=	"\033[0m"
CLBGGFGW	=	"\033[1;42m"
CLBGBFGW	=	"\033[1;44m"

MAKE		=	@make -s

LIBFT		=	./libft

LIBS		=	$(LIBFT)/libft.a

SRCS		=	ft_printf.c\
				ft_utils.c\
				ft_flagutils.c\
				ft_preparse.c\
				ft_check.c\
				ft_parsebypass.c\
				ft_parse_s.c\
				ft_parse_c.c\
				ft_parse_p.c\
				ft_parse_d.c\
				ft_parse_i.c\
				ft_parse_u.c\
				ft_parse_x.c\
				ft_parse_ux.c\
				ft_parse_perback.c\
				$(LIBFT)/ft_putchar.c\
				$(LIBFT)/ft_putstr.c\
				$(LIBFT)/ft_strlen.c\
				$(LIBFT)/ft_atoi.c\
				$(LIBFT)/ft_isdigit.c\


OBJS		=	$(SRCS:.c=.o)
LOBJ		=	$(SRCS:$LIBFT/.c=$LIBFT/.o)

CC			=	@gcc $(FLAGS) -I. -I$(LIBFT)

FLAGS		=	#-Wall -Wextra -Werror

DBFLAGS		=	$(FLAGS) -g3

NAME		=	libftprintf.a

TEST_NAME	=	test

$(NAME):		$(OBJS)
				@printf $(CLBGBFGW)"%68s"$(CLRST)"\n" ""
				@printf $(CLBGGFGW)"%68s"$(CLRST)"\n" ""
				@printf $(CLBGGFGW)"%68s"$(CLRST)"\n" ""
				@printf $(CLBGGFGW)"%40s%28s"$(CLRST)"\n" "Making libftprintf" ""
				@printf $(CLBGGFGW)"%68s"$(CLRST)"\n" ""
				@printf $(CLBGGFGW)"%68s"$(CLRST)"\n" ""
				@printf $(CLBGBFGW)"%68s"$(CLRST)"\n" ""
				@printf "\n\n"
				@$(MAKE) -C $(LIBFT)
				ar rcs $(NAME) $(OBJS) $(LOBJ) $(LIBFT)/libft.a
				@$(MAKE) clean

all:			$(NAME)
				@rm -rf $(OBJS)

clean:			
				@printf $(CLBGBFGW)"%68s"$(CLRST)"\n" ""
				@printf $(CLBGGFGW)"%68s"$(CLRST)"\n" ""
				@printf $(CLBGGFGW)"%68s"$(CLRST)"\n" ""
				@printf $(CLBGGFGW)"%40s%28s"$(CLRST)"\n" "Cleaning libftprintf" ""
				@printf $(CLBGGFGW)"%68s"$(CLRST)"\n" ""
				@printf $(CLBGGFGW)"%68s"$(CLRST)"\n" ""
				@printf $(CLBGBFGW)"%68s"$(CLRST)"\n" ""
				@printf "\n"
				@$(MAKE) -C $(LIBFT) clean
				@rm -fr $(OBJS)

fclean:			
				@printf $(CLBGBFGW)"%68s"$(CLRST)"\n" ""
				@printf $(CLBGGFGW)"%68s"$(CLRST)"\n" ""
				@printf $(CLBGGFGW)"%68s"$(CLRST)"\n" ""
				@printf $(CLBGGFGW)"%40s%28s"$(CLRST)"\n" "Removing "$(NAME) ""
				@printf $(CLBGGFGW)"%68s"$(CLRST)"\n" ""
				@printf $(CLBGGFGW)"%68s"$(CLRST)"\n" ""
				@printf $(CLBGBFGW)"%68s"$(CLRST)"\n" ""
				@printf "\n"
				@$(MAKE) -C $(LIBFT) fclean
				@rm -fr $(NAME)

re:				clean fclean all

test:			re
				@$(CC) -L. -L$(LIBFT) main.c -o $(TEST_NAME) -lftprintf -lft
				@rm -rf *.o
				@chmod u+x test
				./test
				@rm test

test_asm:		all
				@$(CC) -S -O3  main.c -o $(TEST_NAME).s $(NAME) $(LIBS)

ctest:			
				@rm -rf $(TEST_NAME)

.PHONY:			all clean faclean re
