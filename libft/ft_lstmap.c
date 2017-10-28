/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 16:00:15 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:14:08 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list *blah;

	if (lst)
	{
		blah = f(lst);
		blah->next = ft_lstmap(lst->next, f);
		return (blah);
	}
	return (NULL);
}
