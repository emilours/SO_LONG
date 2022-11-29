/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:14:31 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/29 20:45:51 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*searches for the first occurrence of a char in the string*/
char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

/*concatenates two strings in a third one.
s = line (stock)
s1 = temp (where are kept what is read by function READ
and are cleaned before READ is called again.)*/
char	*strjoin_gnl(char *s, char *s1)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
	{
		s = (char *)malloc(1 * sizeof(char));
		s[0] = '\0';
	}
	if (!s || !s1)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(s) + ft_strlen(s1)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (s)
		while (s[++i] != '\0')
			str[i] = s[i];
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	str[ft_strlen(s) + ft_strlen(s1)] = '\0';
	free(s);
	return (str);
}

/*finds the line to be returned by GNL in what I read
thanks to ft_read_line and copies this string in str.*/
char	*ft_get_line(char *s)
{
	int		i;
	char	*str;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		str[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*Cleans my stock : the char not returned by GNL remain in my static char.
old line = what is returned by GNL + what is not returned by GNL.
The chars remaining (> /n) are kept to be copied in new line.
new line = strlen(old line) - GNL(return).*/
char	*ft_get_new_line(char *old_line)
{
	int		i;
	int		j;
	char	*new_line;

	i = 0;
	if (!old_line)
	{
		free(old_line);
		return (NULL);
	}
	while (old_line[i] && old_line[i] != '\n')
		i++;
	if (old_line[i] == '\0' || old_line[i + 1] == '\0')
		return (free(old_line), NULL);
	new_line = malloc(sizeof(char) * ((ft_strlen(old_line) - i) + 1));
	if (!new_line)
		return (free(old_line), NULL);
	if (old_line[i] == '\n')
		i++;
	j = 0;
	while (old_line[i])
		new_line[j++] = old_line[i++];
	new_line[j] = '\0';
	free(old_line);
	return (new_line);
}
