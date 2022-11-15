/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 20:14:31 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/15 18:44:15 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
