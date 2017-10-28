/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:26:35 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:23:07 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		counter;
	size_t	x;
	size_t	y;

	x = 0;
	counter = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[counter] != '\0' && len > 0)
	{
		y = counter;
		while (big[y] == little[x] && x < len && big[y] != '\0')
		{
			x++;
			y++;
			if (little[x] == '\0')
				return ((char*)(big + counter));
		}
		len--;
		counter++;
		x = 0;
	}
	return ((void *)0);
}
