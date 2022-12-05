/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:11:27 by eminatch          #+#    #+#             */
/*   Updated: 2022/12/02 21:29:41 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	fill_map2(t_s *s, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		write(2, "\n", 1);
	}
	s->m.size = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = NULL;
		line = get_next_line(fd);
		s->m.size++;
	}
	close(fd);
	if (fill_map2_bis(s, file) == 1)
		return (1);
	return (0);
}

int	fill_map2_bis(t_s *s, char *file)
{
	int		fd;

	s->m.cpy_map = malloc(sizeof(char *) * (s->m.size + 1));
	if (!s->m.cpy_map)
		return (1);
	fd = open(file, O_RDONLY);
	s->m.cpy_map[0] = get_next_line(fd);
	s->m.size = 0;
	while (s->m.cpy_map[s->m.size])
	{
		s->m.size++;
		s->m.cpy_map[s->m.size] = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	stuck(t_s *s, int x, int y)
{
	if (s->m.cpy_map[x - 1][y] == '1' && s->m.cpy_map[x + 1][y] == '1'
	&& s->m.cpy_map[x][y - 1] == '1' && s->m.cpy_map[x][y + 1] == '1')
	{
		s->m.cpy_map[x][y] = '1';
		return (1);
	}
	return (0);
}

int	not_stuck(t_s *s, int x, int y)
{
	if (s->m.cpy_map[x][y] == 'C')
	{
		s->m.nb_c--;
		s->m.cpy_map[x][y] = '1';
		return (0);
	}
	if (s->m.cpy_map[x][y] == '1' || s->m.cpy_map[x][y] == 'E')
	{
		if (s->m.cpy_map[x][y] == 'E')
			s->m.nb_e--;
		return (1);
	}
	return (0);
}

// print_tab(s->m.cpy_map, s);
int	check_move(t_s *s, int x, int y)
{
	s->m.cpy_map[x][y] = '1';
	if (stuck(s, x, y) == 1)
		return (1);
	if (not_stuck(s, x, y - 1) == 0)
		check_move(s, x, y - 1);
	if (not_stuck(s, x - 1, y) == 0)
		check_move(s, x - 1, y);
	if (not_stuck(s, x, y + 1) == 0)
		check_move(s, x, y + 1);
	if (not_stuck(s, x + 1, y) == 0)
		check_move(s, x + 1, y);
	return (0);
}
