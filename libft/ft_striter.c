/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 16:49:48 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:20:20 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	int counter;

	if ((!s) || (!f))
		return ;
	counter = 0;
	while (s[counter] != '\0')
	{
		f(&s[counter]);
		counter++;
	}
}
