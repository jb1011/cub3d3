/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:16:41 by jdemenet          #+#    #+#             */
/*   Updated: 2020/11/18 13:16:45 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*my_s;

	i = 0;
	my_s = (void*)s;
	while (i < n)
	{
		if (my_s[i] == (unsigned char)c)
			return (my_s + i);
		i++;
	}
	return (NULL);
}
