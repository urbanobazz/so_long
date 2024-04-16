/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubazzane <ubazzane@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:31:28 by ubazzane          #+#    #+#             */
/*   Updated: 2024/01/26 19:38:14 by ubazzane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_extension(char *file);

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		ft_putstr_fd("usage:./so_long [map_file]\n", 2);
		exit (EXIT_FAILURE);
	}
	if (!ft_check_extension(argv[1]))
	{
		ft_putstr_fd("Error: Invalid file extension\n", 2);
		exit (EXIT_FAILURE);
	}
	data = data_init(argv[1]);
	check_valid_path(data, data->game->player->y, data->game->player->x);
	render_img(data);
	mlx_key_hook(data->win_ptr, key_press, data);
	mlx_hook(data->win_ptr, 17, 1L << 0, close_window, data);
	mlx_loop(data->mlx_ptr);
	ft_destroy(data, 0);
	return (EXIT_SUCCESS);
}

static int	ft_check_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}
/********************MAC_OS***************** */
/* MLX_FLAGS = -L ./mlx -Lmlx -lmlx -L/usr/X11/lib -lXext -lX11 -framework OpenGL -framework AppKit */
/* INCLUDE_MLX = -I/opt/X11/include -Imlx */
/********************LINUX********************/
