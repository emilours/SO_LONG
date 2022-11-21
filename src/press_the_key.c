/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_the_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:19:23 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/21 18:18:22 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	press_key(int key)
{
	t_game	game;

	if (key == KEY_ESC)
		exit_game(&game);
	// if (key == KEY_W)
	// 	player->y++;
	// if (key == KEY_S)
	// 	player->y--;
	// if (key == KEY_A)
	// 	player->x--;
	// if (key == KEY_D)
		// player->x++;
	return (0);
}

// void	move_player(char **line, t_player *player, t_map *map)
// {
// 	t_game	game;

// 	while (map->i++ < ft_strlen(line))
// 	{
// 		if (line[map->i][map->j] == 'P')
// 			exit_game(&game);
// 	}
// 	if (line[map->i][map->j] == 'C')
// 		set_texture
// 		player->walks++;				
// }