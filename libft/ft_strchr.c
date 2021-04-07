/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:28:46 by jdemenet          #+#    #+#             */
/*   Updated: 2020/11/16 17:06:39 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char letter;

	letter = (char)c;
	while (*s != letter && *s)
		s++;
	if (*s == letter)
		return ((char *)s);
	if (!c && *s == '\0')
		return ((char *)s);
	return (0);
}
