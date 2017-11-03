/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:34 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/11 12:51:04 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"

void	format_decimal(t_print *ptr, t_spec *this)
{
	this->data.normal = va_arg(ptr->arg, int);
	ft_putstr("inside format decimal\n");
	ft_putchar(this->type);
	ft_putchar('\n');
	ft_putnbr(this->data.normal);
	ft_putchar('\n');
}
/*
void		format_octal(t_print *ptr, t_spec *this)
{
	t_format form;

	this->data.hex_oct = va_arg(ptr->arg, unsigned long int);
	constructor(this, &form);
	if (this->left_align)
	{
		print_character(this, '0', form.zeroes);
		ft_putstr(form.print);
		print_character(this, ' ', form.spaces);
		*this->ret = *this->ret + form.length;
	}
	else
	{
		print_character(this, ' ', form.spaces);
		print_character(this, '0', form.zeroes);
		ft_putstr(form.print);
		*this->ret = *this->ret + form.length;
	}
}*/