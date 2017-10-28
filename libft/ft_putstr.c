/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:53:40 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/01 12:02:50 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr(char *str)
{
	int counter;

	counter = 0;
	if (!str && (write(1, "(null)", 6)))
		return ;
	while (str[counter] != '\0')
	{
		write(1, &str[counter], 1);
		counter++;
	}
}
