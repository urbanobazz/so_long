/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:29:54 by ubazzane          #+#    #+#             */
/*   Updated: 2024/01/27 14:23:29 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	window_init(t_data *data);
static void	*get_texture(t_data *data, char *file_path);

void	textures_init(t_data *data)
{
	window_init(data);
	data->p_img = get_texture(data, "textures/player.xpm");
	data->e_img = get_texture(data, "textures/exit.xpm");
	data->c_img = get_texture(data, "textures/collectable.xpm");
	data->wall_img = get_texture(data, "textures/wall.xpm");
	data->floor_img = get_texture(data, "textures/floor.xpm");
}

static void	window_init(t_data *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_destroy(data, "ERROR: visuals_init(1)\n");
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->map->width * TILE_SIZE,
			data->map->height * TILE_SIZE, "so_long");
	if (!data->win_ptr)
		ft_destroy(data, "ERROR: visuals_init(2)\n");
	data->mlx_img = mlx_new_image(data->mlx_ptr, data->map->width * TILE_SIZE,
			data->map->height * TILE_SIZE);
	if (!data->mlx_img)
		ft_destroy(data, "ERROR: visuals_init(3)\n");
}

static void	*get_texture(t_data *data, char *file_path)
{
	void *ptr;
	int	height;
	int	width;

	height = 50;
	width = 50;
	ptr = mlx_xpm_file_to_image(data->mlx_ptr, file_path, &width, &height);
	if (!ptr)
		ft_destroy(data, "ERROR: visuals_init(texture)\n");
	return (ptr);
}
