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
	int ret;
	char *ptr = "hello world!";

	ret = ft_printf("%-+3.3lld\n", 10);
	//ret = ft_printf("%- 03.5hhd\n", 99);
	//ret = ft_printf("%15.10s\n", ptr);
	ret = ft_printf("%-15.10s\n", ptr);
	return (0);
}