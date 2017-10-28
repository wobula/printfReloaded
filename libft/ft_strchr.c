/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:14:15 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:18:37 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				counter;
	unsigned char	l;
	char			*x;
	char			*ptr;

	x = (char *)s;
	l = (unsigned char)c;
	counter = 0;
	while (x[counter] != '\0')
	{
		if (x[counter] == l)
		{
			ptr = &x[counter];
			return (ptr);
		}
		counter++;
	}
	if (x[counter] == l)
	{
		ptr = &x[counter];
		return (ptr);
	}
	return (NULL);
}
