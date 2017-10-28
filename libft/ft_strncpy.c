/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 17:12:16 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:22:12 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t c;
	size_t b;

	b = 0;
	c = 0;
	while (src[b] != '\0')
		b++;
	while (c < len)
	{
		if (b < c)
			dst[c] = '\0';
		else
			dst[c] = src[c];
		c++;
	}
	return (dst);
}
