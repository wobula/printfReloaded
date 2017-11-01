/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_pointer                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:34 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/11 12:51:04 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"

void	format_pointer(t_print *ptr, t_spec *this)
{
	char *print;

	this->data.hex_oct = va_arg(ptr->arg, unsigned long int);
	print = ft_ptf_itoabase(this->data.hex_oct, 16, 0);
	ft_putstr("0x");
	*this->ret = *this->ret + 2;
	ft_putstr(print);
	*this->ret = *this->ret + ft_strlen(print);
}