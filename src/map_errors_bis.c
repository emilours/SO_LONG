/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:49:00 by eminatch          #+#    #+#             */
/*   Updated: 2022/12/05 22:02:02 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_condition(t_s *s, char **argv)
{
	s->m.file = argv[1];
	if (argv_checking(argv[1], s) == 1)
		exit_game(s);
	if (hidden_file(argv[1]) == 1)
		exit_game(s);
	if (fill_map(s, argv[1]) == 1)
		exit_game(s);
	if (map_checking(s) == 1)
		exit_game(s);
	else
	{
		if (check_path(s) == 1)
			exit_game(s);
	}
}

void	mlx_win_issue(t_s *s)
{
	if (!s->g.win)
	{
		ft_error("win issue");
		exit_game(s);
	}
}

int	hidden_file(char *argv)
{
	char	*ptr;

	ptr = ft_strrchr(argv, '.');
	if (ptr == NULL || ft_strncmp(ptr, ".ber", 5) != 0 || *ptr == *argv)
		return (1);
	return (0);
}

int	open_process(char *file)
{
	int	fd;

	fd = open(file, __O_DIRECTORY);
	if (fd > 0)
	{
		ft_error("Map can't be a directory");
		close (fd);
		exit(EXIT_FAILURE);
	}
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr_fd(strerror(errno), 2);
		write(2, "\n", 1);
		exit(EXIT_FAILURE);
	}
	return (fd);
}
