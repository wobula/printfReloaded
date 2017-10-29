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

#include <stdio.h>
#include "../includes/libft.h"
#include "../includes/printf.h"

/*

static int	length(t_print *all, char *f)
{
	int c;

	c = 0;
	if (all->length)
		ft_strdel(&all->length);
	if (f[c] == 'h' && f[c + 1] == 'h' && (c = c + 2))
		all->length = ft_strdup("hh\0");
	else if (f[c] == 'h' && (c = c + 1))
		all->length = ft_strdup("h\0");
	else if (f[c] == 'l' && f[c + 1] == 'l' && (c = c + 2))
		all->length = ft_strdup("ll\0");
	else if (f[c] == 'l' && (c = c + 1))
		all->length = ft_strdup("l\0");
	else if (f[c] == 'z' && (c = c + 1))
		all->length = ft_strdup("z\0");
	else if (f[c] == 'j' && (c = c + 1))
		all->length = ft_strdup("j\0");
	return (c);
}

static int	precision(t_print *all, char *f)
{
	int c;
	char*ptr;

	c = 1;
	all->precision = 0;
	if (f[c] >= '0' && f[c] <= '9')
	{
		while (f[c] >= '0' && f[c] <= '9')
			c++;
		ptr = ft_strnxdup(f, 1, c - 1);
		all->precision = ft_atoi(ptr);
		ft_strdel(&ptr);
	}
	if (f[c] == '*' && (c = c + 1))
		all->precision = va_arg(all->arg, int);
	return (c);
}

static int	width(t_print *all, char *f)
{
	int c;
	char*ptr;

	c = 0;
	if (f[c] >= '1' && f[c] <= '9')
	{
		while (f[c] >= '0' && f[c] <= '9')
			c++;
		ptr = ft_strnxdup(f, 0, c);
		all->width = ft_atoi(ptr);
		ft_strdel(&ptr);
	}
	if (f[c] == '*' && (c = c + 1))
		all->width = va_arg(all->arg, int);
	return (c);
}

int		gather_flags(t_spec *this, char *f)
{
	int c;
	int skip;

	c = 0;
	skip = 0;
	while (!specifier(all, f[c]) && f[c] != '\0')
	{
		if ((skip = length(all, f + c)))
			c = c + skip - 1;
		else if (f[c] == '.' && (skip = precision(all, f + c)))
			c = c + skip - 1;
		else if ((skip = width(all, f + c)))
			c = c + skip - 1;
		else if ((skip = flags(all, f + c)))
			c = c + skip - 1;
		c++;
	}
	return (c);
}*/

void	printDebug(char *str, int field)
{
	ft_putstr(str);
	ft_putnbr(field);
	ft_putchar('\n');
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

int		gather_flags(t_spec *this, char *format)
{
	int x;

	x = -1;
	ft_putstr("inside flags\n");
	ft_putstr(format);
	while (!specifier(this, format[++x]))
		;
	printDebug("left align: ", this->left_align);
	printDebug("show sign: ", this->show_sign);
	printDebug("prepend space: ", this->prepend_space);
	printDebug("prepend zero: ", this->prepend_zero);
	printDebug("alt form: ", this->alt_form);
	printDebug("width: ", this->width);
	printDebug("precision: ", this->precision);
	ft_putstr("length: ");
	ft_putstr(this->length);
	ft_putstr("\ntype: ");
	ft_putchar(this->type);
	ft_putchar('\n');
	ft_putstr("outside flags\n\n");
	return (0);
}