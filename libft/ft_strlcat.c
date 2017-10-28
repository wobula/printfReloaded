/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:32:34 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:21:01 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t first;
	size_t second;
	size_t third;

	first = 0;
	second = 0;
	third = 0;
	while (dst[first] != '\0' && first < size)
		first++;
	while (src[second] != '\0')
		second++;
	third = first;
	while (src[first - third] && first < size - 1)
	{
		dst[first] = src[first - third];
		first++;
	}
	if (third < size)
		dst[first] = '\0';
	return (third + second);
}
