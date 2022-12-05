/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:25:39 by eminatch          #+#    #+#             */
/*   Updated: 2022/12/05 21:59:58 by eminatch         ###   ########.fr       */
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
# define KEY_UP			65362
# define KEY_DN			65364
# define KEY_R			65363
# define KEY_L			65361

# define T				64

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
	int		p_moves;
	char	*s;
}				t_player;

typedef struct s_g
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_g;

typedef struct s_s
{
	t_m			m;
	t_im		im;
	t_player	ply;
	t_g			g;
}					t_s;

/* main */
void	ft_init_solong(t_s *s);
int		main(int argc, char **argv);
void	check_condition(t_s *s, char **argv);
void	mlx_win_issue(t_s *s);

/* graphic part */
int		fill_map(t_s *s, char *file);
int		fill_map_bis(t_s *s, char *file);
void	textures_to_window(t_s *s);
int		set_img(t_s *s);
int		img_to_win(t_s *s);
void	destroy_image(t_s *s);
void	update_img(t_s *s);
int		check_texture(t_s *s);

/* player part */
int		press_key(int key, t_s *s);
void	action(t_s *s, int x, int y);
void	ft_find_player(t_m *m);
size_t	ft_strlen_sl(char *s);

/* errors_map */
int		argv_checking(char *argv, t_s *s);
int		map_checking(t_s *s);
int		map_checking_bis(t_s *s);
int		map_checking_conditions(t_s *s);
int		map_is_rectangle(t_s *s);
int		check_walls(char *str);
int		hidden_file(char *argv);

/* errors */
int		exit_game(t_s *s);
void	ft_free(char **str);
void	ft_error(char *s1);
int		check_path(t_s *s);
int		open_process(char *file);

/* path_finding */
int		stuck(t_s *s, int x, int y);
int		not_stuck(t_s *s, int x, int y);
int		check_move(t_s *s, int x, int y);
int		fill_map2(t_s *s, char *file);
int		fill_map2_bis(t_s *s, char *file);
int		print_tab(char **tab, t_s *s);
int		**copy_map(t_s *s, char *str);

#endif