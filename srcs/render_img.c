/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:12:44 by ubazzane          #+#    #+#             */
/*   Updated: 2024/01/25 18:33:54 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	render_background(t_data *data, int y, int x);
static void	render_foreground(t_data *data, int y, int x);

void	render_img(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			render_background(data, y, x);
			render_foreground(data, y, x);
			x++;
		}
		y++;
	}
}

static void	render_background(t_data *data, int y, int x)
{
	if (data->map->map_array[y][x] == 1)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall_img, x * TILE_SIZE, y * TILE_SIZE);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->floor_img, x * TILE_SIZE, y * TILE_SIZE);
}

static void	render_foreground(t_data *data, int y, int x)
{
	if (data->map->exit->x == x && data->map->exit->y == y)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->e_img, x * TILE_SIZE, y * TILE_SIZE);
	else if (data->game->player->x == x && data->game->player->y == y)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->p_img, x * TILE_SIZE, y * TILE_SIZE);
	else if (is_collectable(data, y, x))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->c_img, x * TILE_SIZE, y * TILE_SIZE);
}
