NAME = fractol

SRC = main.c mandelbrot.c

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -lXext -lX11

all: $(NAME)

$(NAME):
	cc $(SRC) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus