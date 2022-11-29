/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:14:09 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/29 20:46:13 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*I read and I keep what is read in temp.
Temp is concatenated to line(my stock).
temp is freed to be reused for another read.*/
char	*ft_read_line(int fd, char *line)
{
	char	*temp;
	int		i;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	i = 1;
	while (!ft_strchr(line, '\n') && i != 0)
	{
		i = read(fd, temp, BUFFER_SIZE);
		if ((i == -1) || read(fd, temp, 0))
		{
			free(temp);
			return (NULL);
		}
		temp[i] = '\0';
		line = strjoin_gnl(line, temp);
	}
	free(temp);
	return (line);
}

/*If the read chars don’t contain a \n 
and if the BUFFER_SIZE is nut null,
all we need to do is READ again and add the new read chars.
Then, if there is a \n in the static string, we will
 be able to extract the part before the \n,
to return it as a line, saving the other part
 in the static variable, over and over.*/
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
