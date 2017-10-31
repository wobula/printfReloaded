/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:34 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/11 12:51:04 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"

static void	print_width(t_spec *this)
{
	int print;

	print = this->width - this->len;
	while (print > 0)
	{
		ft_putchar(' ');
		print--;
		*this->ret = *this->ret + 1;
	}
}

static void	print_char(char output, int *ret)
{
	ft_putchar(output);
	*ret = *ret + 1;
}

void	format_char(t_print *ptr, t_spec *this)
{
	this->data.chr = (char)va_arg(ptr->arg, int);
	this->len = 1;
	if (this->left_align == true)
	{
		print_char(this->data.chr, this->ret);
		print_width(this);
	}
	else
	{
		print_width(this);
		print_char(this->data.chr, this->ret);
	}
}