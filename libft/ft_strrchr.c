/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:30:13 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:23:47 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				counter;
	unsigned char	x;
	const char		*ptr;

	x = c;
	counter = 0;
	ptr = NULL;
	while (s[counter] != '\0')
	{
		if (s[counter] == x)
			ptr = &s[counter];
		counter++;
	}
	if (s[counter] == x)
		ptr = &s[counter];
	return ((char*)ptr);
}
