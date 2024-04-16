/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 20:10:15 by ubazzane          #+#    #+#             */
/*   Updated: 2024/04/16 22:56:33 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

static void	write_line(char **line, char **file, t_data *data, int i);
static char	*make_file(t_data *data);

void	read_file(char *map_file, t_data *data)
{
	int		fd;
	char	*line;
	char	*file;
	int		i;

	i = 0;
	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		ft_destroy(data, "ERROR: unable to open file");
	file = make_file(data);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		(data->map->height)++;
		write_line(&line, &file, data, i);
		free(line);
		i++;
	}
	close(fd);
	validate_map(data, file);
	free(file);
}

static void	write_line(char **line, char **file, t_data *data, int i)
{
	char	*tmp;

	if (i == 0)
		data->map->width = ft_strlen(*line) - 1;
	tmp = ft_strjoin(*file, *line);
	free(*file);
	*file = tmp;
}

static char	*make_file(t_data *data)
{
	char	*file;

	file = malloc(sizeof(char));
	if (file == NULL)
		ft_destroy(data, "ERROR: unable to allocate memory");
	file[0] = '\0';
	return (file);
}
