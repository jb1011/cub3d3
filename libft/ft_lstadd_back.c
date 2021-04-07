/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:31:02 by jdemenet          #+#    #+#             */
/*   Updated: 2020/11/21 11:31:04 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*list;

	if (!alst)
		return ;
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	list = *alst;
	while (list->next)
		list = list->next;
	list->next = new;
}
