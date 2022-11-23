/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:21:32 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/23 21:37:10 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_game(t_solong *solong)
{
	destroy_image(solong);
	ft_free(solong->map.mapping);
	mlx_destroy_window(solong->game.mlx, solong->game.win);
	mlx_destroy_display(solong->game.mlx);
	free(solong->game.mlx);
}

int	argv_checking(char *argv, t_solong *solong)
{
	if (argv)
	{
		if (argv[0] == '.')
		{
			write (2, "Error\n", 6);
			write (2, "Map must be a valid file", 24);
			return (1);
		}
		solong->map.i = ft_strlen(argv);
		if (argv[solong->map.i - 1])
		{
			solong->map.i--;
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

int	map_checking(t_solong *solong)
{
	solong->map.i = 0;
	while ((int)solong->map.i < solong->map.size)
	{
		solong->map.j = 0;
		if (solong->map.mapping[solong->map.i][0] != '1' || solong->map.mapping[solong->map.i][ft_strlen(solong->map.mapping[solong->map.i]) - 2] != '1')
		{
			write(2, "Error\n", 6);
			write(2, "Map must be surrounded by walls", 31);
			return (1);
		}
		while (solong->map.j < ft_strlen(solong->map.mapping[solong->map.i]) - 1)
		{
			if (solong->map.mapping[solong->map.i][solong->map.j] == 'E')
				solong->map.nb_e++;
			else if (solong->map.mapping[solong->map.i][solong->map.j] == 'P')
				solong->map.nb_p++;
			else if (solong->map.mapping[solong->map.i][solong->map.j] == 'C')
				solong->map.nb_c++;
			solong->map.j++;
		}
		solong->map.i++;
	}
	if (solong->map.nb_e != 1)
	{
		write (2, "Error\n", 6);
		write (2, "Map must only have one exit", 29);
		return (1);
	}
	if (solong->map.nb_p != 1)
	{
		write (2, "Error\n", 6);
		write (2, "Map must only have one starting position", 40);
		return (1);
	}
	if (solong->map.nb_c == 0)
	{
		write (2, "Error\n", 6);
		write (2, "Map must have at least one collectible", 38);
		return (1);
	}
	return (0);
}

char	**ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}
