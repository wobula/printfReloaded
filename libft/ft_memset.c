/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:09:30 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/02 13:44:31 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				counter;
	unsigned char	*p;

	counter = 0;
	p = b;
	while (len > 0)
	{
		p[counter] = c;
		counter++;
		len--;
	}
	p = NULL;
	return (b);
}
