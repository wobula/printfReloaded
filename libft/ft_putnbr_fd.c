/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 19:55:59 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:17:36 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(nbr * -1, fd);
	}
	else if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putchar_fd(nbr % 10 + '0', fd);
	}
	else if (nbr < 10)
	{
		ft_putchar_fd(nbr + '0', fd);
	}
}
