/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:11:27 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/30 20:52:17 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	**fill_map2(t_sl *sl, char *file)
{
	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		write(2, "\n", 1);
	}
	sl->m.size = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = NULL;
		line = get_next_line(fd);
		sl->m.size++;
	}
	close(fd);
	fill_map2_bis(sl, file);
	return (0);
}

void	**fill_map2_bis(t_sl *sl, char *file)
{
	int		fd;

	sl->m.cpy_map = malloc(sizeof(char *) * (sl->m.size + 1));
	if (!sl->m.cpy_map)
		return (NULL);
	fd = open(file, O_RDONLY);
	sl->m.cpy_map[0] = get_next_line(fd);
	sl->m.size = 0;
	while (sl->m.cpy_map[sl->m.size])
	{
		sl->m.size++;
		sl->m.cpy_map[sl->m.size] = get_next_line(fd);
	}
	//sl->m.cpy_map[sl->m.size + 1] = 0;
	close(fd);
	return (0);
}

int	stuck(t_sl *sl, int x, int y)
{
	if (sl->m.cpy_map[x - 1][y] == '1' && sl->m.cpy_map[x + 1][y] == '1'
	&& sl->m.cpy_map[x][y - 1] == '1' && sl->m.cpy_map[x][y + 1] == '1')
	{
		sl->m.cpy_map[x][y] = '1';
		return (1);
	}
	return (0);
}

int	not_stuck(t_sl *sl, int x, int y)
{
	if (sl->m.cpy_map[x][y] != '1')
	{
		if (sl->m.cpy_map[x][y] == 'E')
		{
			sl->m.nb_e--;
			sl->m.cpy_map[x][y] = '1';
		}	
		if (sl->m.cpy_map[x][y] == 'C')
		{
			sl->m.nb_c--;
			sl->m.cpy_map[x][y] = '1';
		}
		return (0);
	}
	return (1);
}

// print_tab(sl->m.cpy_map, sl);
int	check_move(t_sl *sl, int x, int y)
{
	sl->m.cpy_map[x][y] = '1';
	if (stuck(sl, x, y) == 1)
		return (1);
	if (not_stuck(sl, x, y - 1) == 0)
		check_move(sl, x, y - 1);
	if (not_stuck(sl, x - 1, y) == 0)
		check_move(sl, x - 1, y);
	if (not_stuck(sl, x, y + 1) == 0)
		check_move(sl, x, y + 1);
	if (not_stuck(sl, x + 1, y) == 0)
		check_move(sl, x + 1, y);
	return (0);
}

int	check_path(t_sl *sl)
{
	int	cpy_nb_c;

	cpy_nb_c = sl->m.nb_c;
	fill_map2(sl, sl->m.file);
	ft_find_player(&sl->m);
	check_move(sl, sl->m.i_p, sl->m.j_p);
	if (sl->m.nb_e > 0)
		ft_putstr_fd("Path is not valid : exit is not found\n", 2);
	if (sl->m.nb_c != 0)
		ft_putstr_fd("Path is not valid : item reachable\n", 2);
	sl->m.nb_c = cpy_nb_c;
	return (0);
}
