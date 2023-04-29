NAME = fractol
CFLAGS = -Wall -Wextra -Werror -g3
MLX_FLAGS = -lmlx -lXext -lX11 -lm
LIBFT = ./libft/libft.a
BONUSLIB = ./bonus/libbonus.a

SRCS = mandatory/fractol.c \
	mandatory/key_hooks.c \
	mandatory/mouse_hooks.c \
	mandatory/fractol_utils.c \
	mandatory/check_arg.c \
	mandatory/mandelbrot.c \
	mandatory/julia.c

OBJS = $(SRCS:%.c=%.o)

BONUS_SRCS = bonus/fractol_bonus.c \
	bonus/key_hooks_bonus.c \
	bonus/mouse_hooks_bonus.c \
	bonus/fractol_utils_bonus.c \
	bonus/check_arg_bonus.c \
	bonus/mandelbrot_bonus.c \
	bonus/julia_bonus.c \
	bonus/burning_ship_bonus.c

BONUS_OBJS = $(BONUS_SRCS:%.c=%.o)

all: libft $(NAME)

libft:
	make -C ./libft

%.o:%.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	cc $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

bonus: libft $(BONUSLIB)

$(BONUSLIB): $(BONUS_OBJS) $(LIBFT)
	ar rcs $(BONUSLIB) $(BONUS_OBJS)
	cc $(BONUSLIB) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	make clean -C ./libft 
	rm -f $(OBJS) $(BONUS_OBJS) $(BONUSLIB)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus libft