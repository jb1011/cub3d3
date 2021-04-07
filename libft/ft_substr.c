/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:28:40 by jdemenet          #+#    #+#             */
/*   Updated: 2020/11/18 14:28:44 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		if (!(new = malloc(sizeof(char) * 1)))
			return (NULL);
		new[0] = '\0';
		return (new);
	}
	if (!(new = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while (s[start] && len > 0)
	{
		new[i] = s[start];
		i++;
		start++;
		len--;
	}
	new[i] = '\0';
	return (new);
}
