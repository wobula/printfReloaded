/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:57:01 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:20:32 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int counter;

	if ((!s) || (!f))
		return ;
	counter = 0;
	while (s[counter] != '\0')
	{
		f(counter, &s[counter]);
		counter++;
	}
}
