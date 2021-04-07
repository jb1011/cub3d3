/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:11:24 by jdemenet          #+#    #+#             */
/*   Updated: 2020/11/16 17:42:51 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strrchr(const char *s, int c)
{
	char			letter;
	unsigned long	lenght;

	lenght = ft_strlen(s);
	letter = (char)c;
	if (letter == 0)
		return ((char *)s + lenght);
	while (lenght--)
	{
		if (*(s + lenght) == c)
			return ((char *)(s + lenght));
	}
	return (0);
}
