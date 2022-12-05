/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphism.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:09:15 by eminatch          #+#    #+#             */
/*   Updated: 2022/12/05 21:07:31 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	set_img(t_s *s)
{
	int	w;
	int	h;

	s->im.w = mlx_xpm_file_to_image(s->g.mlx, "txr/w.xpm", &w, &h);
	s->im.e = mlx_xpm_file_to_image(s->g.mlx, "txr/e.xpm", &w, &h);
	s->im.z = mlx_xpm_file_to_image(s->g.mlx, "txr/z.xpm", &w, &h);
	s->im.p = mlx_xpm_file_to_image(s->g.mlx, "txr/p.xpm", &w, &h);
	s->im.c = mlx_xpm_file_to_image(s->g.mlx, "txr/c.xpm", &w, &h);
	s->m.i = 0;
	if (check_texture(s) == 1)
	{
		ft_error("texture file issue");
		exit_game(s);
	}
	while ((int)s->m.i < s->m.size)
	{
		s->m.j = 0;
		while (s->m.j < ft_strlen(s->m.map[s->m.i]))
			img_to_win(s);
		s->m.i++;
	}
	return (0);
}

int	img_to_win(t_s *s)
{
	if (s->m.map[s->m.i][s->m.j] == 'E')
		mlx_put_image_to_window (s->g.mlx, s->g.win, s->im.e, s->m.j * T,
			s->m.i * T);
	else if (s->m.map[s->m.i][s->m.j] == '1')
		mlx_put_image_to_window (s->g.mlx, s->g.win, s->im.w, s->m.j * T,
			s->m.i * T);
	else if (s->m.map[s->m.i][s->m.j] == '0')
		mlx_put_image_to_window (s->g.mlx, s->g.win, s->im.z, s->m.j * T,
			s->m.i * T);
	else if (s->m.map[s->m.i][s->m.j] == 'P')
		mlx_put_image_to_window (s->g.mlx, s->g.win, s->im.p, s->m.j * T,
			s->m.i * T);
	if (s->m.map[s->m.i][s->m.j] == 'C')
		mlx_put_image_to_window (s->g.mlx, s->g.win, s->im.c, s->m.j * T,
			s->m.i * T);
	s->m.j++;
	return (0);
}

void	update_img(t_s *s)
{
	s->m.i = 0;
	while ((int)s->m.i < s->m.size)
	{
		s->m.j = 0;
		while (s->m.j < ft_strlen(s->m.map[s->m.i]))
			img_to_win(s);
		s->m.i++;
	}
	s->ply.s = ft_itoa(s->ply.p_moves);
	ft_putstr_fd(s->ply.s, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	mlx_string_put(s->g.mlx, s->g.win, s->m.i, s->m.j, 0x0000FF00, s->ply.s);
	free(s->ply.s);
}

void	destroy_image(t_s *s)
{
	if (s->im.w != NULL)
		mlx_destroy_image(s->g.mlx, s->im.w);
	if (s->im.e != NULL)
		mlx_destroy_image(s->g.mlx, s->im.e);
	if (s->im.z != NULL)
		mlx_destroy_image(s->g.mlx, s->im.z);
	if (s->im.c != NULL)
		mlx_destroy_image(s->g.mlx, s->im.c);
	if (s->im.p != NULL)
		mlx_destroy_image(s->g.mlx, s->im.p);
}

int	check_texture(t_s *s)
{
	if (!s->im.w)
		return (1);
	if (!s->im.e)
		return (1);
	if (!s->im.z)
		return (1);
	if (!s->im.c)
		return (1);
	if (!s->im.p)
		return (1);
	return (0);
}
