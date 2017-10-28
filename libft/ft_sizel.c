/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:23:04 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/13 12:23:06 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_sizel(int nbr)
{
	int		array_size;

	array_size = 0;
	if (nbr == 0)
		return (1);
	else if (nbr < 0)
	{
		array_size++;
	}
	while (nbr != 0)
	{
		nbr = nbr / 10;
		array_size++;
	}
	return (array_size);
}
