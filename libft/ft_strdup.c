/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:05:38 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/01 11:34:02 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		counter;
	char	*ptr;

	counter = 0;
	if (!s1)
		return (NULL);
	while (s1[counter] != '\0')
		counter++;
	ptr = (char*)ft_memalloc(sizeof(char) * counter + 1);
	counter = 0;
	while (s1[counter] != '\0')
	{
		ptr[counter] = s1[counter];
		counter++;
	}
	ptr[counter] = '\0';
	return (ptr);
}
