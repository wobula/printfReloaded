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

char		*ft_ptf_itoabase(uintmax_t val, int base, int opt)
{
	static char	buf[32] = "0";
	char		set[32] = "0123456789abcdef0123456789ABCDEF";
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