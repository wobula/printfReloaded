/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:34 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/11 12:51:04 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"

static int activateFrankenstein(t_print *all, int x)
{
	int ret;

	ret = -1;
	while (all->format[x + (ret++)] != 's')
	{
		ft_putchar(all->format[x + ret]);
		all->ret++;
	}
	all->ret++;
	ft_putchar(all->format[x + ret]);
	return (x + ret);
}

static void noFrankenstein(t_print *all, int x)
{
	ft_putchar(all->format[x]);
	all->ret++;
}

static void	parse(t_print *all)
{
	int x = -1;
	all->ret = 0;
	while (all->format[++x])
	{
		if (all->format[x] == '%')
			x = activateFrankenstein(all, x);
		else
			noFrankenstein(all, x);
	}
}

int		ft_printf(const char *format, ...)
{
	t_print all;
	t_print *ptr;

	ptr = &all;
	ptr->format = format;
	va_start(ptr->arg, format);
	parse(ptr);
	va_end(ptr->arg);
	return (ptr->ret);
}