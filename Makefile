NAME=fracl-ol

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
CFLAG=
SLB= ./printf/libftprintf.a

SRC=./src/put_pixel.c

all: greeting


setting: lib
	$(CC) $(CFLAG) $(INC) $(MLX) ./mlx/libmlx.a $(SLB) $(SRC) main.c -o $(NAME)

clean:
	@make -C ./printf/ clean
	

fclean: clean
	@make -C ./printf/ fclean
	@rm -rf $(NAME)

re: fclean all

lib:
	make -C ./printf/

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
