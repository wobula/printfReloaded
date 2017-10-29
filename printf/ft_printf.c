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

static void activateFrankenstein(t_print *all, int x)
{
	t_spec this_percent;
	t_spec *ptr;

	ptr = &this_percent;
	gather_flags(ptr, (char *)all->format + x);
}

static void noFrank(t_print *all, int x)
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
			activateFrankenstein(all, ++x);
		else
			noFrank(all, x);
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