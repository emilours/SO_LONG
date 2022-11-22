/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_the_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:19:23 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/22 20:47:49 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	press_key(int key, t_solong *solong)
{
	ft_find_player(solong, 'P');
	if (key == KEY_ESC)
		exit_game(solong);
	if (key == KEY_W)
	{
		solong->player.position = solong->map.mapping[solong->map.i][solong->map.j - 1];
		move_player(solong);
	}
	else if (key == KEY_S)
	{
		solong->player.position = solong->map.mapping[solong->map.i][solong->map.j + 1];
		move_player(solong);
	}
	else if (key == KEY_A)
	{
		solong->player.position = solong->map.mapping[solong->map.i - 1][solong->map.j];
		move_player(solong);
	}
	else if (key == KEY_D)
	{
		solong->player.position = solong->map.mapping[solong->map.i + 1][solong->map.j];
		move_player(solong);
	}
	return (0);
}

void	move_player(t_solong *solong)
{
	solong->player.total_item = counting_item(solong);
	while ((int)solong->map.i++ < solong->map.size)
	{
		if (solong->map.mapping[solong->map.i][solong->map.j] == 'P')
			exit_game(solong);
	}
	if (solong->map.mapping[solong->map.i][solong->map.j] == 'C')
		solong->player.count_item++;
	else if (solong->map.mapping[solong->map.i][solong->map.j] == 'E' && solong->player.count_item == solong->player.total_item)
		exit_game(solong);
	else if (solong->map.mapping[solong->map.i][solong->map.j] != '1' && solong->map.mapping[solong->map.i][solong->map.j] != 'E')
	{
		solong->map.mapping[solong->map.i][solong->map.j] = '0';
		set_image(solong);
	}
	solong->map.j++;
}

int	counting_item(t_solong *solong)
{
	if ((int)solong->map.i++ < solong->map.size)
	{
		if (solong->map.mapping[solong->map.i][solong->map.j] == 'C')
			solong->player.count_item++;
		solong->map.j++;
	}
	solong->map.i++;
	return (solong->player.count_item);
}

void	ft_find_player(t_solong *solong, char c)
{
	while (solong->map.mapping && solong->map.mapping[solong->map.i][solong->map.j] != '\0')
	{
		if (solong->map.mapping[solong->map.i][solong->map.j] == c)
			solong->player.position = solong->map.mapping[solong->map.i][solong->map.j];
		solong->map.i++;
		solong->map.j++;
	}
}
	// if (c == '\0')
	// 	return (&solong->map.mapping[(solong->map.size)]);
