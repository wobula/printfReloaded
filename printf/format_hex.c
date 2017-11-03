/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_hex                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:34 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/11 12:51:04 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"

static void	print_character(t_spec *this, char print, int times)
{
	while (times > 0)
	{
		ft_putchar(print);
		*this->ret = *this->ret + 1;
		times--;
	}
}

static void	constructor(t_spec *this, t_format *form)
{
	if (this->type == 'x')
		form->print = ft_ptf_itoabase(this->data.super_u, 16, 0);
	else
		form->print = ft_ptf_itoabase(this->data.super_u, 16, 1);
	form->length = ft_strlen(form->print);
	form->zeroes = 0;
	form->spaces = 0;
	if (this->precision > form->length)
		form->zeroes += this->precision - form->length;
	if (this->alt_form == true)
		form->length += 2;
	if (this->width > form->length + form->zeroes)
		form->spaces = this->width - (form->length + form->zeroes);
}

void	format_hex(t_print *ptr, t_spec *this)
{
	t_format form;

	conversions(ptr, this);
	constructor(this, &form);
	if (this->left_align == false)
	{
		if (form.zeroes > 0)
			print_character(this, '0', form.spaces);
		else
			print_character(this, ' ', form.spaces);
		if (this->alt_form == true)
			ft_putstr("0x");
		print_character(this, '0', form.zeroes);
		ft_putstr(form.print);
		*this->ret = *this->ret + form.length;
	}
	else
	{
		if (this->alt_form == true)
			ft_putstr("0x");
		print_character(this, '0', form.zeroes);
		ft_putstr(form.print);
		if (form.spaces > 0)
			print_character(this, ' ', form.spaces);
		*this->ret = *this->ret + form.length;
	}
}