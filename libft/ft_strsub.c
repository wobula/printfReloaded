/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:10:02 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:24:37 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		counter;

	counter = 0;
	if (!s)
		return (NULL);
	ptr = malloc((sizeof(char) * (len)) + 1);
	if (!ptr)
		return (NULL);
	while (len > 0)
	{
		ptr[counter] = s[start];
		start++;
		counter++;
		len--;
	}
	ptr[counter] = '\0';
	return (ptr);
}
