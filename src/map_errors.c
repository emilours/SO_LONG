/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:21:32 by eminatch          #+#    #+#             */
/*   Updated: 2022/12/05 22:03:23 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	argv_checking(char *argv, t_s *s)
{
	if (argv)
	{
		if (argv[0] == '.')
		{
			ft_error("Map must be a valid file");
			return (1);
		}
		s->m.i = ft_strlen(argv);
		if (argv[s->m.i - 1])
		{
			s->m.i--;
			if (!ft_strnstr(argv, ".ber", ft_strlen(argv)))
			{
				ft_error("Map must be a .ber file");
				return (1);
			}
		}
	}
	return (0);
}

int	map_checking(t_s *s)
{
	s->m.i = 0;
	if (s->m.size < 3)
		return (ft_error("At least three lines to be a valid map"), 1);
	if (check_walls(s->m.map[0]) == 1
		|| check_walls(s->m.map[s->m.size - 1]) == 1)
		return (ft_error("Map must be surrounded by walls"), 1);
	while ((int)s->m.i < s->m.size - 1)
	{
		s->m.j = 0;
		if (s->m.map[s->m.i][0] != '1'
			|| s->m.map[s->m.i][ft_strlen(s->m.map[s->m.i]) - 2] != '1')
		{
			ft_error("Map must be surrounded by walls");
			return (1);
		}
		if (map_checking_bis(s) == 1)
			return (1);
		s->m.i++;
	}
	if (map_checking_conditions(s) == 1)
		return (1);
	return (0);
}

int	check_walls(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			i++;
		else
			break ;
	}
	if (str[i] == '\n' || str[i] == '\0')
		return (0);
	return (1);
}

int	map_checking_bis(t_s *s)
{
	while (s->m.j < ft_strlen(s->m.map[s->m.i]) - 1)
	{
		if (s->m.map[s->m.i][s->m.j] != '1'
		&& s->m.map[s->m.i][s->m.j] != '0'
		&& s->m.map[s->m.i][s->m.j] != 'E'
		&& s->m.map[s->m.i][s->m.j] != 'C'
		&& s->m.map[s->m.i][s->m.j] != 'P'
		&& s->m.map[s->m.i][s->m.j] != '\n')
		{
			ft_error("map with unauthorized char");
			return (1);
		}
		else if (s->m.map[s->m.i][s->m.j] == 'E')
			s->m.nb_e++;
		else if (s->m.map[s->m.i][s->m.j] == 'P')
			s->m.nb_p++;
		else if (s->m.map[s->m.i][s->m.j] == 'C')
			s->m.nb_c++;
		s->m.j++;
	}
	return (0);
}

int	map_checking_conditions(t_s *s)
{
	if (s->m.nb_e != 1)
	{
		ft_error("Map must have one exit");
		return (1);
	}
	if (s->m.nb_p != 1)
	{
		ft_error("Map must only have one starting position");
		return (1);
	}
	if (s->m.nb_c == 0)
	{
		ft_error("Map must have at least one collectible");
		return (1);
	}
	return (0);
}
