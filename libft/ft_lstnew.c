/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 11:42:52 by jdemenet          #+#    #+#             */
/*   Updated: 2020/11/21 11:42:55 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*list;

	if ((list = malloc(sizeof(t_list) * 1)) == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
