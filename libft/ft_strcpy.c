/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:02:24 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:19:11 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	int counter;

	counter = 0;
	while (src[counter] != '\0')
	{
		dst[counter] = src[counter];
		counter++;
	}
	if (src[counter] == '\0')
		dst[counter] = '\0';
	return (dst);
}
