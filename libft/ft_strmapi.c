/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 18:00:19 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:21:33 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		counter;
	char	*ptr;

	if ((!s) || (!f))
		return (NULL);
	counter = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (counter + 1));
	if (!ptr)
		return (NULL);
	ptr[counter] = '\0';
	counter = -1;
	while (s[++counter] != '\0')
		ptr[counter] = f(counter, s[counter]);
	return (ptr);
}
