C_NAME		=	mtclient

S_NAME		=	mtserver

SERVER		=	src/server

CLIENT		=	src/client

O			=	obj/

I			=	inc/

SSRCS		=	

CSRCS		=	

SOBJS		=	$(SSRCS:$SERVER%.c=$O%.o)

CLIENT		=	$(CSRCS:$CLIENT%.c=$O%.o)

#HEADER		=	-I $Ifract-ol.h

LIBFT		=	-L libft

CC			=	gcc -g3 -fsanitize=address #-O3 #clang

FLAGS		=	-Wall -Wextra -Werror

all:			$(C_NAME) $(S_NAME)

$(C_NAME):
				make -C libft
				printf "Making Client\n"
				$(CC) $(FLAGS) $(CSRCS) $(LIBFT) -o $(C_NAME)

$(S_NAME):
				make -C libft
				printf "Making Slient\n"
				$(CC) $(FLAGS) $(SSRCS) $(LIBFT) -o $(S_NAME)

$O%.o:			$(OBJS)
				$(CC) $(FLAGS) -c $< -o $@

re:				fclean
				make re -C libft
				$(MAKE)

clean:
				rm -rf $O*.o

fclean:			clean		
				rm -rf $(C_NAME)
				rm -rf $(S_NAME)

test:			re
				./fract_ol 1

dbg_test:		re

.PHONY:			all re clean fclean
