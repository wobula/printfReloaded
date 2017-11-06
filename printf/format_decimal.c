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

static void get_sign(t_spec *this, t_format *form)
{
	if (this->data.super < 0)
	{
		form->sign = '-';
		this->data.super *= -1;
	}
	else if (this->show_sign == true)
	{
		form->sign = '+';
		form->length++;
	}
}

static void	constructor(t_spec *this, t_format *form)
{
	form->sign = 0;
	get_sign(this, form);
	form->print = ft_ptf_itoabase((uintmax_t)this->data.super, 10, this->alt_form);
	form->length = ft_strlen(form->print);
	form->zeroes = 0;
	form->spaces = 0;
	if (this->precision > form->length)
		form->zeroes += this->precision - form->length;
	if (form->sign != 0)
		form->length++;
	if (this->width > form->length + form->zeroes)
		form->spaces += this->width - (form->length + form->zeroes);
}

static void print_character(t_spec *this, char c, int times)
{
	while (times > 0)
	{
		ft_putchar_fd(c, *this->fd);
		times--;
		*this->ret = *this->ret + 1;
	}
}

static void print_width(t_spec *this, t_format *form)
{
	if (this->prepend_zero == true)
	{
		if (form->sign != 0)
			ft_putchar_fd(form->sign, *this->fd);
		print_character(this, '0', form->spaces);
	}
	else
		print_character(this, ' ', form->spaces);
}

void		format_decimal(t_print *ptr, t_spec *this)
{
	t_format form;

	conversions(ptr, this);
	constructor(this, &form);
	if (this->left_align == false)
	{
		print_width(this, &form);
		if (form.sign != 0 && this->prepend_zero == false)
			ft_putchar_fd(form.sign, *this->fd);
		print_character(this, '0', form.zeroes);
		ft_fputstr_fd(form.print, *this->fd);
	}
	else
	{
		if (form.sign != 0)
			ft_putchar_fd(form.sign, *this->fd);
		print_character(this, '0', form.zeroes);
		ft_fputstr_fd(form.print, *this->fd);
		print_character(this, ' ', form.spaces);
	}
	*this->ret = *this->ret + form.length;
}