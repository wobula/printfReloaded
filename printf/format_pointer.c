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

void		format_pointer(t_print *ptr, t_spec *this)
{
	char *print;

	this->data.super_u = va_arg(ptr->arg, unsigned long int);
	print = ft_ptf_itoabase(this->data.super_u, 16, 0);
	ft_fputstr_fd("0x", *this->fd);
	*this->ret = *this->ret + 2;
	ft_fputstr_fd(print, *this->fd);
	*this->ret = *this->ret + ft_strlen(print);
}