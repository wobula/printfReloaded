/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:19:39 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:24:00 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	**ft_words(char const *str, char c)
{
	int i;
	int word_c;
	char**ptr;

	i = -1;
	word_c = 0;
	while (str[++i])
	{
		if (str[i] != c)
		{
			word_c++;
			while (str[i] != c && str[i + 1] != '\0')
				i++;
		}
	}
	ptr = (char **)ft_memalloc(sizeof(char *) * (word_c + 1));
	if (!ptr)
		return (NULL);
	ptr[word_c] = 0;
	return (ptr);
}

static char	*ft_fill(char const *str, char *ptr, char c, int i)
{
	int x;

	x = 0;
	while (str[i] != c && str[i] != '\0')
	{
		ptr[x] = str[i];
		x++;
		i++;
	}
	ptr[x] = '\0';
	return (ptr);
}

static char	*ft_letters(char const *str, char delim, int letter)
{
	int d;
	int b;
	char*ptr;

	b = letter;
	d = 0;
	while (str[b] != delim && str[b] != '\0')
	{
		d++;
		b++;
	}
	ptr = (char *)ft_memalloc(sizeof(char) * (d + 1));
	if (!ptr)
		return (NULL);
	ptr = ft_fill(str, ptr, delim, letter);
	return (ptr);
}

char	**ft_strsplit(char const *str, char delim)
{
	int letter;
	int word;
	char**ptr;

	if ((!delim) || (!str))
		return (NULL);
	word = 0;
	letter = -1;
	ptr = ft_words(str, delim);
	if (!ptr)
		return (NULL);
	while (str[++letter] != '\0')
	{
		if (str[letter] != delim)
		{
			ptr[word] = ft_letters(str, delim, letter);
			while (str[letter] != delim && str[letter + 1] != '\0')
				letter++;
			word++;
		}
	}
	return (ptr);
}
