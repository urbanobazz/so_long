NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror -DGL_SILENCE_DEPRECATION
HFILE = so_long.h
LIBFTDIR = ./libft
LIBFT = libft/libft.a
SRCS =	main.c\
		./srcs/data_init/data_init.c\
		./srcs/data_init/ft_destroy.c\
		./srcs/data_init/read_map.c\
		./srcs/data_init/read_file.c\
		./srcs/data_init/textures_init.c\
		./srcs/data_init/validate_map.c\
		./srcs/events/key_events.c\
		./srcs/events/p_moves.c\
		./srcs/check_valid_path.c\
		./srcs/render_img.c\
		./srcs/utils.c\

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
	MLX = ./mlx_linux/libmlx.a
	MLX_FLAGS = -L ./mlx_linux -lX11 -lXext -lm -lmlx -lbsd
	INCLUDE_MLX = -I/usr/include -Imlx
	MLX_DIR = ./mlx_linux
else ifeq ($(UNAME_S),Darwin)
	MLX = ./mlx/libmlx.a
	MLX_FLAGS = -L ./mlx -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit
	INCLUDE_MLX = -I/opt/X11/include -Imlx
	MLX_DIR = ./mlx
endif

INCLUDE = -L ./libft -lft

all: $(NAME)

$(NAME): $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(SRCS) $(INCLUDE) $(INCLUDE_MLX) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFTDIR)

$(MLX):
	@make -C $(MLX_DIR)

clean:
	@make clean -C $(LIBFTDIR)
	@make clean -C $(MLX_DIR)

fclean: clean
	@make fclean -C $(LIBFTDIR)
	@rm -f $(NAME)

re: fclean all
