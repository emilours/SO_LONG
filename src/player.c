/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:22:11 by eminatch          #+#    #+#             */
/*   Updated: 2022/12/02 19:12:02 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	press_key(int key, t_s *s)
{
	s->m.i = 0;
	s->m.j = 0;
	if (key == KEY_ESC)
	{
		mlx_loop_end(s->g.mlx);
		return (1);
	}
	ft_find_player(&s->m);
	if (key == KEY_W || key == KEY_UP)
		action(s, s->m.i - 1, s->m.j);
	else if (key == KEY_D || key == KEY_R)
		action(s, s->m.i, s->m.j + 1);
	else if (key == KEY_A || key == KEY_L)
		action(s, s->m.i, s->m.j - 1);
	else if (key == KEY_S || key == KEY_DN)
		action(s, s->m.i + 1, s->m.j);
	return (0);
}

void	action(t_s *s, int x, int y)
{
	if (s->m.map[x][y] == 'E'
			&& s->m.nb_c == 0)
	{
		s->ply.p_moves++;
		s->ply.s = ft_itoa(s->ply.p_moves);
		ft_putstr_fd(s->ply.s, STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
		free(s->ply.s);
		mlx_loop_end(s->g.mlx);
	}
	else if (s->m.map[x][y] != '1'
			&& s->m.map[x][y] != 'E')
	{
		if (s->m.map[x][y] == 'C')
			s->m.nb_c--;
		s->m.map[x][y] = 'P';
		s->m.map[s->m.i][s->m.j] = '0';
		s->ply.p_moves++;
		update_img(s);
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

size_t	ft_strlen_sl(char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len] != '\n' && s[len] != '\0')
		len++;
	return (len);
}
