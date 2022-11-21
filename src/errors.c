/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:21:32 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/20 19:11:46 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_game(t_game *game)
{
	mlx_loop_end(game->mlx);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

int	argv_checking(char *argv, t_map *map)
{
	if (argv)
	{
		if (argv[0] == '.')
		{
			write (2, "Error\n", 6);
			write (2, "Map must be a valid file", 24);
			return (1);
		}
		map->i = ft_strlen(argv);
		if (argv[map->i - 1])
		{
			map->i--;
			if (!ft_strnstr(argv, ".ber", ft_strlen(argv)))
			{
				write (2, "Error\n", 6);
				write(2, "Map must be a .ber file", 23);
				return (1);
			}
		}
	}
	return (0);
}

int	map_checking(char **file, t_map *map)
{
	map->i = 0;
	while ((int)map->i < map->size)
	{
		map->j = 0;
		if (file[map->i][0] != '1' || file[map->i][ft_strlen(file[map->i]) - 2] != '1')
		{
			write(2, "Error\n", 6);
			write(2, "Map must be surrounded by walls", 31);
			return (1);
		}
		while (map->j < ft_strlen(file[map->i]) - 1)
		{
			if (file[map->i][map->j] == 'E')
				map->nb_e++;
			else if (file[map->i][map->j] == 'P')
				map->nb_p++;
			else if (file[map->i][map->j] == 'C')
				map->nb_c++;
			map->j++;
		}
		map->i++;
	}
	if (map->nb_e != 1)
	{
		write (2, "Error\n", 6);
		write (2, "Map must only have one exit", 29);
		return (1);
	}
	if (map->nb_p != 1)
	{
		write (2, "Error\n", 6);
		write (2, "Map must only have one starting position", 40);
		return (1);
	}
	if (map->nb_c == 0)
	{
		write (2, "Error\n", 6);
		write (2, "Map must have at least one collectible", 38);
		return (1);
	}
	return (0);
}
