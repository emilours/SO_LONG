/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:58:24 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/16 13:58:19 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;
	int		largeur;
	int		longueur;
	char	**map;

	largeur = 64;
	longueur = 28;
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, 600, 600, "my_first_window");
	game.img = mlx_xpm_file_to_image(game.mlx_ptr, "images/test.xpm", &largeur, &longueur);
	if (!game.img)
		return (0);
	mlx_put_image_to_window(game.mlx_ptr, game.win_ptr, game.img, largeur, longueur);
	mlx_hook(game.win_ptr, 2, 1L, key_press, NULL);
	mlx_loop(game.mlx_ptr);
	if (argc != 2)
	{
		write (2, "Error\n", 7);
		write (2, "Map issue", 9);
	}
	if (argv[1])
	{
		map = fill_map(argv[1]);
		if (map_checking(map, argv[1]) == 1)
			mlx_destroy_window(game.mlx_ptr, game.win_ptr);
	}
	mlx_loop_end(game.mlx_ptr);
	mlx_destroy_display(game.mlx_ptr);
	free(game.mlx_ptr);
	mlx_destroy_window(game.mlx_ptr, game.win_ptr);
	return (0);
}
	// dprintf(2, "key : %d\n", key);
	// int i = 0;
	// while (map[i])
	// {
	// 	printf(" line %d: %s\n", i, map[i]);
	// 	i++;
	// }