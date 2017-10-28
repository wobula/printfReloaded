/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 18:08:46 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:18:23 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int counter;
	int counter_2;

	counter = -1;
	counter_2 = -1;
	while (s1[++counter])
		;
	while (s2[++counter_2])
	{
		s1[counter] = s2[counter_2];
		counter++;
	}
	return (s1);
}
