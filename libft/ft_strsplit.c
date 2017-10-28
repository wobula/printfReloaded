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

char	*ft_fill(char const *str, char *ptr, char c, int i)
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

static char	**ft_words(char const *str, char c)
{
	int i;
	int word_c;
	char**ptr;

	i = 0;
	word_c = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			word_c++;
			while (str[i] != c && str[i + 1] != '\0')
				i++;
		}
		i++;
	}
	ptr = (char **)malloc((sizeof(*ptr) * word_c) + 1);
	if (!ptr)
		return (NULL);
	ptr[word_c] = NULL;
	return (ptr);
}


static char	*ft_letters(char const *str, char c, int i)
{
	int d;
	int b;
	char*ptr;

	b = i;
	d = 0;
	while (str[b] != c && str[b] != '\0')
	{
		d++;
		b++;
	}
	ptr = (char *)malloc((sizeof(ptr) * d) + 1);
	if (!ptr)
		return (NULL);
	ptr = ft_fill(str, ptr, c, i);
	return (ptr);
}

char	**ft_strsplit(char const *s, char c)
{
	int i;
	int d;
	char**ptr;

	if ((!c) || (!s))
		return (NULL);
	d = 0;
	i = 0;
	ptr = ft_words(s, c);
	if (!ptr)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			ptr[d] = ft_letters(s, c, i);
			while (s[i] != c && s[i + 1] != '\0')
				i++;
			d++;
		}
		i++;
	}
	return (ptr);
}
