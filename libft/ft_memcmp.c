/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 20:01:29 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:15:26 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			counter;
	unsigned char	*rs1;
	unsigned char	*rs2;

	rs1 = (unsigned char *)s1;
	rs2 = (unsigned char *)s2;
	counter = 0;
	if (n == 0)
		return (0);
	else if (rs1 == NULL && rs2 == NULL)
		return (0);
	while (counter < n)
	{
		if (rs1[counter] != rs2[counter])
			return (rs1[counter] - rs2[counter]);
		counter++;
	}
	return (0);
}
