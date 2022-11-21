/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:21:17 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/21 18:10:10 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_map(t_map *map)
{
	map->nb_e = 0;
	map->nb_p = 0;
	map->nb_c = 0;
	map->size = 0;
	map->i = 0;
	map->j = 0;
	map->height = 0;
	map->width = 0;
	map->mapping = NULL;
	map->wall = NULL;
	map->exit = NULL;
	map->empty = NULL;
	map->pos = NULL;
	map->item = NULL;
}

void	ft_init_player(t_player *player)
{
	player->x = 0;
	player->y = 0;
	player->walks = 0;
}

void	ft_init_game(t_game *game)
{
	game->mlx = NULL;
	game->win = NULL;
	game->img = NULL;
}
