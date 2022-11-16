/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:22:02 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/16 14:10:09 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**fill_map(char *file, t_map *map)
{
	int		fd;
	char	**mapping;
	char	*line;

	fd = open(file, O_RDONLY);
	map->size = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = NULL;
		map->size++;
		line = get_next_line(fd);
	}
	close(fd);
	mapping = malloc(sizeof(char *) * map->size + 1);
	fd = open(file, O_RDONLY); // error gestion
	mapping[0] = get_next_line(fd);
	map->size = 0;
	while (mapping[map->size])
	{
		map->size++;
		mapping[map->size] = get_next_line(fd);
	}
	mapping[map->size + 1] = 0;
	return (mapping);
}

int	map_checking(char **file, char *argv, t_map *map)
{
	if (argv[map->i])
	{
		if (argv[0] == '.')
		{
			write (2, "Error\n", 6);
			write (2, "Map must be a valid file", 24);
			return (1);
		}
		map->i = ft_strlen(argv);
		if (argv[map->i - 1])
		{
			map->i--;
			if (!ft_strnstr(argv, ".ber", ft_strlen(argv)))
			{
				write (2, "Error\n", 6);
				write(2, "Map must be a .ber file", 23);
				return (1);
			}
		}
	}
	map->i = 0;
	map->j = 0;
	while (map->i <= ft_strlen(&file[map->i][map->j]))
	{
		while (map->j <= ft_strlen(&file[map->i][map->j]))
		{
			if (file[map->i][map->j] != '1' || file[map->i - 1][map->j - 1] != '1')
			{	
				write (2, "Error\n", 6);
				write (2, "Map must be surrounded by walls", 31); //souci
				return (1);
			}
			else if (file[map->i++][map->j++] == 'E')
				map->nb_e++;
			else if (file[map->i++][map->j++] == 'P')
				map->nb_p++;
			else if (file[map->i++][map->j++] == 'C')
				map->nb_c++;
			map->j++;
		}
		map->i++;
	}
	if (map->nb_e != 1)
	{
		write (2, "Error\n", 6);
		write (2, "Map must only have one exit", 31);
		return (1);
	}
	if (map->nb_p != 1)
	{
		write (2, "Error\n", 6);
		write (2, "Map must have one starting position", 35);
		return (1);
	}
	if (map->nb_c == 0)
	{
		write (2, "Error\n", 6);
		write (2, "Map must have at least one collectible", 38);
		return (1);
	}
	return (0);
}

//faire boucle while dans boucle while pour incrementer la map avec deux indices
// erreur map rectangulaire
// erreir .ber : fichier cache / .ber.ber : ok ?
//erreur : recep tous les C avant de E
// loop end avant de destroy pour eviter leaks
// telecharger sprites