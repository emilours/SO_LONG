/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:58:24 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/15 20:28:06 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int		largeur;
	int		longueur;

	largeur = 64;
	longueur = 28;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 600, 600, "my_first_window");
	img = mlx_xpm_file_to_image(mlx_ptr, "images/test.xpm", &largeur, &longueur);
	if (!img)
		return (0);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img, largeur, longueur);
	mlx_hook(win_ptr, 2, 1L, key_press, NULL);
	mlx_loop(mlx_ptr);
	if (argc != 2)
	{
		write (2, "Error\n", 7);
		write (2, "Map issue", 9);
	}
	if (argv[1])
	{
		char **map = fill_map(argv[1]);
		if (map_checking(map, argv[1]) == 1)
			mlx_destroy_window(mlx_ptr, win_ptr);
	return (0);
	}
	// int i = 0;
	// while (map[i])
	// {
	// 	printf(" line %d: %s\n", i, map[i]);
	// 	i++;
	// }
}
	// mlx_destroy_display(mlx_ptr);
	// free(mlx_ptr);
	// mlx_destroy_window(mlx_ptr, win_ptr);
	// dprintf(2, "key : %d\n", key);