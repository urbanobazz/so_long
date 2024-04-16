/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:50:48 by ubazzane          #+#    #+#             */
/*   Updated: 2024/04/16 22:57:07 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	load_coordinates(t_data *data, char *line);
static void	find_position(t_data *data, char *line, int pos, int i);
static void	free_map(t_data *data, char *line, int len);
static void	call_destroy(t_data *data, char *line, char *msg);

void	validate_map(t_data *data, char *line)
{
	read_map(data, line);
	data->map->collectables
		= (t_coordinates *)malloc(sizeof(t_coordinates) * data->map->count_c);
	if (!data->map->collectables)
		call_destroy(data, line, "ERROR: malloc(collectables)\n");
	data->map->map_array = (int **)malloc(sizeof(int *) * data->map->height);
	if (!data->map->map_array)
		call_destroy(data, line, "ERROR: malloc(map_array)\n");
	data->map->exit = (t_coordinates *)malloc(sizeof(t_coordinates));
	if (!data->map->exit)
		call_destroy(data, line, "ERROR: malloc(exit)\n");
	data->map->start = (t_coordinates *)malloc(sizeof(t_coordinates));
	if (!data->map->start)
		call_destroy(data, line, "ERROR: malloc(start)\n");
	data->game->player = (t_coordinates *)malloc(sizeof(t_coordinates));
	if (!data->game->player)
		call_destroy(data, line, "ERROR: malloc(player)\n");
	load_coordinates(data, line);
}

static void	load_coordinates(t_data *data, char *line)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	pos = 0;
	while (i < data->map->height)
	{
		data->map->map_array[i]
			= (int *)malloc(sizeof(int) * (data->map->width));
		if (!data->map->map_array[i])
			free_map(data, line, i);
		j = 0;
		while (j < data->map->width)
		{
			find_position(data, line, pos, i);
			data->map->map_array[i][j++] = line[pos++] - 48;
		}
		pos++;
		i++;
	}
}

static void	find_position(t_data *data, char *line, int pos, int i)
{
	static int	count_c;

	if (line[pos] == 'C')
	{
		data->map->collectables[count_c].x = (pos - i) % data->map->width;
		data->map->collectables[count_c].y = (pos - i) / data->map->width;
		line[pos] = '0';
		count_c++;
	}
	else if (line[pos] == 'E')
	{
		data->map->exit->x = (pos - i) % data->map->width;
		data->map->exit->y = (pos - i) / data->map->width;
		line[pos] = '0';
	}
	else if (line[pos] == 'P')
	{
		data->map->start->x = (pos - i) % data->map->width;
		data->map->start->y = (pos - i) / data->map->width;
		data->game->player->x = (pos - i) % data->map->width;
		data->game->player->y = (pos - i) / data->map->width;
		line[pos] = '0';
	}
}

static void	free_map(t_data *data, char *line, int len)
{
	int	i;

	i = 0;
	while (i < len)
		free(data->map->map_array[i++]);
	free(data->map->map_array);
	free(line);
	ft_destroy(data, "ERROR: [MATRIX]\n");
}

static void	call_destroy(t_data *data, char *line, char *err)
{
	free(line);
	ft_destroy(data, err);
}
