/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vwaldon <vwaldon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:22:42 by vwaldon           #+#    #+#             */
/*   Updated: 2021/10/27 14:31:42 by vwaldon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *str, char c)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i] && str[i] == c)
		i++;
	while (str[i])
	{
		while (str[i] && str[i] != c)
			i++;
		count++;
		while (str[i] && str[i] == c)
			i++;
	}
	return (count);
}

static void	ft_free(char **arr, int count)
{
	int	i;

	i = 0;
	while (i <= count)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

static size_t	ft_letter_count(const char *s, char c)
{
	size_t		letter;

	letter = 0;
	while (*s != c && *s)
	{
		letter++;
		s++;
	}
	return (letter);
}

static char	**ft_array(char **arr, char const *s, char c)
{
	size_t		i;
	size_t		wordcount;

	i = 0;
	wordcount = ft_countwords((char *)s, c);
	arr = (char **)malloc(sizeof(char *) * (wordcount + 1));
	if (!arr)
		return (NULL);
	while (*s)
	{	
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{	
			arr[i] = ft_substr(s, 0, ft_letter_count(s, c));
			if (arr[i++] == NULL)
			{
				ft_free(arr, i);
				return (NULL);
			}
			s = s + ft_letter_count(s, c);
		}
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**split;

	split = NULL;
	if (!s)
		return (NULL);
	split = ft_array(split, s, c);
	if (!split)
		return (NULL);
	return (split);
}
