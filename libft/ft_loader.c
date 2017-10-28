/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:30:44 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/11 12:47:50 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_loaderl(char *dst, int nbr, int size)
{
	int sign;

	if (nbr == 0)
	{
		dst[0] = '0';
		return (dst);
	}
	else if (nbr < 0)
	{
		sign = -1;
		nbr = nbr * -1;
	}
	size--;
	while (nbr > 0)
	{
		dst[size] = nbr % 10 + '0';
		nbr = nbr / 10;
		size--;
	}
	if (sign == -1)
		dst[size] = '-';
	return (dst);
}
