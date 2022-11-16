/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:22:02 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/16 20:22:43 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	fill_map(t_map *map, char *file)
{
	int		fd;
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
	map->mapping = malloc(sizeof(char *) * map->size + 1);
	fd = open(file, O_RDONLY);
	map->mapping[0] = get_next_line(fd);
	map->size = 0;
	while (map->mapping[map->size])
	{
		map->size++;
		map->mapping[map->size] = get_next_line(fd);
	}
	map->mapping[map->size + 1] = 0;
}

// void	textures_to_window(t_map *map)
// {
// }

// erreur map rectangulaire
// checker si les 1 au milieu voir papier
// erreir .ber : fichier cache / .ber.ber : ok ?
//erreur : recep tous les C avant de E
// loop end avant de destroy pour eviter leaks
// telecharger sprites