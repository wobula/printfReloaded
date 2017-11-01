/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_octal                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:34 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/11 12:51:04 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"

static void	print_character(t_spec *this, char c, int times)
{
	while (times > 0)
	{
		ft_putchar(c);
		*this->ret = *this->ret + 1;
		times--;
	}
}

static void	constructor(t_spec *this, t_format *form)
{
	form->print = ft_ptf_itoabase(this->data.hex_oct, 8, 0);
	form->length = ft_strlen(form->print);
	form->zeroes = 0;
	if (this->alt_form == true && form->print[0] != '0')
		form->zeroes++;
	if (this->left_align == true)
	{
		if (this->precision > form->length + form->zeroes)
			form->zeroes = this->precision - form->length;
		form->spaces = this->width - (form->zeroes + form->length);
	}
	else
	{
		if (this->precision > form->length + form->zeroes)
			form->zeroes = this->precision - form->length;
		if (this->prepend_zero == true)
			form->zeroes += this->width - (form->zeroes + form->length);
		else
			form->spaces = this->width - (form->zeroes + form->length);
	}
}

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
}