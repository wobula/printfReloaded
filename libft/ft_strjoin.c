/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 22:33:29 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/31 20:11:49 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char*ptr;
	int	x;

	if (!s1 || !s2)
		return (NULL);
	x = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)ft_memalloc(x + 1);
	if (!ptr)
		return (NULL);
	ptr[x] = '\0';
	ptr = ft_strcpy(ptr, s1);
	ptr = ft_strcat(ptr, s2);
	return (ptr);
}