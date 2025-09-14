NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = minilibx-linux
MLX = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS = -L$(MLX_DIR) -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm
LIBFT = libft/libft.a
SRCS = srcs/core/main.c srcs/core/init_minilibx.c\
	   srcs/logic/parse_arguments.c srcs/logic/complex.c srcs/logic/iterations.c\
	   srcs/render/render_fractal.c\
	   srcs/utils/utils.c srcs/utils/ft.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -g $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

%.o: %.c
	$(CC) -g $(CFLAGS) -I/usr/include -I$(MLX_DIR) -O3 -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
