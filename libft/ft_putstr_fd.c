/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:51:56 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:18:02 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int counter;

	if ((!s) || (!fd))
		return ;
	counter = 0;
	while (s[counter] != '\0')
	{
		write(fd, &s[counter], 1);
		counter++;
	}
}
