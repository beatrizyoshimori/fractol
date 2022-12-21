NAME = fractol
CFLAGS = -Wall -Wextra -Werror -g3
MLX_FLAGS = -lmlx -lXext -lX11 -lm
LIBFT = ./libft/libft.a
LIBBONUS = bonus.a

SRCS := fractol.c \
	key_hooks.c \
	mouse_hooks.c \
	fractol_utils.c \
	check_arg.c \
	mandelbrot.c \
	julia.c

OBJS := $(SRCS:%.c=%.o)

OBJS := $(addprefix mandatory/, $(OBJS))

SRCS := $(addprefix mandatory/, $(SRCS))

BONUS_SRCS := fractol_bonus.c \
	key_hooks_bonus.c \
	mouse_hooks_bonus.c \
	fractol_utils_bonus.c \
	check_arg_bonus.c \
	mandelbrot_bonus.c \
	julia_bonus.c \
	burning_ship_bonus.c

BONUS_OBJS := $(BONUS_SRCS:%.c=%.o)

BONUS_OBJS := $(addprefix bonus/, $(BONUS_OBJS))

BONUS_SRCS := $(addprefix bonus/, $(BONUS_SRCS))

all: libft $(NAME)

libft:
	make -C ./libft

%.o:%.c
	cc $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(LIBFT)
	cc $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

bonus: libft $(LIBBONUS)

$(LIBBONUS): $(BONUS_OBJS)
	ar rcs $(LIBBONUS) $(BONUS_OBJS)
	cc $(LIBBONUS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

clean:
	make clean -C ./libft 
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus libft