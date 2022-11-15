/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eminatch <eminatch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:31:45 by eminatch          #+#    #+#             */
/*   Updated: 2022/11/09 16:50:53 by eminatch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
// # include <stdio.h>

static int	tot_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	return (len);
}

int	ft_word_count(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
			count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (count);
}

char	*ft_strddup(const char *s, char c)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_calloc(tot_len(s, c) + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	**ft_free(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**tab;

	i = 0;
	if (s == NULL)
		return (NULL);
	tab = ft_calloc(ft_word_count(s, c) + 1, sizeof(char *));
	if (tab == NULL)
		return (NULL);
	while (*s && ft_word_count(s, c))
	{
		while (*s != '\0' && *s == c)
			s++;
		if (*s != '\0' && *s != c)
		{
			tab[i] = ft_strddup(s, c);
			if (tab[i] == NULL)
				return (ft_free(tab, i));
			i++;
		}
		while (*s != '\0' && *s != c)
			s++;
	}
	return (tab);
}

// static int	tot_len(const char *s, char c)
// {
// 	int	len;

// 	len = 0;
// 	while (s[len] != '\0' && s[len] != c)
// 		len++;
// 	return (len);
// }

// int	ft_word_count(const char *s, char c)
// {
// 	int	i;
// 	int	count;

// 	count = 0;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		while (s[i] != '\0' && s[i] == c)
// 			i++;
// 		if (s[i] != '\0' && s[i] != c)
// 			count++;
// 		while (s[i] != '\0' && s[i] != c)
// 			i++;
// 	}
// 	return (count);
// }

// char	*ft_strddup(const char *s, char c)
// {
// 	int		i;
// 	char	*str;

// 	i = 0;
// 	str = ft_calloc(tot_len(s, c) + 1, sizeof(char));
// 	if (str == NULL)
// 	{
// 		free(str);
// 		return (NULL);
// 	}
// 	while (s[i] != '\0' && s[i] != c)
// 	{
// 		str[i] = s[i];
// 		i++;
// 	}
// 	str[i] = '\0';
// 	return (str);
// }

// char	**ft_clean(char **tab, int i)
// {
// 	while (i >= 0)
// 	{
// 		free(tab[i]);
// 		i--;
// 	}
// 	free(tab);
// 	return (NULL);
// }

// char	**ft_split(char const *s, char c)
// {
// 	size_t	i;
// 	char	**tab;

// 	i = 0;
// 	if (s == NULL)
// 		return (NULL);
// 	tab = ft_calloc(ft_word_count(s, c) + 1, sizeof(char *));
// 	// if (tab == NULL)
// 	// {
// 	// 	ft_clean(tab, i);
// 	// 	return (NULL);
// 	// }
// 	while (*s && ft_word_count(s, c))
// 	{
// 		while (*s != '\0' && *s == c)
// 			s++;
// 		if (*s != '\0' && *s != c)
// 		{
// 			tab[i] = ft_strddup(s, c);
// 			if (tab[i] == NULL)
// 				return (ft_clean(tab, i));
// 			printf("tab[%zu] = %s / %p\n", i, tab[i], &tab[i]);
// 			i++;
// 		}
// 		while (*s != '\0' && *s != c)
// 			s++;
// 	}
// 	return (tab);
// }

/*int	main(void)
{
	int		i;
	char		charset = ' ';
	char		*tab = " tripouille  42   blabla   ";
	char		**result;

	i = 0;
	result = ft_split(tab, charset);
	while (result[i])
	{
		printf("%s\n", result[i]);
		i++;
	}
	for (size_t j = 0; result[j]; j++)
	{
		free(result[j]);
	}
	free(result);
	return (0);
}*/