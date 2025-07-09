/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:55:02 by manmaria          #+#    #+#             */
/*   Updated: 2025/04/17 18:08:26 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(char const *s, char c)
{
	size_t	cw;

	cw = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			cw++;
		while (*s != c && *s)
			s++;
	}
	return (cw);
}

static size_t	count_letters(char const *s, char c, char **p_s)
{
	size_t	letters;

	letters = 0;
	while (*s != c && *s)
	{
		letters++;
		s++;
	}
	*p_s = (char *)s;
	return (letters);
}

static char	**free_split(char **save)
{
	char	**marcemon;

	marcemon = save;
	while (1)
	{
		if (!*save)
			break ;
		free(*save);
		save++;
	}
	free(marcemon);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**save;
	char	**split;
	size_t	words;
	size_t	letters;

	words = count_words(s, c);
	split = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!split)
		return (NULL);
	save = split;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			letters = count_letters(s, c, (char **)&s);
			*split = ft_substr(s - letters, 0, letters);
			if (!*split)
				return (free_split(save));
			split++;
		}
	}
	return (save);
}
