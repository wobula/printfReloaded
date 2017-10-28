/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 19:01:10 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:15:15 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	l;
	unsigned char	*m;
	size_t			a;
	unsigned char	*ptr;

	a = 0;
	m = (unsigned char*)s;
	l = (unsigned char)c;
	while (a < n)
	{
		if (m[a] == l)
		{
			ptr = &m[a];
			return (ptr);
		}
		a++;
	}
	return (NULL);
}
