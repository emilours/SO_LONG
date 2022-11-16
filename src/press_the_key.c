/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_the_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:19:23 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/16 20:14:26 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(int key, t_player *player)
{
	t_game	game;

	if (key == KEY_ESC)
		exit_game(&game); //loop end et exit normal dans le main
	if (key == KEY_W)
		player->y++;
	if (key == KEY_S)
		player->y--;
	if (key == KEY_A)
		player->x--;
	if (key == KEY_D)
		player->x++;
	return (0);
}
