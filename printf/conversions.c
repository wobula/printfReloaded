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

void	conversions_u(t_print *ptr, t_spec *this)
{
	if (this->length[0] == 'h' && this->length[1] == 'h')
		this->data.chr_u = (unsigned char)va_arg(ptr->arg, int);
	else if (this->length[0] == 'h')
		this->data.small_u = (unsigned short)va_arg(ptr->arg, uintmax_t);
	else if (this->length[0] == 'l' && this->length[1] == 'l')
		this->data.big_u = va_arg(ptr->arg, unsigned long long int);
	else if (this->length[0] == 'l')
		this->data.big_u = va_arg(ptr->arg, unsigned long int);
	else if (this->length[0] == 'j')
		this->data.super_u = va_arg(ptr->arg, unsigned long int);
	else if (this->length[0] == 'z')
		this->data.wtf_is_size_t = va_arg(ptr->arg, size_t);
	else
		this->data.normal_u = va_arg(ptr->arg, unsigned int);
}

void	conversions(t_print *ptr, t_spec *this)
{
	if (this->length[0] == 'h' && this->length[1] == 'h')
		this->data.chr = (char)va_arg(ptr->arg, int);
	else if (this->length[0] == 'h')
		this->data.small = (short int)va_arg(ptr->arg, intmax_t);
	else if (this->length[0] == 'l' && this->length[1] == 'l')
		this->data.big = va_arg(ptr->arg, long long int);
	else if (this->length[0] == 'l')
		this->data.big = va_arg(ptr->arg, long int);
	else if (this->length[0] == 'j')
		this->data.super = va_arg(ptr->arg, long int);
	else if (this->length[0] == 'z')
		this->data.wtf_is_size_t = va_arg(ptr->arg, size_t);
	else
		this->data.normal = va_arg(ptr->arg, int);
}