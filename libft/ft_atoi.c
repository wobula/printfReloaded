/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 15:55:00 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:10:43 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(const char *str)
{
	int		result;
	int		c;
	int		sign;

	result = 0;
	c = 0;
	sign = 1;
	while ((str[c] >= 9 && str[c] <= 13) || str[c] == ' ')
		c++;
	if (str[c] == '-')
	{
		sign = -1;
		c++;
	}
	else if (str[c] == '+')
		c++;
	while (str[c] && ft_isdigit(str[c]) == 1)
	{
		result = result * 10 + str[c] - '0';
		c++;
	}
	return (result * sign);
}
