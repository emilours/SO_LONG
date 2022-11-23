/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:22:11 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/23 21:44:41 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	press_key(int key, t_solong *solong)
{
	solong->map.i = 0;
	solong->map.j = 0;
	if (key == KEY_ESC)
		mlx_loop_end(solong->game.mlx);
	ft_find_player(&solong->map);
	if (key == KEY_W)
		action(solong, solong->map.i - 1, solong->map.j);
	else if (key == KEY_D)
		action(solong, solong->map.i, solong->map.j + 1);
	else if (key == KEY_A)
		action(solong, solong->map.i, solong->map.j - 1);
	else if (key == KEY_S)
		action(solong, solong->map.i + 1, solong->map.j);
	set_image(solong);
	return (0);
}

void	action(t_solong *solong, int x, int y)
{
	if (solong->map.mapping[x][y] == 'E'
			&& solong->map.nb_c == 0)
		mlx_loop_end(solong->game.mlx);
	else if (solong->map.mapping[x][y] != '1'
			&& solong->map.mapping[x][y] != 'E')
	{
		if (solong->map.mapping[x][y] == 'C')
			solong->map.nb_c--;
		solong->map.mapping[x][y] = 'P';
		solong->map.mapping[solong->map.i][solong->map.j] = '0';
	}
}

void	ft_find_player(t_map *map)
{
	map->i = 0;
	while ((int)map->i < map->size)
	{
		map->j = 0;
		while (map->j < ft_strlen(map->mapping[map->i]))
		{
			if (map->mapping[map->i][map->j] == 'P')
				return ;
			map->j++;
		}
		map->i++;
	}
}
