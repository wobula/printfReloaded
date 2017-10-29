/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/01 22:32:06 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:22:34 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strndup(const char *s1, size_t offset)
{
	size_t	counter;
	char	*ptr;

	counter = ft_strlen(s1 + offset);
	ptr = (char *)ft_memalloc(sizeof(char) * (counter + 1));
	if (ptr == NULL)
		return (NULL);
	counter = -1;
	while (s1[++counter + offset] != '\0')
		ptr[counter] = s1[counter + offset];
	ptr[counter] = '\0';
	return (ptr);
}
