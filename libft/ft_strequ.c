/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 11:00:43 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:19:56 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int counter;
	int equal;

	equal = 1;
	counter = 0;
	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2)
		return (0);
	while (s1[counter] != '\0')
	{
		if (s1[counter] != s2[counter])
			equal = 0;
		counter++;
	}
	while (s2[counter] != '\0')
	{
		if (s1[counter] != s2[counter])
			equal = 0;
		counter++;
	}
	return (equal);
}
