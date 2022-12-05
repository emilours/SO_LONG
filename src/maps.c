/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:22:02 by eminatch          #+#    #+#             */
/*   Updated: 2022/12/05 21:54:33 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	fill_map(t_s *s, char *file)
{
	char	*line;
	int		fd;

	fd = open_process(file);
	s->m.size = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		s->m.size++;
	}
	if (s->m.size == 0)
		return (ft_putstr_fd("Error\nMap empty\n", 2), 1);
	close(fd);
	if (fill_map_bis(s, file) == 1)
		return (1);
	return (0);
}

int	fill_map_bis(t_s *s, char *file)
{
	int		fd;
	int		line_size;

	s->m.map = malloc(sizeof(char *) * (s->m.size + 1));
	if (!s->m.map)
		return (1);
	fd = open(file, O_RDONLY);
	s->m.size = 0;
	line_size = 0;
	while (1)
	{
		s->m.map[s->m.size] = get_next_line(fd);
		if (!s->m.map[s->m.size])
			break ;
		if (map_is_rectangle(s) == 1)
			line_size++;
		s->m.size++;
	}
	close(fd);
	if (line_size > 0)
	{
		ft_error("Map must be a rectangle");
		return (1);
	}
	return (0);
}

int	map_is_rectangle(t_s *s)
{
	if (s->m.size > 0)
	{
		if ((int)ft_strlen_sl(s->m.map[s->m.size])
			!= (int)ft_strlen_sl(s->m.map[s->m.size - 1]))
			return (1);
	}
	return (0);
}
