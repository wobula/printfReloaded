/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:34:52 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:21:52 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t c;

	c = 0;
	while (n > c)
	{
		if (s1[c] != s2[c])
			return ((unsigned char)s1[c] - (unsigned char)s2[c]);
		if (s1[c] == '\0' && s2[c] == '\0')
			return (0);
		c++;
	}
	return (0);
}
