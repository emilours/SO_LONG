/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:22:02 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/22 18:55:23 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_map(t_solong *solong, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		strerror(errno);
		write(2, "\n", 1);
		close(fd);
		exit(errno);
	}
	solong->map.size = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = NULL;
		solong->map.size++;
		line = get_next_line(fd);
	}
	close(fd);
	solong->map.mapping = malloc(sizeof(char *) * solong->map.size + 1);
	fd = open(file, O_RDONLY);
	solong->map.mapping[0] = get_next_line(fd);
	solong->map.size = 0;
	while (solong->map.mapping[solong->map.size])
	{
		solong->map.size++;
		solong->map.mapping[solong->map.size] = get_next_line(fd);
	}
	solong->map.mapping[solong->map.size + 1] = 0;
}

void	set_image(t_solong *solong)
{
	int	img_width;
	int	img_height;

	solong->img.wall = mlx_xpm_file_to_image(solong->game.mlx, "txr/wall.xpm", &img_width, &img_height);
	solong->img.exit = mlx_xpm_file_to_image(solong->game.mlx, "txr/exit.xpm", &img_width, &img_height);
	solong->img.empty = mlx_xpm_file_to_image(solong->game.mlx, "txr/fond.xpm", &img_width, &img_height);
	solong->img.pos = mlx_xpm_file_to_image(solong->game.mlx, "txr/perso.xpm", &img_width, &img_height);
	solong->img.item = mlx_xpm_file_to_image(solong->game.mlx, "txr/item.xpm", &img_width, &img_height);
	solong->map.i = 0;
	while ((int)solong->map.i < solong->map.size)
	{
		solong->map.j = 0;
		while (solong->map.j < ft_strlen(solong->map.mapping[solong->map.i]))
		{
			if (solong->map.mapping[solong->map.i][solong->map.j] == 'E')
				mlx_put_image_to_window (solong->game.mlx, solong->game.win, solong->img.exit, solong->map.j * 64, solong->map.i * 64);
			else if (solong->map.mapping[solong->map.i][solong->map.j] == '1')
				mlx_put_image_to_window (solong->game.mlx, solong->game.win, solong->img.wall, solong->map.j * 64, solong->map.i * 64);
			else if (solong->map.mapping[solong->map.i][solong->map.j] == '0')
				mlx_put_image_to_window (solong->game.mlx, solong->game.win, solong->img.empty, solong->map.j * 64, solong->map.i * 64);
			else if (solong->map.mapping[solong->map.i][solong->map.j] == 'P')
				mlx_put_image_to_window (solong->game.mlx, solong->game.win, solong->img.pos, solong->map.j * 64, solong->map.i * 64);
			else if (solong->map.mapping[solong->map.i][solong->map.j] == 'C')
				mlx_put_image_to_window (solong->game.mlx, solong->game.win, solong->img.item, solong->map.j * 64, solong->map.i * 64);
			solong->map.j++;
		}
		solong->map.i++;
	}
}

void	destroy_image(t_solong *solong)
{
	if (solong->img.wall != NULL)
		mlx_destroy_image(solong->game.mlx, solong->img.wall);
	if (solong->img.exit != NULL)
		mlx_destroy_image(solong->game.mlx, solong->img.exit);
	if (solong->img.empty != NULL)
		mlx_destroy_image(solong->game.mlx, solong->img.empty);
	if (solong->img.item != NULL)
		mlx_destroy_image(solong->game.mlx, solong->img.item);
	if (solong->img.pos != NULL)
		mlx_destroy_image(solong->game.mlx, solong->img.pos);
}
