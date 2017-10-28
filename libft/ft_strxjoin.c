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

char	*ft_strxjoin(char *s1, char *s2, size_t opt)
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
	if (opt == 1)
		free(s1);
	else if (opt == 2)
		free(s2);
	else if (opt == 3)
	{
		free(s1);
		free(s2);
	}
	return (ptr);
}