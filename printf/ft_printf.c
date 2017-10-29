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

static void initSpecifier(t_spec *this)
{
	this->left_align = false;
	this->show_sign = false;
	this->prepend_space = false;
	this->prepend_zero = false;
	this->alt_form = false;
	this->width = 0;
	this->precision = 0;
	this->length[0] = 0;
	this->length[1] = 0;
	this->type = 0;
}

static void activateFrankenstein(t_print *all, int *x)
{
	t_spec this_percent;
	t_spec *ptr;

	ptr = &this_percent;
	initSpecifier(ptr);
	gather_flags(ptr, (char *)all->format + *x);
	*x += ft_strlen(all->format);
}

static void noFrank(t_print *all, int x)
{
	ft_putchar(all->format[x]);
	all->ret++;
}

static void	parse(t_print *all)
{
	int x = -1;
	int *p = &x;

	all->ret = 0;
	while (all->format[++x])
	{
		if (all->format[x] == '%')
			activateFrankenstein(all, p);
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