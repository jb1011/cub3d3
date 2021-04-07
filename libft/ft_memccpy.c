/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:09:02 by jdemenet          #+#    #+#             */
/*   Updated: 2020/11/17 14:09:08 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*my_dest;
	unsigned const char	*my_src;
	size_t				i;

	my_dest = dest;
	my_src = src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (n > i)
	{
		my_dest[i] = my_src[i];
		if (my_src[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
