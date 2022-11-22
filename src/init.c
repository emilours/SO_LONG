/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:21:17 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/22 20:42:02 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_solong(t_solong *solong)
{
	solong->map.nb_e = 0;
	solong->map.nb_p = 0;
	solong->map.nb_c = 0;
	solong->map.size = 0;
	solong->map.i = 0;
	solong->map.j = 0;
	solong->map.height = 0;
	solong->map.width = 0;
	solong->map.mapping = NULL;
	solong->img.wall = NULL;
	solong->img.exit = NULL;
	solong->img.empty = NULL;
	solong->img.pos = NULL;
	solong->img.item = NULL;
	solong->player.count_item = 0;
	solong->player.total_item = 0;
	solong->game.mlx = NULL;
	solong->game.img = NULL;
	solong->game.win = NULL;
}
