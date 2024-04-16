/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_moves.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:43:19 by ubazzane          #+#    #+#             */
/*   Updated: 2024/01/25 18:56:35 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	move_up(t_data *data, int y, int x)
{
	if (data->map->map_array[y - 1][x] == 0)
	{
		data->game->player->y--;
		print_moves(data);
	}
}

void	move_down(t_data *data, int y, int x)
{
	if (data->map->map_array[y + 1][x] == 0)
	{
		data->game->player->y++;
		print_moves(data);
	}
}

void	move_left(t_data *data, int y, int x)
{
	if (data->map->map_array[y][x - 1] == 0)
	{
		data->game->player->x--;
		print_moves(data);
	}
}

void	move_right(t_data *data, int y, int x)
{
	if (data->map->map_array[y][x + 1] == 0)
	{
		data->game->player->x++;
		print_moves(data);
	}
}
