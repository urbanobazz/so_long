/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:51:53 by ubazzane          #+#    #+#             */
/*   Updated: 2024/04/16 22:57:25 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	destroy_data(t_data *data);
static void	destroy_map(t_data *data);
static void	free_matrix(int **matrix, int size);

int	ft_destroy(t_data *data, char *msg)
{
	if (data)
	{
		if (data->map)
			destroy_map(data);
		if (data->game)
		{
			if (data->game->player)
				free(data->game->player);
			free(data->game);
		}
		destroy_data(data);
		free(data);
	}
	if (msg)
		ft_putstr_fd(msg, 2);
	exit (EXIT_FAILURE);
}

static void	destroy_data(t_data *data)
{
	if (data->p_img)
		mlx_destroy_image(data->mlx_ptr, data->p_img);
	if (data->e_img)
		mlx_destroy_image(data->mlx_ptr, data->e_img);
	if (data->c_img)
		mlx_destroy_image(data->mlx_ptr, data->c_img);
	if (data->wall_img)
		mlx_destroy_image(data->mlx_ptr, data->wall_img);
	if (data->floor_img)
		mlx_destroy_image(data->mlx_ptr, data->floor_img);
	if (data->mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->mlx_img);
	if (data->win_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
		mlx_destroy_display(data->mlx_ptr);
	if (data->mlx_ptr)
		free(data->mlx_ptr);
}

static void	destroy_map(t_data *data)
{
	if (data->map->collectables)
		free(data->map->collectables);
	if (data->map->exit)
		free(data->map->exit);
	if (data->map->start)
		free(data->map->start);
	if (data->map->map_array)
		free_matrix(data->map->map_array, data->map->height);
	free(data->map);
}

static void	free_matrix(int **matrix, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(matrix[i++]);
	free(matrix);
}
