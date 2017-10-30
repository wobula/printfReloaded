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

typedef union
{
	short			small;
	int				normal;
	long			semi;
	intmax_t		big;
	uintmax_t		super;
	char			chr;
	char			*str;
}					raw;

typedef struct		s_spec
{
	bool			left_align;
	bool			show_sign;
	bool			prepend_space;
	bool			prepend_zero;
	bool			alt_form;
	int				width;
	int				precision;
	char			length[3];
	char			type;
	raw				data;
	int 			len;
	int 			*ret;
}					t_spec;

int		gather_flags(t_spec *this, char *format, int x);
void	format_strings(t_print *ptr, t_spec *this);

#endif