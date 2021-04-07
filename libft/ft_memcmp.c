/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:23:04 by jdemenet          #+#    #+#             */
/*   Updated: 2020/11/18 13:23:06 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t		i;
	char		*my_s1;
	char		*my_s2;

	my_s1 = (void*)s1;
	my_s2 = (void*)s2;
	i = 0;
	while (i < n)
	{
		if (my_s1[i] != my_s2[i])
			return ((unsigned char)my_s1[i] - (unsigned char)my_s2[i]);
		i++;
	}
	return (0);
}
