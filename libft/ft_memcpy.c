/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:51:59 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/31 20:33:38 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *restrict d, const void *restrict s, size_t n)
{
	unsigned char		*dst_c;
	unsigned const char *src_c;
	size_t				counter;

	dst_c = d;
	src_c = s;
	counter = 0;
	while (counter < n)
	{
		dst_c[counter] = src_c[counter];
		counter++;
	}
	return (dst_c);
}
