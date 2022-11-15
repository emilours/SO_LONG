/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:22:02 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/15 20:55:14 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**fill_map(char *file)
{
	int		fd;
	int		size;
	char	**map;
	char	*line;

	fd = open(file, O_RDONLY);
	size = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = NULL;
		size++;
		line = get_next_line(fd);
	}
	close(fd);
	map = malloc(sizeof(char *) * size + 1);
	fd = open(file, O_RDONLY); // error gestion
	map[0] = get_next_line(fd);
	size = 0;
	while (map[size])
	{
		size++;
		map[size] = get_next_line(fd);
	}
	map[size + 1] = 0;
	return (map);
}

int	map_checking(char **file, char *argv)
{
	size_t	i;
	size_t	j;
	int		nb_e;
	int		nb_p;
	int		nb_c;

	i = 0;
	nb_e = 0;
	nb_p = 0;
	nb_c = 0;
	if (argv[i])
	{
		if (argv[0] == '.')
		{
			write (2, "Error\n", 6);
			write (2, "Map must be a valid file", 24);
			return (1);
		}
		i = ft_strlen(argv);
		if (argv[i - 1])
		{
			i--;
			if (!ft_strnstr(argv, ".ber", ft_strlen(argv)))
			{
				write (2, "Error\n", 6);
				write(2, "Map must be a .ber file", 23);
				return (1);
			}
		}
	}
	j = 0;
	while (j++ <= ft_strlen(&file[0][j]))
	{
		i = 0;
		while (i++ <= ft_strlen(&file[i][j]))
		{
			if (file[i][j] != '1')
			{	
				write (2, "Error\n", 6);
				write (2, "Map must be surrounded by walls", 31); //souci
				return (1);
			}
			else if (file[i][j] == 'E')
				nb_e++;
			else if (file[i][j] == 'P')
				nb_p++;
			else if (file[i][j] == 'C')
				nb_c++;
		}
	}
	if (nb_e != 1)
	{
		write (2, "Error\n", 6);
		write (2, "Map must only have one exit", 31);
		return (1);
	}
	if (nb_p != 1)
	{
		write (2, "Error\n", 6);
		write (2, "Map must have one starting position", 35);
		return (1);
	}
	if (nb_c == 0)
	{
		write (2, "Error\n", 6);
		write (2, "Map must have at least one collectible", 38);
		return (1);
	}
	return (0);
}