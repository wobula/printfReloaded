/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:39:31 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:17:09 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int				counter;
	unsigned char	*s_c;

	counter = 0;
	s_c = ((unsigned char *)s);
	if ((!s) || (!fd))
		return ;
	while (s_c[counter] != '\0')
	{
		write(fd, &s_c[counter], 1);
		counter++;
	}
	write(fd, "\n", 1);
}
