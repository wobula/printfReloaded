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
	char *y;
	int z;

	x = 0;
	y = "what is a supdog?";
	z = -42;
	ft_putstr("~~~~~~~~~~~~~~\n");
	ft_putstr("%10s\n");
	x = printf("**%10s\n", y);
	fflush(stdout);
	printf("return: %d\n", x);
	fflush(stdout);
	x = ft_printf("--%&&10s\n", 34, 41, y);
	printf("my return: %d\n", x);
	fflush(stdout);
	ft_putstr("\n~~~~~~~~~~~~~~\n");
	ft_putstr("~~~~~~~~~~~~~~\n");
	ft_putstr("%10s\n");
	x = dprintf(2, "**%10s\n", y);
	fflush(stdout);
	printf("return: %d\n", x);
	fflush(stdout);
	x = ft_dprintf(2, "--%10s\n", y);
	printf("my return: %d\n", x);
	fflush(stdout);
	ft_putstr("\n~~~~~~~~~~~~~~\n");
	return (0);
}
