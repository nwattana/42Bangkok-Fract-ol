NAME=afract-ol

MLX= -Lmlx -lmlx -framework OpenGL -framework Appkit
#MLX=
INC= -iquote ./printf/includes\
	 -iquote ./printf/libft\
	 -iquote ./inc\
	 -I./mlx/ 

RED=\033[31m
GREEN=\033[32m
MAGENTA=\033[1;35m
ENDC=\033[39m

CC=cc
CFLAG=
SLB= ./printf/libftprintf.a

INPUT=./src/input/input.c \
	  ./src/mlx_util/pix_put.c\
	  ./src/mlx_util/colour.c

SRC= $(INPUT)

all: test 

test: lib
	$(CC) $(CFLAG) $(INC) $(MLX) ./mlx/libmlx.a $(SLB) $(SRC) fractol.c -o $(NAME)

run: test
	./$(NAME) mandelbrot

setting: lib
	$(CC) $(CFLAG) $(INC) $(MLX) ./mlx/libmlx.a $(SLB) $(SRC) main.c -o $(NAME)

clean:
	@make -C ./printf/ clean
	

fclean: clean
	@make -C ./printf/ fclean
	@rm -rf $(NAME)

re: fclean setting

lib:
	make -C ./printf/
	make -C ./mlx/

greeting:
	@clear
	@printf "====================================================\n"
	@printf "====================================================\n"
	@printf "\t$(RED)HELLO!!$(ENDC) Welcome To $(MAGENTA)Fract-OL$(ENDC)\n"
	@printf "====================================================\n"
	@printf "====================================================\n"
	@git log --oneline --graph --all -n10
	@printf "====================================================\n"
	@printf "You are on\n"
	@git branch

.PHONT: all clean fclean lib
