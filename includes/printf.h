/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
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

# define NUMBERSET "0123456789abcdef0123456789ABCDEF"

//entry level -- return value, format pointer, va_arg list
typedef struct				s_print
{
	int 					fd;
	int						ret;
	char					*format;
	va_list					arg;
}							t_print;

//raw va_args data -- stores va_arg calls
typedef union
{
	char					chr;
	char					*str;
	intmax_t				super;
	uintmax_t				super_u;
	void					*ptr;
}							raw;

//specifier level -- stores formatting meta-data
typedef struct				s_spec
{
	bool					alt_form;
	bool					left_align;
	bool					prepend_space;
	bool					prepend_zero;
	bool					show_sign;
	char					length[3];
	char					type;
	int 					len;
	int						precision;
	int						width;
	int 					*ret;
	int 					*fd;
	raw						data;
}							t_spec;

//formatting level -- utility struct for printing output
typedef struct 				s_format
{
	char 					sign;
	char 					*print;
	int 					length;
	int 					spaces;
	int 					zeroes;
}							t_format;

//		Meta-data
void	parse(t_print *ptr);
int		gather_flags(t_spec *this, char *format, int *x);

//		Conversions
void	conversions(t_print *ptr, t_spec *this);
void	conversions_u(t_print *ptr, t_spec *this);

//		Formatters
void	format_char(t_print *ptr, t_spec *this);
void	format_percent(t_spec *this);
void	format_string(t_print *ptr, t_spec *this);
void	format_decimal(t_print *ptr, t_spec *this);
void	format_pointer(t_print *ptr, t_spec *this);
void	format_octal(t_print *ptr, t_spec *this);
void	format_hex(t_print *ptr, t_spec *this);

//		Helpers
char	*ft_ptf_itoabase(uintmax_t val, int base, int opt);

#endif