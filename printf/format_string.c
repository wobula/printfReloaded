/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_string                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:34 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/11 12:51:04 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	print_width(t_spec *this)
{
	int print;

	if (this->precision >= 0 && this->precision < this->len)
		print = this->width - this->precision;
	else
		print = this->width - this->len;
	while (print > 0)
	{
		ft_putchar_fd(' ', *this->fd);
		print--;
		*this->ret = *this->ret + 1;
	}
}

static void	print_precision(t_spec *this)
{
	int print;

	if (this->precision != -1 && this->precision < this->len)
		print = this->precision;
	else
		print = this->len;
	write(*this->fd, this->data.str, print);
	*this->ret = *this->ret + print;
}

void		format_string(t_print *ptr, t_spec *this)
{
	this->data.str = va_arg(ptr->arg, char*);
	this->len = ft_strlen(this->data.str);
	if (this->left_align == true)
	{
		print_precision(this);
		print_width(this);
	}
	else
	{
		print_width(this);
		print_precision(this);
	}
}