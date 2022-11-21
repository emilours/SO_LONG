/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:22:02 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/21 20:14:24 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_map(t_map *map, char *file)
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
	map->size = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = NULL;
		map->size++;
		line = get_next_line(fd);
	}
	close(fd);
	map->mapping = malloc(sizeof(char *) * map->size + 1);
	fd = open(file, O_RDONLY);
	map->mapping[0] = get_next_line(fd);
	map->size = 0;
	while (map->mapping[map->size])
	{
		map->size++;
		map->mapping[map->size] = get_next_line(fd);
	}
	map->mapping[map->size + 1] = 0;
}

void	set_texture(t_game *game, t_map *map)
{
	int	img_width;
	int	img_height;

	map->wall = mlx_xpm_file_to_image(game->mlx, "txr/wall.xpm", &img_width, &img_height);
	map->exit = mlx_xpm_file_to_image(game->mlx, "txr/exit.xpm", &img_width, &img_height);
	map->empty = mlx_xpm_file_to_image(game->mlx, "txr/fond.xpm", &img_width, &img_height);
	map->pos = mlx_xpm_file_to_image(game->mlx, "txr/perso.xpm", &img_width, &img_height);
	map->item = mlx_xpm_file_to_image(game->mlx, "txr/item.xpm", &img_width, &img_height);
	map->i = 0;
	while ((int)map->i < map->size)
	{
		map->j = 0;
		while (map->j < ft_strlen(map->mapping[map->i]))
		{
			if (map->mapping[map->i][map->j] == 'E')
				mlx_put_image_to_window (game->mlx, game->win, map->exit, map->j * 64, map->i * 64);
			else if (map->mapping[map->i][map->j] == '1')
				mlx_put_image_to_window (game->mlx, game->win, map->wall, map->j * 64, map->i * 64);
			else if (map->mapping[map->i][map->j] == '0')
				mlx_put_image_to_window (game->mlx, game->win, map->empty, map->j * 64, map->i * 64);
			else if (map->mapping[map->i][map->j] == 'P')
				mlx_put_image_to_window (game->mlx, game->win, map->pos, map->j * 64, map->i * 64);
			else if (map->mapping[map->i][map->j] == 'C')
				mlx_put_image_to_window (game->mlx, game->win, map->item, map->j * 64, map->i * 64);
			map->j++;
		}
		map->i++;
	}
}

// 	while (index < map->size)
// 	{
// 		if (line[index] == '1')
// 			mlx_put_image_to_window (game->mlx, game->win, map->wall, 64, 64);
// 		if (line[index] == 'E')
// 			mlx_put_image_to_window (game->mlx, game->win, map->exit, 128, 128);
// 		// if (line[index] == 'C')
// 		// 	mlx_put_image_to_window (game->mlx, game->win, "txr/wall.xpm", 64, 64);
// 		// if (line[index] == 'P')
// 		// 	mlx_put_image_to_window (game->mlx, game->win, "txr/wall.xpm", 64, 64);
// 		else
// 			mlx_put_image_to_window (game->mlx, game->win, map->empty, 264, 264);
// 		index++;
// 	}
// }

// erreur map rectangulaire
// checker si les 1 au milieu voir papier
// erreir .ber : fichier cache / .ber.ber : ok ?
//erreur : recep tous les C avant de E
// loop end avant de destroy pour eviter leaks
// telecharger sprites