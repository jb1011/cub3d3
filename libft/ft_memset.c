/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:35:36 by jdemenet          #+#    #+#             */
/*   Updated: 2020/11/17 11:35:40 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	int				i;
	unsigned char	*my_s;

	i = 0;
	my_s = s;
	while (n > 0)
	{
		my_s[i] = (unsigned char)c;
		n--;
		i++;
	}
	return (s);
}
