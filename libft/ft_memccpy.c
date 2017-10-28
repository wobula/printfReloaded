/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:16:03 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:15:01 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			x;
	unsigned char	*dst_c;
	unsigned char	*src_c;
	unsigned char	d;
	unsigned char	*ptr;

	d = (unsigned char)c;
	dst_c = (unsigned char *)dst;
	src_c = (unsigned char *)src;
	x = 0;
	while (x < n)
	{
		dst_c[x] = src_c[x];
		if (src_c[x] == d)
		{
			ptr = &dst_c[x + 1];
			return (ptr);
		}
		x++;
	}
	return (NULL);
}
