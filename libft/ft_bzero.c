/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 21:32:08 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/29 01:13:22 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			counter;

	p = s;
	counter = 0;
	while (counter < n)
	{
		p[counter] = 0;
		counter++;
	}
}
