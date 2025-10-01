NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS = srcs/core/main.c srcs/core/init_minilibx.c\
	   srcs/logic/parse_arguments.c srcs/logic/complex.c srcs/logic/iterations.c\
	   srcs/render/render_fractal.c\
	   srcs/utils/close.c srcs/utils/color.c srcs/utils/pixel.c srcs/utils/parsing.c srcs/utils/errors.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) -g $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(MLX):
	@make -C $(MLX_DIR)

%.o: %.c
	$(CC) -g $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@

clean:
	rm -f $(OBJS)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
