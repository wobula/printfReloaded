/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:34 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/11 12:51:04 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Our first data structure tracks 3 things: va_arg pointer,
** format pointer, and return value (printf returns the number 
** of characters printed).  Did I say 3 things?  This is dprintf
** so actually there is one additional thing to keep track of:
** the file descriptor.  Standard out is 1, standard error is 2. :D
*/

int			ft_dprintf(int fd, const char *format, ...)
{
	t_print all;

	all.ret = 0;
	all.fd = fd;
	all.format = (char*)format;
	va_start(all.arg, format);
	parse(&all);
	va_end(all.arg);
	return (all.ret);
}