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

//entry level
typedef struct				s_print
{
	int						ret;
	char					*format;
	va_list					arg;
}							t_print;

//raw va_args data
typedef union
{
	char					chr;
	unsigned char 			chr_u;
	char					*str;
	short					small;
	unsigned short 			small_u;
	int						normal;
	unsigned int 			normal_u;
	long int				big;
	unsigned long int 		big_u;
	long long int 			mega;
	unsigned long long int 	mega_u;
	intmax_t				super;
	uintmax_t				super_u;
	size_t					wtf_is_size_t;
	void					*ptr;
}							raw;

//specifier level
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
	raw						data;
}							t_spec;

//formatting level
typedef struct 				s_format
{
	char 					*print;
	int 					length;
	int 					spaces;
	int 					zeroes;
}							t_format;

//		Meta-data retrieval
int		gather_flags(t_spec *this, char *format, int *x);
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