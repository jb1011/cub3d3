/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 09:32:17 by jdemenet          #+#    #+#             */
/*   Updated: 2020/11/17 09:32:21 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned long	i;
	unsigned int	j;
	size_t			src_len;

	src_len = 0;
	i = 0;
	j = 0;
	while (dst[i])
		i++;
	while (src[src_len])
		src_len++;
	if (size < i)
		return (ft_strlen(src) + size);
	while (src[j] && j + i + 1 < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + src_len);
}
