/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:01:01 by eminatch          #+#    #+#             */
/*   Updated: 2022/12/05 19:39:32 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_game(t_s *s)
{
	if (s->g.mlx)
	{
		if (s->g.win)
		{
			destroy_image(s);
			mlx_destroy_window(s->g.mlx, s->g.win);
			mlx_destroy_display(s->g.mlx);
		}
		free(s->g.mlx);
	}
	if (s->m.map)
		ft_free(s->m.map);
	if (s->m.cpy_map)
		ft_free(s->m.cpy_map);
	exit(EXIT_FAILURE);
	return (0);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	ft_error(char *err)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err, 2);
	ft_putstr_fd("\n", 2);
}

int	print_tab(char **tab, t_s *s)
{
	int	a;

	a = 0;
	while (a <= (int)s->m.size)
	{
		ft_putstr_fd(tab[a], 1);
		a++;
	}
	write(1, "\n\n", 2);
	return (0);
}

int	check_path(t_s *s)
{
	int	cpy_nb_c;

	cpy_nb_c = s->m.nb_c;
	if (fill_map2(s, s->m.file) == 1)
		return (1);
	ft_find_player(&s->m);
	check_move(s, s->m.i_p, s->m.j_p);
	if (s->m.nb_e > 0)
	{
		ft_error("Path is not valid : exit is not found");
		return (1);
	}
	if (s->m.nb_c != 0)
	{
		ft_error("Path is not valid : item reachable");
		return (1);
	}
	s->m.nb_c = cpy_nb_c;
	return (0);
}
