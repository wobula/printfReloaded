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
	printf("**%-13.3s\n", "what is a sup dog");
	fflush(stdout);
	ft_printf("--%-13.3s\n", "what is a sup dog");
	ft_putstr("\n~~~~~~~~~~~~~~\n");
	printf("**%-20s\n", "what is a sup dog");
	fflush(stdout);
	ft_printf("--%-20s\n", "what is a sup dog");
	ft_putstr("\n~~~~~~~~~~~~~~\n");
	printf("**%-.0s\n", "what is a sup dog");
	fflush(stdout);
	ft_printf("--%-.0s\n", "what is a sup dog");
	ft_putstr("\n~~~~~~~~~~~~~~\n");
	return (0);
}