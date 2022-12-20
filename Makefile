NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -lXext -lX11 -lm
LIBFT = ./libft/libft.a

SRCS = fractol.c \
	hook.c \
	fractol_utils.c \
	check_arg.c \
	mandelbrot.c \
	julia.c \
	burning_ship.c

OBJS = $(SRCS:%.c=%.o)

all: libft $(NAME)

libft:
	make -C ./libft
	make bonus -C ./libft

%.o:%.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	cc $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

bonus: libft $(NAME)

clean:
	make clean -C ./libft 
	rm -f $(OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus libft