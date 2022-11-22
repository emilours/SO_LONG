/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:58:24 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/22 19:24:01 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_solong	solong;	
	int			o;
	int			p;

	ft_init_solong(&solong);
	if (argc != 2)
	{
		write (2, "Error\n", 7);
		write (2, "Mapping issue", 13);
	}
	if (argv[1])
	{
		fill_map(&solong, argv[1]);
		if (map_checking(&solong) == 1)
			exit (EXIT_FAILURE);
		else if (argv_checking(argv[1], &solong) == 1)
			exit (EXIT_FAILURE);
	}
	o = solong.map.size * 64;
	p = (ft_strlen(solong.map.mapping[0]) - 1) * 64;
	solong.game.mlx = mlx_init();
	solong.game.win = mlx_new_window(solong.game.mlx, p, o, "EAT SLEEP MEOW");
	set_image(&solong);
	mlx_hook(solong.game.win, 2, 1L, &press_key, &solong);
	mlx_loop(solong.game.mlx);
	exit_game(&solong);
	return (0);
}
	// dprintf(2, "key : %d\n", key);
	// int i = 0;
	// while (map.mapping[i])
	// {
	// 	printf(" line %d: %s\n", i, map[i]);
	// 	i++;
	// }