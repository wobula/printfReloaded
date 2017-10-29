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
/*
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
*/
void activateFrankenstein(t_print *all, int x)
{
	//initSpecifier(ptr);
	//gather_flags(ptr, (char *)all->format + *x);
	ft_putstr("---");
	ft_putnbr(x);
	x += ft_strlen(all->format);
}

static void noFrank(t_print *ptr, int x)
{
	ft_putchar(ptr->format[x]);
	ptr->ret++;
}

static void	parse(t_print *ptr)
{
	int x = -1;

	while (ptr->format[++x])
	{
		if (ptr->format[x] == '%')
			activateFrankenstein(ptr, x);
		else
			noFrank(ptr, x);
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
	va_end(all.arg);
	return (1);
}