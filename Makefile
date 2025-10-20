NAME			:= fractol
CC				:= cc

CFLAGS			:= -Wall -Wextra -Werror -Wno-cast-function-type
MLX_FLAGS		:= -L/usr/local/lib -lmlx -lXext -lX11 -lm -lz

PRINTF_DIR		:= ft_printf
PRINTF			:= $(PRINTF_DIR)/libftprintf.a

SRCS			:= srcs/core/main.c \
				   srcs/core/init_minilibx.c \
				   srcs/core/hooks.c \
				   srcs/logic/parse_arguments.c \
				   srcs/logic/complex.c \
				   srcs/logic/iterations.c \
				   srcs/render/render_fractal.c \
				   srcs/utils/close.c \
				   srcs/utils/color.c \
				   srcs/utils/pixel.c \
				   srcs/utils/parsing.c \
				   srcs/utils/errors.c

OBJS			:= $(SRCS:.c=.o)

RESET			:= \033[0m
RED				:= \033[0;31m
GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m

all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
	@printf "$(YELLOW)[COMPILING]$(RESET) $(SRCS)\n"
	@$(CC) $(OBJS) $(PRINTF) $(MLX_FLAGS) -o $(NAME)

$(PRINTF):
	@printf "$(YELLOW)[MAKING PRINTFLIBFT]$(RESET) $(SRCS)\n"
	@$(MAKE) -s -C $(PRINTF_DIR)

%.o: %.c
	@printf "$(YELLOW)[COMPILING]$(RESET) $(<)\n"
	@$(CC) $(CFLAGS) -I/usr/include -I/usr/local/include -O3 -c $< -o $@

clean:
	@printf "$(YELLOW)[CLEAN]$(RESET) $(OBJS)\n"
	@rm -f $(OBJS)
	@$(MAKE) -s clean -C $(PRINTF_DIR)

fclean: clean
	@printf "$(YELLOW)[FULL CLEAN]$(RESET) $(OBJS)\n"
	@rm -f $(NAME)
	@$(MAKE) -s fclean -C $(PRINTF_DIR)

re: fclean all
