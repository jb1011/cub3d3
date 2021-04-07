/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet@student.42.fr <jdemenet>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:47:57 by jdemenet          #+#    #+#             */
/*   Updated: 2021/03/31 10:23:42 by jdemenet@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

int		ft_count(char const *s, char c)
{
	int		counter;
	int		is_word;

	is_word = 0;
	counter = 0;
	while (*s)
	{
		if (*s == c)
			is_word = 0;
		else if (is_word == 0)
		{
			is_word = 1;
			counter++;
		}
		s++;
	}
	return (counter);
}

int		is_rgb(int i)
{
	if (i >= 0 && i <= 255)
		return (1);
	else
		return (0);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		ft_path_compare(char *s1)
{
	if ((ft_strcmp(s1, "./textures/brick.xpm") == 0) || (ft_strcmp(s1, "./textures/metal.xpm") == 0) ||
		(ft_strcmp(s1, "./textures/wood.xpm") == 0) || (ft_strcmp(s1, "./textures/grass.xpm") == 0))
		return (1);
	return (0);
}

int		ft_tablen(char **map)
{
	int i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}
