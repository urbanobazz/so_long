/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:18:52 by ubazzane          #+#    #+#             */
/*   Updated: 2025/01/09 16:58:43 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

#if defined(__linux__)
/* ------- keycodes for linux------ */
int	key_press(int keycode, t_data *data)
{
	int	y;
	int	x;

	y = data->game->player->y;
	x = data->game->player->x;
	if (keycode == 119 || keycode == 65362)
		move_up(data, y, x);
	else if (keycode == 115 || keycode == 65364)
		move_down(data, y, x);
	else if (keycode == 97 || keycode == 65361)
		move_left(data, y, x);
	else if (keycode == 100 || keycode == 65363)
		move_right(data, y, x);
	else if (keycode == 65307)
		ft_destroy(data, 0);
	collect(data);
	render_img(data);
	check_exit(data);
	return (0);
}

#elif defined(__APPLE__)
/* ---- keycodes for MAC ----- */
int	key_press(int keycode, t_data *data)
{
	int	y;
	int	x;

	y = data->game->player->y;
	x = data->game->player->x;
	if (keycode == 126)
		move_up(data, y, x);
	else if (keycode == 125)
		move_down(data, y, x);
	else if (keycode == 123)
		move_left(data, y, x);
	else if (keycode == 124)
		move_right(data, y, x);
	else if (keycode == 53)
		ft_destroy(data, 0);
	collect(data);
	render_img(data);
	check_exit(data);
	return (0);
}
#endif

int	close_window(t_data *data)
{
	ft_destroy(data, 0);
	return (0);
}
