/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:25:39 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/21 18:38:36 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  SO_LONG_H
# define SO_LONG_H

# include "../Libs/LIBFT/includes/libft.h" 
# include "../Libs/minilibx-linux/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

typedef struct t_map
{
	int		nb_e;
	int		nb_p;
	int		nb_c;
	int		size;
	size_t	i;
	size_t	j;
	int		height;
	int		width;
	char	**mapping;
	void	*wall;
	void	*exit;
	void	*empty;
	void	*pos;
	void	*item;
}				t_map;

typedef struct t_player
{
	int		x;
	int		y;
	int		walks;
}				t_player;

typedef struct t_game
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_game;

int		main(int argc, char **argv);
void	fill_map(t_map *map, char *file);
int		map_checking(char **file, t_map *map);
int		press_key(int key);
void	ft_init_map(t_map *map);
void	ft_init_player(t_player *player);
void	ft_init_game(t_game *game);
void	textures_to_window(t_map *map);
int		argv_checking(char *argv, t_map *map);
void	exit_game(t_game *game);
void	move_player(char **line, t_player *player, t_map *map);
void	set_texture(t_game *game, t_map *map);

#endif
