/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:34 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/11 12:51:04 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	main(void)
{
	int x;
	intmax_t y;
	int z;

	x = 0;
	y = 99999999999;
	z = -42;
	ft_putstr("~~~~~~~~~~~~~~\n");
	ft_putstr("%-8.5jx\n");
	x = printf("**%-8.5jd\n", y);
	fflush(stdout);
	printf("return: %d\n", x);
	fflush(stdout);
	x = ft_printf("--%-8.5jx\n", y);
	printf("my return: %d\n", x);
	fflush(stdout);
	ft_putstr("\n~~~~~~~~~~~~~~\n");
	return (0);
}