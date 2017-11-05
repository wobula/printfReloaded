/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:34 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/11 12:51:04 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Conversions are where we retrieve information from the elipsis aspect of
** printf.  If this feels like bullshit computer magic, don't feel bad.  I
** felt the same way for the entire run through of my first coding of printf.
** So wtf is going on with va_args?  How does this process work?  Think of it
** like this: va_start allocates memory inside the computer, and it stores all
** your variable strings and numbers inside of this happy-computer-memory land.
** Then when you do your va_arg call, va_arg uses your data_type as a means for
** figuring out where to start and stop reading memory from happy memory land.
** So if you get this part of the function wrong, your printf will print out
** a bunch of bullshit because it is retrieving truncated or incomplete data.
** And, as everyone knows, truncated and incomplete data makes pandas sad.  :(
*/

void	conversions_u(t_print *ptr, t_spec *this)
{
	if (this->length[0] == 'h' && this->length[1] == 'h')
		this->data.super_u = (unsigned char)va_arg(ptr->arg, unsigned int);
	else if (this->length[0] == 'h')
		this->data.super_u = (unsigned short)va_arg(ptr->arg, unsigned int);
	else if (this->length[0] == 'l' && this->length[1] == 'l')
		this->data.super_u = va_arg(ptr->arg, unsigned long long int);
	else if (this->length[0] == 'l')
		this->data.super_u = va_arg(ptr->arg, unsigned long int);
	else if (this->length[0] == 'j')
		this->data.super_u = va_arg(ptr->arg, uintmax_t);
	else if (this->length[0] == 'z')
		this->data.super_u = va_arg(ptr->arg, size_t);
	else
		this->data.super_u = va_arg(ptr->arg, unsigned int);
}

/*
** If you'll notice, I've used a union as the storage container for all
** my va_args data.  WTF is a union?  It's something cool that makes me look
** SUPER smart.  Don't let that fool you.  I am not that smart, and you can tell
** by how I'm storing everything in a massive intmax_t/uintmax_t data type because
** I'm too lazy to actually use appropriately sized containers as that would
** require way more thinking than I feel like doing.
**
** Seriously though, think of a union as a really large container that can be used to
** carry lots of different types of data--but it can only carry one at a time.  So
** if we store a number in this->data.super_u, we can't also use the string portion of the union 
** at the same time: the string and the number in our union are sharing the same memory.  WTF is the
** point of this?  This enables us to reduce memory consumption.  If we used a struct, instead
** of a union, the computer would allocate independent memory spaces for each member of our
** struct.  In the context of embedded systems programming--such as a washer or dryer with a tiny
** bit of memory--we would want to as little memory as possible.  This is where unions come into play.
** And I really want to use my printf the next time I code output for a washing machine.
*/

void	conversions(t_print *ptr, t_spec *this)
{
	if (this->length[0] == 'h' && this->length[1] == 'h')
		this->data.super = (char)va_arg(ptr->arg, int);
	else if (this->length[0] == 'h')
		this->data.super = (short int)va_arg(ptr->arg, int);
	else if (this->length[0] == 'l' && this->length[1] == 'l')
		this->data.super = va_arg(ptr->arg, long long int);
	else if (this->length[0] == 'l')
		this->data.super = va_arg(ptr->arg, long int);
	else if (this->length[0] == 'j')
		this->data.super = va_arg(ptr->arg, intmax_t);
	else if (this->length[0] == 'z')
		this->data.super = va_arg(ptr->arg, size_t);
	else
		this->data.super = va_arg(ptr->arg, int);
}