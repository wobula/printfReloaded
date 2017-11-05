/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:34 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/11 12:51:04 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Just a constructor so we don't have any junk in the trunk, I mean struct.
*/

static void constructor(t_print *ptr, t_spec *this)
{
	this->left_align = false;
	this->show_sign = false;
	this->prepend_space = false;
	this->prepend_zero = false;
	this->alt_form = false;
	this->width = 0;
	this->precision = -1;
	this->length[0] = '\0';
	this->length[1] = '\0';
	this->length[2] = '\0';
	this->type = 0;
	this->len = 0;
	this->ret = &ptr->ret;
}

/*
** Welcome to frankenstein!  I like to give my function names personality, 
** and printf is a monster!
**
** This part of the code marks the begining of the huge printf glacier of
** functionality that is hiding just beneath the surface of what is, pretty
** much, just a glorified putstring function.  
**
** For activate_frankenstein, we call our second struct: t_spec.  Again, 
** we are using stack memory because the malloc function has lots of overhead, 
** is slow, invites memory leaks, and creates way more programmatic complexity 
** than my feeble brain is capable of remembering.  Tracking down memory leaks 
** with valgrind is no fun.  Instead, I've decided to avoid all malloc calls so
** that I never have to stay awake at night wondering to myself, "oh my god,
** is my printf leaking?  Did I free all my mallocs?  I just don't know."
** 
** But I digress: activate frankenstein consists of three parts: constructor, gather
** flags, and format_dispatcher.  A simpler way of saying this is 1) we activate and
** zero out our struct (no trash), 2) gather meta-data, and 3) send off meta-data
** to the proper formatting function.
*/

static void	activate_frankenstein(t_print *ptr, int *xptr)
{
	t_spec this;

	constructor(ptr, &this);
	gather_flags(&this, ptr->format, xptr);
	if (this.type == 's' || this.type == 'S')
		format_string(ptr, &this);
	else if (this.type == 'd')
		format_decimal(ptr, &this);
	else if (this.type == 'c' || this.type == 'C')
		format_char(ptr, &this);
	else if (this.type == '%')
		format_percent(&this);
	else if (this.type == 'p')
		format_pointer(ptr, &this);
	else if (this.type == 'o')
		format_octal(ptr, &this);
	else if (this.type == 'x' || this.type == 'X')
		format_hex(ptr, &this);
}

/*
** This is our buffer printing function.  It's a very small variation
** on the more traditional putstring function which calls write for
** every character in the string.  Here, call write once for the entire
** buffer and print all these characters in one call.  In the context of 
** hundreds of thousands of characters printing to the screen, this 
** tiny little change in code will create massive speed optimizations.
**
** P.S. Notice how we are still keeping track of our return value. :)
*/

static void print_buffer(char *format, int *ret, int start, int x)
{
	write(1, format + start, x - start);
	*ret = *ret + x - start;
}

/*
** The parse level of printf is essentially putstring with a single
** if statement to activate formatting functionality for any '%' character.  I've
** complicated my parse function by also adding a bit of buffering.  This
** is done to increase speed.  Write calls are slow, so rather than calling
** write for every single character, we build a buffer, call write once,
** and print out the buffer in one go.  Each time we reach a % specifier,
** we print out the buffer.  We also have to clear the buffer at the very end
** once we've reached the null terminator.  Also, remember: we still have
** to keep track of how many characters we are printing out, hence the 
** continual references to ptr->ret.
**
** One other thing you may notice is that there are a lot of ampersands.  This
** is how we pass variables (stack structs) by reference.  If we passed these structs without
** the ampersand, the changes to our variables would be local in scope.  
** In other words, our functions (print_buffer, activate_frankenstein) would change the struct, 
** but those changes will not reverberate back to the calling function (parse).
*/

static void	parse(t_print *ptr)
{
	int x;
	int start;

	x = -1;
	start = 0;
	while (ptr->format[++x] != '\0')
	{
		if (ptr->format[x] == '%')
		{
			print_buffer(ptr->format, &ptr->ret, start, x);
			activate_frankenstein(ptr, &x);
			start = x + 1;
		}
	}
	print_buffer(ptr->format, &ptr->ret, start, x);
}

/*
** Our first data structure tracks 3 things: va_arg pointer,
** format pointer, and return value (printf returns the number 
** of characters printed).
*/

int			ft_printf(const char *format, ...)
{
	t_print all;

	all.ret = 0;
	all.format = (char*)format;
	va_start(all.arg, format);
	parse(&all);
	va_end(all.arg);
	return (all.ret);
}