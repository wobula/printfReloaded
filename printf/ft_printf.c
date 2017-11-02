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

static void constructor(t_print *ptr, t_spec *this)
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

static void	activate_frankenstein(t_print *ptr, int *xptr)
{
	t_spec this;

	constructor(ptr, &this);
	gather_flags(&this, ptr->format, xptr);
	if (this.type == 's' || this.type == 'S')
		format_string(ptr, &this);
	else if (this.type == 'd')
		format_decimal(ptr, &this);
	else if (this.type == 'c' || this.type == 'C')
		format_char(ptr, &this);
	else if (this.type == '%')
		format_percent(&this);
	else if (this.type == 'p')
		format_pointer(ptr, &this);
	else if (this.type == 'o')
		format_octal(ptr, &this);
	else if (this.type == 'x' || this.type == 'X')
		format_hex(ptr, &this);
}

static void no_frank(t_print *ptr, int *x)
{
	ft_putchar(ptr->format[*x]);
	ptr->ret++;
}

static void	parse(t_print *ptr)
{
	int x;

	x = -1;
	while (ptr->format[++x] != '\0')
	{
		if (ptr->format[x] == '%')
			activate_frankenstein(ptr, &x);
		else
			no_frank(ptr, &x);
	}
}

int			ft_printf(const char *format, ...)
{
	t_print all;

	all.ret = 0;
	all.format = (char*)format;
	va_start(all.arg, format);
	parse(&all);
	va_end(all.arg);
	return (all.ret);
}