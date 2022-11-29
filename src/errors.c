/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:21:32 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/29 21:25:52 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_game(t_sl *sl)
{
	if (sl->g.mlx)
	{
		if (sl->g.win)
		{
			destroy_image(sl);
			mlx_destroy_window(sl->g.mlx, sl->g.win);
			mlx_destroy_display(sl->g.mlx);
		}
		free(sl->g.mlx);
	}
	if (sl->m.map)
		ft_free(sl->m.map);
	if (sl->m.cpy_map)
		ft_free(sl->m.cpy_map);
	exit(0);
}

int	argv_checking(char *argv, t_sl *sl)
{
	if (argv)
	{
		if (argv[0] == '.')
		{
			write (2, "Error\n", 6);
			write (2, "Map must be a valid file", 24);
			return (1);
		}
		sl->m.i = ft_strlen(argv);
		if (argv[sl->m.i - 1])
		{
			sl->m.i--;
			if (!ft_strnstr(argv, ".ber", ft_strlen(argv)))
			{
				write (2, "Error\n", 6);
				write(2, "Map must be a .ber file", 23);
				return (1);
			}
		}
	}
	return (0);
}

int	map_checking(t_sl *sl)
{
	sl->m.i = 0;
	while ((int)sl->m.i < sl->m.size)
	{
		sl->m.j = 0;
		if (sl->m.map[sl->m.i][0] != '1'
			|| sl->m.map[sl->m.i][ft_strlen(sl->m.map[sl->m.i]) - 2] != '1')
		{
			write(2, "Error\n", 6);
			write(2, "Map must be surrounded by walls", 31);
			return (1);
		}
		while (sl->m.j < ft_strlen(sl->m.map[sl->m.i]) - 1)
		{
			if (sl->m.map[sl->m.i][sl->m.j] == 'E')
				sl->m.nb_e++;
			else if (sl->m.map[sl->m.i][sl->m.j] == 'P')
				sl->m.nb_p++;
			else if (sl->m.map[sl->m.i][sl->m.j] == 'C')
				sl->m.nb_c++;
			sl->m.j++;
		}
		sl->m.i++;
	}
	map_checking_bis(sl);
	return (0);
}

int	map_checking_bis(t_sl *sl)
{
	if (sl->m.nb_e != 1)
	{
		write (2, "Error\n", 6);
		write (2, "Map must only have one exit", 29);
		return (1);
	}
	if (sl->m.nb_p != 1)
	{
		write (2, "Error\n", 6);
		write (2, "Map must only have one starting position", 40);
		return (1);
	}
	if (sl->m.nb_c == 0)
	{
		write (2, "Error\n", 6);
		write (2, "Map must have at least one collectible", 38);
		return (1);
	}
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
