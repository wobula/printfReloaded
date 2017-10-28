/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:11:03 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:21:23 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		counter;
	char	*ptr;

	if ((!s) || (!f))
		return (NULL);
	counter = 0;
	while (s[counter] != '\0')
		counter++;
	ptr = (char *)malloc((sizeof(char) * counter) + 1);
	if (!ptr)
		return (NULL);
	ptr[counter] = '\0';
	counter = 0;
	while (s[counter] != '\0')
	{
		ptr[counter] = f(s[counter]);
		counter++;
	}
	return (ptr);
}
