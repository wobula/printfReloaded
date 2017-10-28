/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:34:52 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:13:34 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *nxlst;

	if ((!alst) || (!del))
		return ;
	lst = *alst;
	while (lst)
	{
		nxlst = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = nxlst;
	}
	*alst = NULL;
	return ;
}
