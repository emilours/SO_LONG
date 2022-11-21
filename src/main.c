/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:58:24 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/21 20:20:09 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game		game;
	t_map		map;
	t_player	player;
	int	o;
	int	p;

	ft_init_map(&map);
	ft_init_player(&player);
	ft_init_game(&game);
	if (argc != 2)
	{
		write (2, "Error\n", 7);
		write (2, "Mapping issue", 13);
	}
	if (argv[1])
	{
		fill_map(&map, argv[1]);
		if (map_checking(map.mapping, &map) == 1)
			exit (EXIT_FAILURE);
		else if (argv_checking(argv[1], &map) == 1)
			exit (EXIT_FAILURE);
	}
	o = map.size * 64;
	p = (ft_strlen(map.mapping[0]) - 1) * 64;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, p, o, "Cat's hunting");
	set_texture(&game, &map);
	mlx_hook(game.win, 2, 1L, press_key, NULL);
	mlx_loop(game.mlx);
	exit_game(&game);
	return (0);
}
	// dprintf(2, "key : %d\n", key);
	// int i = 0;
	// while (map.mapping[i])
	// {
	// 	printf(" line %d: %s\n", i, map[i]);
	// 	i++;
	// }