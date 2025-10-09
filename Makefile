NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -Wno-cast-function-type
MLX_DIR = minilibx-linux-asahi
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
SRCS = srcs/core/main.c srcs/core/init_minilibx.c srcs/core/hooks.c\
	   srcs/logic/parse_arguments.c srcs/logic/complex.c srcs/logic/iterations.c\
	   srcs/render/render_fractal.c\
	   srcs/utils/close.c srcs/utils/color.c srcs/utils/pixel.c srcs/utils/parsing.c srcs/utils/errors.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) -g $(OBJS) $(PRINTF) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(PRINTF):
	@make -C $(PRINTF_DIR)

# MLX is already compiled, skip compilation
#$(MLX):
#	@make -C $(MLX_DIR)

%.o: %.c
	$(CC) -g $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f $(OBJS)
	@make clean -C $(PRINTF_DIR)
	# Don't clean pre-compiled minilibx
	#@make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(PRINTF_DIR)

re: fclean all
