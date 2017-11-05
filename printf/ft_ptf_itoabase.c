/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_itoabase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:58:34 by rschramm          #+#    #+#             */
/*   Updated: 2017/02/11 12:51:04 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** If you're new to programming, I think I can probably guess what
** you're thinking when you look at itoabase.  It's something like
** "omgwhatthefuckisallofthatfuckingmathmoduloBULLSHIT!!/cry"
** For now, ignore the math, ignore the modulo.  The thing to pay
** attention to is that this function accepts an unsigned number, and 
** then it spits out a converted character string that doesn't utilize
** malloc'd memory space.  In my printf, the call function records the
** integer sign before feeding it into itoabase.  This makes it possible
** to use the same itoabase for both signed and unsigned integers (I bring
** the sign back during the formatting phase of printf).
**
** The other thing that is happening in this weird and beautiful
** function is that we are passing 'opt' in as a mechanism for controlling 
** upper and lowercase printing functionality.  If opt is 0, we use lowercase, 
** else we add an offset to the 'o' index value so that we can access the
** uppercase letters that are at the end of the string.  (Check my header file
** to see the definition of "NUMBERSET")
*/

char		*ft_ptf_itoabase(uintmax_t val, int base, int opt)
{
	static char	buf[32] = "0";
	char		set[32] = NUMBERSET;
	int			i;
	int 		o;

	i = 30;
	o = 0;
	if (opt != 0)
		o = 16;
	if (val == 0)
		return (ft_strcpy(buf, "0\0"));
	while (val > 0 && i > 0)
	{
		buf[i] = set[(val + o) % base];
		val = val / base;
		--i;
	}
	return (buf + i + 1);
}