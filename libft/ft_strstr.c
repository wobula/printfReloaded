/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 19:52:55 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:24:12 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int c;
	int x;
	int r;

	c = 0;
	x = 0;
	if (little[0] == '\0')
		return ((char*)big);
	while (big[c] != '\0')
	{
		r = c;
		while (little[x] == big[r])
		{
			if (little[x + 1] == '\0')
				return ((char*)&big[c]);
			x++;
			r++;
		}
		c++;
		x = 0;
	}
	return (0);
}
