/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:22:11 by eminatch          #+#    #+#             */
/*   Updated: 2022/12/01 20:39:52 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	press_key(int key, t_sl *sl)
{
	sl->m.i = 0;
	sl->m.j = 0;
	if (key == KEY_ESC)
	{
		mlx_loop_end(sl->g.mlx);
		return (1);
	}
	ft_find_player(&sl->m);
	if (key == KEY_W || key == KEY_UP)
		action(sl, sl->m.i - 1, sl->m.j);
	else if (key == KEY_D || key == KEY_R)
		action(sl, sl->m.i, sl->m.j + 1);
	else if (key == KEY_A || key == KEY_L)
		action(sl, sl->m.i, sl->m.j - 1);
	else if (key == KEY_S || key == KEY_DN)
		action(sl, sl->m.i + 1, sl->m.j);
	return (0);
}

void	action(t_sl *sl, int x, int y)
{
	if (sl->m.map[x][y] == 'E'
			&& sl->m.nb_c == 0)
	{
		sl->ply.p_moves++;
		sl->ply.str = ft_itoa(sl->ply.p_moves);
		ft_putstr_fd(sl->ply.str, STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
		free(sl->ply.str);
		mlx_loop_end(sl->g.mlx);
	}
	else if (sl->m.map[x][y] != '1'
			&& sl->m.map[x][y] != 'E')
	{
		if (sl->m.map[x][y] == 'C')
			sl->m.nb_c--;
		sl->m.map[x][y] = 'P';
		sl->m.map[sl->m.i][sl->m.j] = '0';
		sl->ply.p_moves++;
		update_img(sl);
	}
}

void	ft_find_player(t_m *m)
{
	m->i = 0;
	while ((int)m->i < m->size)
	{
		m->j = 0;
		while (m->j < ft_strlen(m->map[m->i]))
		{
			if (m->map[m->i][m->j] == 'P')
			{
				m->i_p = m->i;
				m->j_p = m->j;
				return ;
			}
			m->j++;
		}
		m->i++;
	}
}