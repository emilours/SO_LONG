/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:21:17 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/15 20:30:17 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	key_press(int key, void *structure)
{
	(void)structure;
	if (key == KEY_ESC)
    //loop_end avant de destroy window
		exit (0);
	// if (KEY_W)
	// 	exit(0);
	// if (KEY_S)
	// 	exit(0);
	// if (KEY_A)
	// 	exit(0);
	// if (KEY_D)
	// 	exit(0);
	return (0);
}