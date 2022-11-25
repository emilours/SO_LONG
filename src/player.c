/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:22:11 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/25 23:54:02 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	press_key(int key, t_sl *sl)
{
	sl->m.i = 0;
	sl->m.j = 0;
	if (key == KEY_ESC)
		mlx_loop_end(sl->g.mlx);
	ft_find_player(&sl->m);
	if (key == KEY_W)
		action(sl, sl->m.i - 1, sl->m.j);
	else if (key == KEY_D)
		action(sl, sl->m.i, sl->m.j + 1);
	else if (key == KEY_A)
		action(sl, sl->m.i, sl->m.j - 1);
	else if (key == KEY_S)
		action(sl, sl->m.i + 1, sl->m.j);
	set_img(sl);
	return (0);
}

void	action(t_sl *sl, int x, int y)
{
	if (sl->m.map[x][y] == 'E'
			&& sl->m.nb_c == 0)
		mlx_loop_end(sl->g.mlx);
	else if (sl->m.map[x][y] != '1'
			&& sl->m.map[x][y] != 'E')
	{
		if (sl->m.map[x][y] == 'C')
			sl->m.nb_c--;
		sl->m.map[x][y] = 'P';
		sl->m.map[sl->m.i][sl->m.j] = '0';
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
			printf("%d\n == j", (int)m->j);
			if (m->map[m->i][m->j] == 'P')
			{
				m->i_p = m->i;
				m->j_p = m->j;
				printf("\n%d == ip", m->i_p);
				return ;
			}
			m->j++;
		}
		m->i++;
	}
}
