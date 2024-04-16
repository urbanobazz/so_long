/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:18:35 by ubazzane          #+#    #+#             */
/*   Updated: 2024/01/25 18:52:42 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	is_collectable(t_data *data, int y, int x)
{
	int	count_c;

	count_c = 0;
	while (count_c < data->map->count_c)
	{
		if (data->map->collectables[count_c].x == x
			&& data->map->collectables[count_c].y == y)
			return (1);
		count_c++;
	}
	return (0);
}

int	is_exit(t_data *data, int y, int x)
{
	if (data->map->exit->x == x && data->map->exit->y == y)
		return (1);
	return (0);
}

void	print_moves(t_data *data)
{
	data->game->p_moves++;
	ft_printf("%i moves.\n", data->game->p_moves);
}

void	collect(t_data *data)
{
	int	count_c;

	count_c = 0;
	while (count_c < data->map->count_c)
	{
		if (data->map->collectables[count_c].x == data->game->player->x
			&& data->map->collectables[count_c].y == data->game->player->y)
		{
			data->map->collectables[count_c].x = -1;
			data->map->collectables[count_c].y = -1;
			data->game->p_collect++;
		}
		count_c++;
	}
}

void	check_exit(t_data *data)
{
	if (is_exit(data, data->game->player->y, data->game->player->x))
	{
		if (data->game->p_collect == data->map->count_c)
		{
			ft_printf("Congratulations! You won!\n");
			ft_destroy(data, 0);
		}
		else
			ft_printf("You need to collect all collectables!\n");
	}
}
