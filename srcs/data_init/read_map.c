/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:43:53 by ubazzane          #+#    #+#             */
/*   Updated: 2024/01/25 17:33:32 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static int	is_wall(t_data *data, int i);
static void	scan_map(t_data *data, char *line, int i);

void	read_map(t_data *data, char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '\n')
			continue ;
		if (is_wall(data, i))
		{
			if (line[i] != '1')
			{
				free(line);
				ft_destroy(data, "[MAP]ERROR: invalid walls\n");
			}
		}
		else
			scan_map(data, line, i);
	}
	if (data->map->count_c < 1
		|| data->map->count_e != 1
		|| data->map->count_p != 1)
	{
		free(line);
		ft_destroy(data, "[MAP]ERROR: invalid element amount\n");
	}
}

/* This function calculates the wall positions
top wall, bottom wall, left wall, right wall */
static int	is_wall(t_data *data, int i)
{
	if (i < data->map->width
		|| i > (data->map->width + 1) * (data->map->height - 1)
		|| i % (data->map->width + 1) == 0
		|| i % (data->map->width + 1) == data->map->width - 1)
		return (1);
	else
		return (0);
}

static void	scan_map(t_data *data, char *line, int i)
{
	if (line[i] == 'C')
		data->map->count_c++;
	else if (line[i] == 'E')
		data->map->count_e++;
	else if (line[i] == 'P')
		data->map->count_p++;
	else if (line[i] != '1' && line[i] != '0')
	{
		free(line);
		ft_destroy(data, "[MAP]ERROR: invalid characters\n");
	}
}
