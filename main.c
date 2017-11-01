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
	int y;
	int z;

	x = 0;
	y = 42;
	z = -42;
	ft_putstr("~~~~~~~~~~~~~~\n");
	ft_putstr("%-#8.5o\n");
	x = printf("**%-#8.5o\n", y);
	fflush(stdout);
	printf("return: %d\n", x);
	fflush(stdout);
	x = ft_printf("--%-#8.5o\n", y);
	printf("my return: %d\n", x);
	fflush(stdout);
	ft_putstr("\n~~~~~~~~~~~~~~\n");
	x = printf("**%-#20.10o\n", z);
	fflush(stdout);
	ft_putstr("%-#20.10o\n");
	printf("return: %d\n", x);
	fflush(stdout);
	x = ft_printf("--%-#20.10o\n", z);
	printf("my return: %d\n", x);
	fflush(stdout);
	ft_putstr("\n~~~~~~~~~~~~~~\n");
	x = printf("**%-#15o\n", y);
	fflush(stdout);
	ft_putstr("%-#15o\n");
	printf("return: %d\n", x);
	fflush(stdout);
	x = ft_printf("--%-#15o\n", y);
	printf("my return: %d\n", x);
	fflush(stdout);
	ft_putstr("\n~~~~~~~~~~~~~~\n");
	x = printf("**%-#20o\n", z);
	fflush(stdout);
	ft_putstr("%-#20o\n");
	printf("return: %d\n", x);
	fflush(stdout);
	x = ft_printf("--%-#20o\n", z);
	printf("my return: %d\n", x);
	fflush(stdout);
	ft_putstr("\n~~~~~~~~~~~~~~\n");
	return (0);
}