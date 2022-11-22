NAME=fract-ol

MLX= -Lmlx -lmlx -framework OpenGL -framework Appkit
INC= -iquote ./printf/includes\
	 -iquote ./printf/libft\
	 -iquote ./inc\
	 -I./mlx/ 

RED=\033[31m
GREEN=\033[32m
MAGENTA=\033[1;35m
ENDC=\033[39m

CC=cc
CFLAG= -Wall -Wextra -Werror
SLB= ./printf/libftprintf.a

INPUT=./src/input/input.c
INIT_FUNC=./src/tn_init_prog.c

MLX_FUNC =./src/mlx_util/pix_put.c\
	 		 ./src/mlx_util/colour.c\
			 ./src/key_hook.c\
			 ./src/tn_preexit.c\
			 ./src/julia.c\
			 ./src/julia2.c\
			 ./src/mouse_hook.c

FRAC = ./src/tn_mkimg.c

SRC= $(INPUT) $(INIT_FUNC) $(MLX_FUNC) $(FRAC)

all: test 

test: lib
	$(CC) $(CFLAG) $(INC) $(MLX) ./mlx/libmlx.a $(SLB) $(SRC) fractol.c -o $(NAME)

clean:
	@make -C ./printf/ clean

fclean: clean
	@make -C ./printf/ fclean
	@rm -rf $(NAME)
	@rm -rf libmlx.a

re: fclean all

lib:
	@make -C ./printf/
	@make -C ./mlx/
	@cp ./mlx/libmlx.a ./

.PHONT: all clean fclean lib
