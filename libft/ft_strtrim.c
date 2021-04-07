/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 15:09:13 by jdemenet          #+#    #+#             */
/*   Updated: 2020/11/18 15:09:15 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_inside(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (ft_is_inside(s1[start], (char*)set) >= 0)
		start++;
	if ((end - start) <= 0)
		return (ft_substr(s1, 0, 0));
	while (ft_is_inside(s1[end - 1], (char *)set) >= 0)
		end--;
	return (ft_substr(s1, start, end - start));
}
