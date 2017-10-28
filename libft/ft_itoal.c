/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:22:43 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/13 12:22:45 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_sizel(int nbr)
{
	int		array_size;

	array_size = 0;
	if (nbr == 0)
		return (1);
	else if (nbr < 0)
		array_size++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		array_size++;
	}
	return (array_size);
}

static char	*ft_malloc(int size)
{
	char	*ptr;

	ptr = ft_memalloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	ptr[size] = '\0';
	return (ptr);
}

static char	*ft_loaderl(char *dst, int nbr, int size)
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

char	*ft_itoal(int nbr)
{
	int		size;
	char	*ptr;

	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_size(nbr);
	ptr = ft_malloc(size);
	if (!ptr)
		return (NULL);
	return (ft_loaderl(ptr, nbr, size));
}
