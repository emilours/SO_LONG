/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:58:24 by eminatch          #+#    #+#             */
/*   Updated: 2022/12/05 21:50:09 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_init_solong(t_s *s)
{
	s->m.nb_e = 0;
	s->m.nb_p = 0;
	s->m.nb_c = 0;
	s->m.size = 0;
	s->m.i = 0;
	s->m.j = 0;
	s->m.height = 0;
	s->m.width = 0;
	s->m.i_p = 0;
	s->m.j_p = 0;
	s->m.map = NULL;
	s->m.cpy_map = NULL;
	s->im.w = NULL;
	s->im.e = NULL;
	s->im.z = NULL;
	s->im.p = NULL;
	s->im.c = NULL;
	s->ply.count_item = 0;
	s->ply.total_item = 0;
	s->ply.p_moves = 0;
	s->ply.s = NULL;
	s->g.mlx = NULL;
	s->g.img = NULL;
	s->g.win = NULL;
}

int	main(int argc, char **argv)
{
	t_s		s;	
	int		o;
	int		p;

	ft_init_solong(&s);
	if (argc != 2)
		return (write (2, "Error\nargc issue\n", 17), 1);
	check_condition(&s, argv);
	o = s.m.size * T;
	p = (ft_strlen(s.m.map[0]) - 1) * T;
	s.g.mlx = mlx_init();
	if (!s.g.mlx)
	{
		ft_error("mlx issue");
		exit_game(&s);
	}
	s.g.win = mlx_new_window(s.g.mlx, p, o, "SO_LONG");
	mlx_win_issue(&s);
	set_img(&s);
	mlx_hook(s.g.win, 2, 1L << 0, press_key, &s);
	mlx_hook(s.g.win, 17, 1L << 17, exit_game, &s);
	mlx_loop(s.g.mlx);
	exit_game(&s);
	return (0);
}
