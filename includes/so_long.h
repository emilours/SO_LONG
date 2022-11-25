/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:25:39 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/25 23:44:16 by eminatch         ###   ########.fr       */
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
# include <stdbool.h>

# define KEY_ESC		65307
# define KEY_W			119
# define KEY_A			97
# define KEY_S			115
# define KEY_D			100

typedef struct s_m
{
	int		nb_e;
	int		nb_p;
	int		nb_c;
	int		size;
	size_t	i;
	size_t	j;
	int		height;
	int		width;
	int		i_p;
	int		j_p;
	char	**map;
	char	**cpy_map;
	char	*file;
}				t_m;

typedef struct s_im
{
	void	*w;
	void	*e;
	void	*z;
	void	*p;
	void	*c;
}				t_im;

typedef struct s_player
{
	int		position;
	int		count_item;
	int		total_item;
}				t_player;

typedef struct s_g
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_g;

typedef struct s_sl
{
	t_m			m;
	t_im		im;
	t_player	ply;
	t_g			g;
}					t_sl;

/* main */
void	ft_init_solong(t_sl *sl);
int		main(int argc, char **argv);

/* graphic part */
void	fill_map(t_sl *sl, char *file);
void	fill_map_bis(t_sl *sl, char *file);
void	textures_to_window(t_sl *sl);
void	set_img(t_sl *sl);
void	img_to_win(t_sl *sl);
void	destroy_image(t_sl *sl);

/* player part */
int		press_key(int key, t_sl *sl);
void	action(t_sl *sl, int x, int y);
void	ft_find_player(t_m *m);

/* errors part*/
void	exit_game(t_sl *sl);
int		argv_checking(char *argv, t_sl *sl);
int		map_checking(t_sl *sl);
int		map_checking_bis(t_sl *sl);
char	**ft_free(char **str);

/* path_finding */
int		stuck(t_sl *sl, int x, int y);
int		not_stuck(t_sl *sl, int x, int y);
int		check_move(t_sl *sl, int x, int y);
int		check_path(t_sl *sl);
void	fill_map2(t_sl *sl, char *file);
void	fill_map2_bis(t_sl *sl, char *file);

#endif
