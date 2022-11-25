/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:58:24 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/25 23:41:39 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_solong(t_sl *sl)
{
	sl->m.nb_e = 0;
	sl->m.nb_p = 0;
	sl->m.nb_c = 0;
	sl->m.size = 0;
	sl->m.i = 0;
	sl->m.j = 0;
	sl->m.height = 0;
	sl->m.width = 0;
	sl->m.i_p = 0;
	sl->m.j_p = 0;
	sl->m.map = NULL;
	sl->m.cpy_map = NULL;
	sl->im.w = NULL;
	sl->im.e = NULL;
	sl->im.z = NULL;
	sl->im.p = NULL;
	sl->im.c = NULL;
	sl->ply.count_item = 0;
	sl->ply.total_item = 0;
	sl->g.mlx = NULL;
	sl->g.img = NULL;
	sl->g.win = NULL;
}

int	main(int argc, char **argv)
{
	t_sl		sl;	
	int			o;
	int			p;

	ft_init_solong(&sl);
	if (argc != 2)
	{
		write (2, "Error\n", 7);
		write (2, "Mapping issue", 13);
	}
	if (argv[1])
	{
		sl.m.file = argv[1];
		fill_map(&sl, argv[1]);
		if (argv_checking(argv[1], &sl) == 1)
			exit (EXIT_FAILURE);
		if (map_checking(&sl) == 1)
			exit (EXIT_FAILURE);
		else if (check_path(&sl) != 0)
			exit(EXIT_FAILURE);
	}
	o = sl.m.size * 64;
	p = (ft_strlen(sl.m.map[0]) - 1) * 64;
	sl.g.mlx = mlx_init();
	sl.g.win = mlx_new_window(sl.g.mlx, p, o, "EAT SLEEP MEOW");
	set_img(&sl);
	mlx_hook(sl.g.win, 2, 1L, &press_key, &sl);
	mlx_loop(sl.g.mlx);
	exit_game(&sl);
	return (0);
}
