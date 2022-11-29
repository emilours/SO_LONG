/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:22:02 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/29 21:27:21 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	fill_map(t_sl *sl, char *file)
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
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		sl->m.size++;
	}
	if (sl->m.size < 3)
	{
		ft_putstr_fd ("Error\nAt least 3lines for a valid map\n", 2);
		return (1);
	}
	close(fd);
	fill_map_bis(sl, file);
	return (0);
}

void	fill_map_bis(t_sl *sl, char *file)
{
	int		fd;

	sl->m.map = malloc(sizeof(char *) * (sl->m.size + 1));
	if (!sl->m.map)
		return ;
	fd = open(file, O_RDONLY);
	// sl->m.map[0] = get_next_line(fd);
	sl->m.size = 0;
	while (1)
	{
		sl->m.map[sl->m.size] = get_next_line(fd);
		if (!sl->m.map[sl->m.size])
			break ;
		sl->m.size++;
	}
	// while (sl->m.map[sl->m.size])
	// {
	// 	sl->m.size++;
	// 	sl->m.map[sl->m.size] = get_next_line(fd);
	// }
	close(fd);
}
void	set_img(t_sl *sl)
{
	int	w;
	int	h;

	sl->im.w = mlx_xpm_file_to_image(sl->g.mlx, "txr/w.xpm", &w, &h);
	sl->im.e = mlx_xpm_file_to_image(sl->g.mlx, "txr/e.xpm", &w, &h);
	sl->im.z = mlx_xpm_file_to_image(sl->g.mlx, "txr/z.xpm", &w, &h);
	sl->im.p = mlx_xpm_file_to_image(sl->g.mlx, "txr/p.xpm", &w, &h);
	sl->im.c = mlx_xpm_file_to_image(sl->g.mlx, "txr/c.xpm", &w, &h);
	sl->m.i = 0;
	while ((int)sl->m.i < sl->m.size)
	{
		sl->m.j = 0;
		while (sl->m.j < ft_strlen(sl->m.map[sl->m.i]))
			img_to_win(sl);
		sl->m.i++;
	}
}

void	img_to_win(t_sl *sl)
{
	if (sl->m.map[sl->m.i][sl->m.j] == 'E')
		mlx_put_image_to_window (sl->g.mlx, sl->g.win, sl->im.e, sl->m.j * 64, sl->m.i * 64);
	else if (sl->m.map[sl->m.i][sl->m.j] == '1')
		mlx_put_image_to_window (sl->g.mlx, sl->g.win, sl->im.w, sl->m.j * 64, sl->m.i * 64);
	else if (sl->m.map[sl->m.i][sl->m.j] == '0')
		mlx_put_image_to_window (sl->g.mlx, sl->g.win, sl->im.z, sl->m.j * 64, sl->m.i * 64);
	else if (sl->m.map[sl->m.i][sl->m.j] == 'P')
		mlx_put_image_to_window (sl->g.mlx, sl->g.win, sl->im.p, sl->m.j * 64, sl->m.i * 64);
	else if (sl->m.map[sl->m.i][sl->m.j] == 'C')
		mlx_put_image_to_window (sl->g.mlx, sl->g.win, sl->im.c, sl->m.j * 64, sl->m.i * 64);
	sl->m.j++;
}

void	update_img(t_sl *sl)
{
	while ((int)sl->m.i < sl->m.size)
	{
		sl->m.j = 0;
		while (sl->m.j < ft_strlen(sl->m.map[sl->m.i]))
			img_to_win(sl);
		sl->m.i++;
	}
}

void	destroy_image(t_sl *sl)
{
	if (sl->im.w != NULL)
		mlx_destroy_image(sl->g.mlx, sl->im.w);
	if (sl->im.e != NULL)
		mlx_destroy_image(sl->g.mlx, sl->im.e);
	if (sl->im.z != NULL)
		mlx_destroy_image(sl->g.mlx, sl->im.z);
	if (sl->im.c != NULL)
		mlx_destroy_image(sl->g.mlx, sl->im.c);
	if (sl->im.p != NULL)
		mlx_destroy_image(sl->g.mlx, sl->im.p);
}
