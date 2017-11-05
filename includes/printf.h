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

/*
** Intro:
**
** Since I've been a student at 42 silicon valley,
** I've observed countless other students complain about the difficulty
** involved in recoding this classic C function.  The most common
** complaint about printf is that it's 'tedious' because there is
** so much damn functionality you have to code for.
**
** I had a similar experience the first time I coded printf.  I hated
** coding printf.  Hated!  I spent a month being miserable.  But upon
** a second coding, I've now decided that printf is one of my favorite projects
** in the 42 curriculum.
**
** The key to making a good printf consists in making good broad level
** architectural choices, so that, later on, when you're knee deep in
** the formatting portions of the function, all your data will be organized
** clean, and tidy.
**
** Toward that end, this recoding has been guided by three principles:
**
** 1. Say no to malloc.
** 2. Stay organized: use structs.
** 3. Simplify.  Simplify.  Simplify.
**
** Explanation:
**
** 1. Malloc may seem like your friend at first glance: instant memory!  It is not.
** Malloc is a trap, especially in big functions like printf.  Malloc requires that 
** you keep track of every single byte of data it gives you so that you can free it.
** Over the course of hundreds of lines of code and several weeks of coding,
** many tired programmers forget their own variables--myself included.  This
** is how memory leaks start.
**
** One other tidbit of information about malloc is that it requires a lot of
** hidden overhead.  Malloc keeps track of its own memory by creating a linked 
** list that systematizes all that data.  And, while the original C-programmers 
** are good, linked lists are, by definition not very fast.  Keep it simple.
** Don't introduce complexity where its not needed.  Say no to malloc.
** 
** Stack memory is your friend.
**
** 2. Structs might seem intimidating to the newbie programmer, but, in fact,
** structs are your best friends (especially stack structs).  Structs give you
** a way to stay organized.  Create a struct inside of a header file, and you can
** add and remove variables anywhere in your program by simply changing the header file.
** This is an awesome tool.  But be careful: this same freedom of creating variables
** can also lead to bloated structs.  Try to be hard on yourself: if you can get rid
** of a variable in your struct, always do so.  Make them compact and pretty.  A simple
** struct is a happy struct.  :D
**
** 3. Printf is a huge function.  To keep it from becoming too big of a monster, always,
** always, always compartmentalize and compress your code.  Doing so makes it easier to
** read, simpler to plan, and more fun to work with.  Don't let your code control you:
** always make sure you are in control of your code.
*/

//entry level
typedef struct				s_print
{
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