NAME		=	#Nombre

S			=	src/

O			=	obj/

I			=	inc/

SRCS		=	$(wildcard $S*.c)

OBJS		=	$(SRCS:$S%.c=$O%.o)

HEADER		=	-I $Ifract-ol.h

LIBFT		=	-L libft

#MLIBX		=	-L lib/minilibx-linux -lmlx -framework OpenGL -framework AppKit
#MLIBXL		=	-L lib/minilibx-linux -lmlx_Linux -lX11 -lXext
#LIBMATH		=	-lm

CC			=	gcc -g3 -fsanitize=address #-O3 #clang

FLAGS		=	-Wall -Wextra -Werror

all:			$(NAME)

$(NAME):
#				make -C lib/libft
#				make -C lib/minilibx-linux
				$(CC) $(FLAGS) $(SRCS) $(LIBMATH) $(LIBFT) $(MLIBXL) -o $(NAME)

$O%.o:			$(OBJS)
				$(CC) $(FLAGS) -c $< -o $@

re:				fclean
				make re -C libft
				#make re -C lib/minilibx-linux
				$(MAKE)

clean:
				rm -rf $O*.o

fclean:			clean		
				rm -rf $(NAME)

test:			re
				./fract_ol 1

dbg_test:		re

.PHONY:			all re clean fclean
