/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:34 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/11 12:51:04 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdbool.h>
# include "../includes/libft.h"

typedef struct		s_print
{
	int				ret;
	const char		*format;
	va_list			arg;
}					t_print;

typedef struct		s_spec
{
	//flags, width, precision, length, specifier
	bool			left_align;
	bool			show_sign;
	bool			prepend_space;
	bool			prepend_zero;
	bool			alt_form;
	int				width;
	int				precision;
	char			length[2];
	char			type;
}					t_spec;

int		gather_flags(t_spec *this, char *format);

#endif