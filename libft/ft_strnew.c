/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 21:56:05 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:22:52 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *ptr;

	ptr = malloc(sizeof(char) * size + 1);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, size);
	ptr[size] = '\0';
	return (ptr);
}
