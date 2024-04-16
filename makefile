NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
HFILE = so_long.h
LIBFTDIR = ./libft
LIBFT = libft/libft.a
MLX = ./mlx_linux/libmlx.a
MLX_FLAGS = -L ./mlx_linux -lX11 -lXext -lm -lmlx -lbsd
INCLUDE = -L ./libft -lft
INCLUDE_MLX = -I/usr/include -Imlx
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

all: $(NAME)

$(NAME): $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) -g $(SRCS) $(INCLUDE) $(INCLUDE_MLX) $(MLX_FLAGS) -o $(NAME)

$(LIBFT):
	@make -C ./libft

$(MLX):
	@make -C ./mlx_linux

clean:
	@make clean -C $(LIBFTDIR)
	@make clean -C ./mlx_linux

fclean: clean
	@make fclean -C $(LIBFTDIR)
	@rm -f $(NAME)

re: fclean all
