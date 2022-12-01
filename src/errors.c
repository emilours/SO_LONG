/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:21:32 by eminatch          #+#    #+#             */
/*   Updated: 2022/12/01 19:18:08 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	exit_game(t_sl *sl)
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
	exit(EXIT_FAILURE);
	return (0);
}

int	argv_checking(char *argv, t_sl *sl)
{
	if (argv)
	{
		if (argv[0] == '.')
		{
			ft_error("Map must be a valid file");
			return (1);
		}
		sl->m.i = ft_strlen(argv);
		if (argv[sl->m.i - 1])
		{
			sl->m.i--;
			if (!ft_strnstr(argv, ".ber", ft_strlen(argv)))
			{
				ft_error("Map must be a .ber file");
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
			ft_error("Map must be surrounded by walls");
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
		if (sl->m.size < 3)
		{
			ft_error("At least three lines to be a valid map");
			return (1);
		}
	}
	if (map_checking_bis(sl) == 1)
		return (1);
	return (0);
}

int	map_checking_bis(t_sl *sl)
{
	if (sl->m.nb_e != 1)
	{
		ft_error("Map must have one exit");
		return (1);
	}
	if (sl->m.nb_p != 1)
	{
		ft_error("Map must only have one starting position");
		return (1);
	}
	if (sl->m.nb_c == 0)
	{
		ft_error("Map must have at least one collectible");
		return (1);
	}
	return (0);
}

int	map_is_rectangle(t_sl *sl)
{
	if (sl->m.size > 0)
	{
		if ((int)ft_strlen_sl(sl->m.map[sl->m.size])
			!= (int)ft_strlen_sl(sl->m.map[sl->m.size - 1]))
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

void	ft_error(char *err)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err, 2);
	ft_putstr_fd("\n ", 2);
}

size_t	ft_strlen_sl(char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len] != '\n' && s[len] != '\0')
		len++;
	return (len);
}