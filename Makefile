NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror -Wno-cast-function-type
MLX_FLAGS = -L/usr/local/lib -lmlx -lXext -lX11 -lm -lz
PRINTF_DIR = ft_printf
PRINTF = $(PRINTF_DIR)/libftprintf.a
SRCS = srcs/core/main.c srcs/core/init_minilibx.c srcs/core/hooks.c\
	   srcs/logic/parse_arguments.c srcs/logic/complex.c srcs/logic/iterations.c\
	   srcs/render/render_fractal.c\
	   srcs/utils/close.c srcs/utils/color.c srcs/utils/pixel.c srcs/utils/parsing.c srcs/utils/errors.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
	$(CC) -g $(OBJS) $(PRINTF) $(MLX_FLAGS) -o $(NAME)

$(MLX):
	@make -C $(MLX_DIR)

$(PRINTF):
	@make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) -g $(CFLAGS) -I/usr/include -I/usr/local/include -O3 -c $< -o $@

clean:
	rm -f $(OBJS)
	@make clean -C $(PRINTF_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(PRINTF_DIR)

re: fclean all
