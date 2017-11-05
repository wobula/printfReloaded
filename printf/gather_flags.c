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

static int ft_isflag(char test)
{
	if (test == '#' || test == '-' || test == '+' ||
	 test == '0' || test == ' ')
		return (1);
	return (0);
}

/*
** ft_isflag and flags are two functions that do very similar things.
** The first identifies if a character is a flag, while the second
** makes a record of the flag in our struct and increments us to the
** next character in the string.
*/

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

/*
** Length describes the size of the datatype you are feeding into
** printf.  If your printf call is 'printf("%jd is hardcore\n", 42);',
** then printf will think the number 42 is using an intmax_t datatype.
** Why the hell does this matter?  Because if you want to output
** really big numbers like, 9999999999999, a plain old int will not
** work.  If we use an int, what will happen is when we make our va_args call, 
** the container will be too small (such as an int), and our output will
** look like a bunch of bullshit (aka overflow values).
*/

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

/*
** Width describes the *minimum* number of characters printf outputs to
** the screen.  So, if we have a width of 10 and our string is 'robin'
** printf will output '     robin' to the screen.  Conversely, if we
** choose to left align our string, printf will output 'robin     '.
** This same concept applies to digits.  One other thing: printf always
** evaluates number/string length first, then precision, and after all
** this is finished -- then it evaluates width.  Another way of thinking
** about this is as follows:
**
** if (precision > string_length), 
**     then string_length += precision - string length
** if (width > string_length)
**     then pad_value = width - string_length
**
** Please note: we are using strcpy and a char stack buffer, NOT strdup,
** because we don't want to deal with any malloc and/or memory leak shenanigans.
*/

static int	width(t_spec *this, char *format)
{
	int x;

	x = 0;
	this->width = ft_atoi(format);
	while (ft_isdigit(format[++x]))
			;
	return (x - 1);
}

/*
** Precision has two basic forms: strings and numbers.  For strings
** precision controls the *maximum* number of characters print to the
** screen (truncating anything beyond that number).  In the case of
** numbers, precision controls the *minimum* number of characters
** printing to the screen.  So if we have a precision of 2 and our
** number is '1', printf will add one extra padding '0' character so
** that the output is '01'.  This comes in handy if we want to print 
** out rows of data and we want all those rows to line up.
*/

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
	else
		this->precision = 0;
	return (x);
}

/*
** I've got specifiers for lots of different letters; don't let this part
** intimidate you.  It's just a bunch of letters!  I've scrunched the code
** together so that I can feel smrt.  :D
*/

static int	specifier(t_spec *this, char c)
{
	if ((c == 's' || c == 'd' || c == 'i' || c == 'c' || c == '%' || c == 'u'
		|| c == 'n' || c == 'o' || c == 'e' || c == 'e' || c == 'x' || c == 'X'
		|| c == 'p' || c == 'G' || c == 'g' || c == 'S' || c == 'D' || c == 'C'
		|| c == 'O' || c == 'U') && (this->type = c))
		return (1);
	return (0);
}

/*
** Gather flags is the epicenter for retrieving all our specifier information.
** For my basic version of printf, I'm only gathering information on flags, precision
** width, length, and the specifier.  Basically, it's just a while loop
** that looks for a bunch of different characters.  For organizational and optimization
** purposes, I've chosen to break up all these character searches into different functions.
** If we find a relavent character, we make a note in our t_spec struct.  
** If we hit a specifier, we break out of our loop and stop collecting meta-data.  
**
** One thing you may notice is that the return values for each of these parsing functions
** is set equal to the dereferenced variable of x.  WTF IS GOING ON?  The purpose of this
** is so that once we go through the flag portion of our string, we never have to go
** through it again.  Think of it as a small speed optimization that can have major
** implications if we are printing out hundreds and thousands of characters with lots
** of specifiers.
*/

int			gather_flags(t_spec *this, char *format, int *x)
{
	while (format[++*x] && !(specifier(this, format[*x])))
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