/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:25:39 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/16 14:15:37 by eminatch         ###   ########.fr       */
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
}				t_map;

typedef struct t_player
{
	int		x;
	int		y;
}				t_player;

typedef struct t_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
}				t_game;

int		main(int argc, char **argv);
char	**fill_map(char *file, t_map *map);
int		map_checking(char **file, char *argv, t_map *map);
int		key_press(int key, t_player *player);
void	ft_init_map(t_map *map);
void	ft_init_player(t_player *player);
void	ft_init_game(t_game *game);

#endif
