/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:34:30 by ubazzane          #+#    #+#             */
/*   Updated: 2024/04/16 22:55:18 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx_linux/mlx.h"
/* # include "./mlx_macOS/mlx.h" */
# include "./libft/libft.h"
# include <fcntl.h>
# include <limits.h>

# ifndef TILE_SIZE
#  define TILE_SIZE 50
# endif

// coordinates structure
typedef struct s_coordinates
{
	int	x;
	int	y;
}	t_coordinates;

// Map structure
typedef struct s_map
{
	int				**map_array; // Map matrix
	int				width; // Map width
	int				height; // Map height
	t_coordinates	*collectables; // Collectables positions array
	t_coordinates	*exit; // Exit position
	t_coordinates	*start; // Start position
	int				count_c; // Number of collectables
	int				count_e; // Number of exits
	int				count_p; // Start position x
}	t_map;

typedef struct s_game
{
	t_coordinates	*player; // Player position
	int				p_up;
	int				p_down;
	int				p_left;
	int				p_right;
	int				p_moves;
	int				p_collect;
}	t_game;

typedef struct s_data
{
	void		*mlx_ptr; // MLX pointer
	void		*win_ptr; // MLX window pointer
	void		*mlx_img; // MLX image pointer
	void		*p_img; // Player image pointer
	void		*c_img; // Collectable image pointer
	void		*e_img; // Exit image pointer
	void		*wall_img; // Wall image pointer
	void		*floor_img; // Floor image pointer
	t_map		*map; // Map pointer (contains map details)
	t_game		*game; // Game pointer (contains game details)
}	t_data;

t_data	*data_init(char *map_file);
void	read_file(char *map_file, t_data *data);
void	read_map(t_data *data, char *line);
void	validate_map(t_data *data, char *line);
void	textures_init(t_data *data);
void	render_img(t_data *data);
int		ft_destroy(t_data *data, char *msg);
int		key_press(int keycode, t_data *data);
int		close_window(t_data *data);
void	move_up(t_data *data, int y, int x);
void	move_down(t_data *data, int y, int x);
void	move_left(t_data *data, int y, int x);
void	move_right(t_data *data, int y, int x);
int		is_collectable(t_data *data, int y, int x);
int		is_exit(t_data *data, int y, int x);
void	print_moves(t_data *data);
void	collect(t_data *data);
void	check_exit(t_data *data);
void	check_valid_path(t_data *data, int y, int x);

#endif
