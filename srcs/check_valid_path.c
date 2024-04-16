/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 17:28:51 by ubazzane          #+#    #+#             */
/*   Updated: 2024/01/26 17:55:55 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	look_for_collectables(t_data *data, int y, int x);
static int	look_for_exit(t_data *data, int y, int x);
static void	reset_map_floor(t_data *data, int y, int x);
void	print_array(t_data *data);

/* implement flood fill algorithm to check if the path is valid,
meaning all collectables can be collected and the exit can be reached. */
void	check_valid_path(t_data *data, int y, int x)
{
	int	collectables_found;
	int	exit_found;

	collectables_found = look_for_collectables(data, y, x);
	exit_found = look_for_exit(data, y, x);
	if (collectables_found != data->map->count_c)
		ft_destroy(data, "ERROR: no valid path (collectables)\n");
	if (exit_found != 1)
		ft_destroy(data, "ERROR: no valid path (exit)\n");
	reset_map_floor(data, y, x);
}

static int	look_for_collectables(t_data *data, int y, int x)
{
	int	coll;

	coll = 0;
	if (y < 0 || y >= data->map->height || x < 0 || x >= data->map->width
		|| data->map->map_array[y][x] == 1)
		return (coll);
	if (data->map->map_array[y][x] == 0)
	{
		data->map->map_array[y][x] = 2;
		if (is_collectable(data, y, x))
			coll += 1;
		coll += look_for_collectables(data, y + 1, x);
		coll += look_for_collectables(data, y - 1, x);
		coll += look_for_collectables(data, y, x + 1);
		coll += look_for_collectables(data, y, x - 1);
	}
	return (coll);
}

static int	look_for_exit(t_data *data, int y, int x)
{
	int	exit;

	exit = 0;
	if (y < 0 || y >= data->map->height || x < 0 || x >= data->map->width
		|| data->map->map_array[y][x] == 1)
		return (exit);
	if (data->map->map_array[y][x] == 2)
	{
		data->map->map_array[y][x] = 3;
		if (is_exit(data, y, x))
			exit += 1;
		exit += look_for_exit(data, y + 1, x);
		exit += look_for_exit(data, y - 1, x);
		exit += look_for_exit(data, y, x + 1);
		exit += look_for_exit(data, y, x - 1);
	}
	return (exit);
}

static void	reset_map_floor(t_data *data, int y, int x)
{
	if (y < 0 || y >= data->map->height || x < 0 || x >= data->map->width
		|| data->map->map_array[y][x] == 1)
		return ;
	if (data->map->map_array[y][x] == 3)
	{
		data->map->map_array[y][x] = 0;
		reset_map_floor(data, y + 1, x);
		reset_map_floor(data, y - 1, x);
		reset_map_floor(data, y, x + 1);
		reset_map_floor(data, y, x - 1);
	}
}

/* void	print_array(t_data *data)
{
	int i = 0;

	while (data->map->map_array[i])
	{
		ft_printf("%s", data->map->map_array[i]);
		i++;
	}
} */
