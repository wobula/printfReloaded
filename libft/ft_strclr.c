/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 10:54:35 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:18:48 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_strclr(char *s)
{
	int counter;

	counter = 0;
	if (!s)
		return ;
	while (s[counter] != '\0')
	{
		s[counter] = '\0';
		counter++;
	}
}
