/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:58:24 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/16 20:15:38 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	t_map	map;
	int		largeur = 64;
	int		longueur = 64;

	ft_init_map(&map);
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
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, 600, 600, "my_first_window");
	game.img = mlx_xpm_file_to_image(game.mlx, "textures/test.xpm", &largeur, &longueur);
	if (!game.img)
		return (0);
	mlx_put_image_to_window(game.mlx, game.win, game.img, 64, 64);
	mlx_hook(game.win, 2, 1L, key_press, NULL);
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