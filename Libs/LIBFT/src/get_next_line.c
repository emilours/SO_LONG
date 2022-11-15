/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:14:09 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/15 18:44:18 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_read_line(int fd, char *line)
{
	char	*temp;
	int		i;

	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	i = 1;
	while (!ft_strchr(line, '\n') && i != 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if ((i == -1) || read(fd, temp, 0))
		{
			free(temp);
			temp = NULL;
			return (NULL);
		}
		temp[i] = '\0';
		line = ft_strjoin(line, temp);
	}
	free(temp);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stock = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stock = ft_read_line(fd, stock);
	if (!stock)
		return (NULL);
	line = ft_get_line(stock);
	stock = ft_get_new_line(stock);
	return (line);
}