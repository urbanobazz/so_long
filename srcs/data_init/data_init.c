/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 14:52:39 by ubazzane          #+#    #+#             */
/*   Updated: 2024/01/21 21:29:13 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	map_init(char *map_file, t_data *data);
static void	game_init(t_data *data);

t_data	*data_init(char *map_file)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_destroy(data, "ERROR: malloc(data_init)");
	data->mlx_ptr = 0;
	data->win_ptr = 0;
	data->mlx_img = 0;
	data->p_img = 0;
	data->e_img = 0;
	data->c_img = 0;
	data->wall_img = 0;
	data->floor_img = 0;
	data->map = 0;
	data->game = 0;
	game_init(data);
	map_init(map_file, data);
	textures_init(data);
	return (data);
}

static void	map_init(char *map_file, t_data *data)
{
	data->map = (t_map *)malloc(sizeof(t_map));
	if (!data->map)
		ft_destroy(data, "ERROR: malloc(map_init)");
	data->map->map_array = 0;
	data->map->width = 0;
	data->map->height = 0;
	data->map->collectables = 0;
	data->map->exit = 0;
	data->map->start = 0;
	data->map->count_c = 0;
	data->map->count_e = 0;
	data->map->count_p = 0;
	read_file(map_file, data);
}

static void	game_init(t_data *data)
{
	data->game = (t_game *)malloc(sizeof(t_game));
	if (!data->game)
		ft_destroy(data, "ERROR: malloc(game_init)");
	data->game->player = 0;
	data->game->p_up = 0;
	data->game->p_down = 0;
	data->game->p_left = 0;
	data->game->p_right = 0;
	data->game->p_moves = 0;
	data->game->p_collect = 0;
}
