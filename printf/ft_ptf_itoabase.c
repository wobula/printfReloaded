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
	int			i;

	i = 30;
	if (val == 0)
		return (ft_strcpy(buf, "0\0"));
	while (val > 0 && i > 0)
	{
		if (opt == 0)
			buf[i] = "0123456789abcdef"[val % base];
		else
			buf[i] = "0123456789ABCDEF"[val % base];
		val = val / base;
		--i;
	}
	return (buf + i + 1);
}