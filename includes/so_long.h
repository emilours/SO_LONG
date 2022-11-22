/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:25:39 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/22 20:46:27 by eminatch         ###   ########.fr       */
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

typedef struct s_map
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
}				t_map;

typedef struct s_img
{
	void	*wall;
	void	*exit;
	void	*empty;
	void	*pos;
	void	*item;
}				t_img;

typedef struct s_player
{
	char	position;
	int		count_item;
	int		total_item;
}				t_player;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_game;

typedef struct s_solong
{
	t_map		map;
	t_img		img;
	t_player	player;
	t_game		game;
}					t_solong;

/* init struct */
void	ft_init_solong(t_solong *solong);

/* graphic part */
int		map_checking(t_solong *solong);
void	fill_map(t_solong *solong, char *file);
void	textures_to_window(t_solong *solong);
void	set_image(t_solong *solong);
void	destroy_image(t_solong *solong);

/* player part */
int		main(int argc, char **argv);
int		press_key(int key, t_solong *solong);
void	move_player(t_solong *solong);
int		counting_item(t_solong *solong);
void	ft_find_player(t_solong *solong, char c);

/* errors part*/
void	exit_game(t_solong *solong);
int		argv_checking(char *argv, t_solong *solong);
char	**ft_free(char **str);

#endif
