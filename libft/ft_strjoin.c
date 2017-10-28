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

char	*ft_strjoin(char *s1, char *s2)
{
	int	c;
	char*ptr;

	if (!s1 || !s2)
		return (NULL);
	c = ft_strlen(s1) + ft_strlen(s2);
	ptr = ft_memalloc(c);
	if (!ptr)
		return (NULL);
	ptr = ft_strxcpy(ptr, s1, 0, 0);
	ptr = ft_strxcpy(ptr, s2, 0, (ft_strlen(s1)));
	return (ptr);
}
