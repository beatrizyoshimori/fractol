NAME = fractol

SRC = fractol.c mandelbrot.c hook.c fractol_utils.c

OBJ = $(SRC:%.c=%.o)

CFLAGS = -Wall -Wextra -Werror

MLX_FLAGS = -lmlx -lXext -lX11

all: $(NAME)

$(NAME):
	cc -g3 $(CFLAGS) $(SRC) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus