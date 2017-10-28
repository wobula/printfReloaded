/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rschramm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 15:18:32 by rschramm          #+#    #+#             */
/*   Updated: 2017/01/13 18:13:20 by rschramm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if ((alst != NULL) && (new != NULL))
	{
		new->next = *alst;
		*alst = new;
	}
	return ;
}
