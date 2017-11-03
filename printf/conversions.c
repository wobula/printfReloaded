/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:34 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/11 12:51:04 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"

void	conversions(t_print *ptr, t_spec *this)
{
	ft_putstr(this->length);
	if (this->length[0] == 'j')
		this->data.big = va_arg(ptr->arg, uintmax_t);
	ft_putstr("inside format decimal\n");
	ft_putchar(this->type);
	ft_putchar('\n');
	ft_putnbr(this->data.normal);
	ft_putchar('\n');
}