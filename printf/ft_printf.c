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

static void init_percent(t_print *ptr, t_spec *this)
{
	this->left_align = false;
	this->show_sign = false;
	this->prepend_space = false;
	this->prepend_zero = false;
	this->alt_form = false;
	this->width = 0;
	this->precision = -1;
	this->length[0] = '\0';
	this->length[1] = '\0';
	this->length[2] = '\0';
	this->type = 0;
	this->len = 0;
	this->ret = &ptr->ret;
}

void activate_frankenstein(t_print *ptr, int *xptr)
{
	t_spec test;
	t_spec *this;

	this = &test;
	init_percent(ptr, this);
	gather_flags(this, (char*)ptr->format, *xptr);
	if (this->type == 's' || this->type == 'S')
		format_strings(ptr, this);
	*xptr += ft_strlen(ptr->format);
}

static void no_frank(t_print *ptr, int *x)
{
	ft_putchar(ptr->format[*x]);
	ptr->ret++;
}

static void	parse(t_print *ptr)
{
	int x;
	int *xptr;

	x = -1;
	xptr = &x;
	while (ptr->format[++*xptr] != '\0')
	{
		if (ptr->format[*xptr] == '%')
			activate_frankenstein(ptr, xptr);
		else
			no_frank(ptr, xptr);
	}
}

int		ft_printf(const char *format, ...)
{
	t_print all;
	t_print *ptr;

	all.ret = 0;
	ptr = &all;
	ptr->format = ft_strdup(format);
	va_start(ptr->arg, format);
	parse(ptr);
	va_end(all.arg);
	return (all.ret);
}