/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:34 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/11 12:51:04 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/printf.h"

static int ft_isflag(char test)
{
	if (test == '#' || test == '-' || test == '+' ||
	 test == '0' || test == ' ')
		return (1);
	return (0);
}

static int flags(t_spec *this, char *format)
{
	int x;

	x = -1;
	while (ft_isflag(format[++x]))
	{
		if (format[x] == '#')
			this->alt_form = true;
		else if (format[x] == ' ')
			this->prepend_space = true;
		else if (format[x] == '0')
			this->prepend_zero = true;
		else if (format[x] == '+')
			this->show_sign = true;
		else if (format[x] == '-')
			this->left_align = true;
	}
	return (x - 1);
}

static int length(t_spec *this, char *format)
{
	int c;

	c = 0;
	if (format[c] == 'h' && format[c + 1] == 'h' && (c = c + 2))
		ft_strcpy(this->length, "hh\0");
	else if (format[c] == 'h' && (c = c + 1))
		ft_strcpy(this->length, "h\0");
	else if (format[c] == 'l' && format[c + 1] == 'l' && (c = c + 2))
		ft_strcpy(this->length, "ll\0");
	else if (format[c] == 'l' && (c = c + 1))
		ft_strcpy(this->length, "l\0");
	else if (format[c] == 'z' && (c = c + 1))
		ft_strcpy(this->length, "z\0");
	else if (format[c] == 'j' && (c = c + 1))
		ft_strcpy(this->length, "j\0");
	return (c - 1);
}

static int	width(t_spec *this, char *format)
{
	int x;

	x = 0;
	this->width = ft_atoi(format);
	while (ft_isdigit(format[++x]))
			;
	return (x - 1);
}

static int	precision(t_spec *this, char *format)
{
	int x;

	x = 0;
	if (ft_isdigit(format[x]))
	{
		this->precision = ft_atoi(format);
		while (ft_isdigit(format[++x]))
			;
	}
	return (x);
}

static int	specifier(t_spec *this, char c)
{
	if ((c == 's' || c == 'd' || c == 'i' || c == 'c' || c == '%' || c == 'u'
		|| c == 'n' || c == 'o' || c == 'e' || c == 'e' || c == 'x' || c == 'X'
		|| c == 'p' || c == 'G' || c == 'g' || c == 'S' || c == 'D' || c == 'C'
		|| c == 'O' || c == 'U') && (this->type = c))
		return (1);
	return (0);
}

int		gather_flags(t_spec *this, char *format, int *x)
{
	while (!(specifier(this, format[++*x])))
	{
		if (ft_isflag(format[*x]))
			*x += flags(this, format + *x);
		else if (format[*x] == '.')
			*x += precision(this, format + *x + 1);
		else if (ft_isdigit(format[*x]))
			*x += width(this, format + *x);
		else if (ft_isalpha(format[*x]))
			*x += length(this, format + *x);
	}
	return (0);
}