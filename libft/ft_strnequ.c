/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 22:22:28 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:20:07 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	counter;
	int		equal;

	counter = 0;
	equal = 1;
	if (!s1 && !s2)
		return (1);
	else if (!s1 || !s2)
		return (0);
	while (s1[counter] && n > counter)
	{
		if (s1[counter] != s2[counter])
			equal = 0;
		counter++;
	}
	counter = 0;
	while (s2[counter] && n > counter)
	{
		if (s2[counter] != s1[counter])
			equal = 0;
		counter++;
	}
	return (equal);
}
