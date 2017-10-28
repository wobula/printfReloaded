/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:59:12 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:24:50 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strtrim(char const *s)
{
	int	e;
	int	b;
	int	x;
	char*ptr;

	x = 0;
	b = 0;
	if (!s)
		return (NULL);
	while (s[b] == ' ' || s[b] == '\n' || s[b] == '\t')
		b++;
	e = b;
	while (s[e + 1] != '\0')
		e++;
	while (s[e] == ' ' || s[e] == '\n' || s[e] == '\t')
		e--;
	ptr = (char*)malloc((sizeof(char) * (e - b)) + 2);
	if (ptr == NULL)
		return (NULL);
	while (b <= e)
		ptr[x++] = s[b++];
	ptr[x] = '\0';
	return (ptr);
}
