/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:06:16 by jdemenet          #+#    #+#             */
/*   Updated: 2021/04/07 14:06:18 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

char	**ft_tabcpy(char **tab)
{
	int		i;
	char	**tab2;

	i = 0;
	if (!(tab2 = malloc(sizeof(char *) * (ft_tablen(tab) + 1))))
		return (NULL);
	while (tab[i])
	{
		tab2[i] = ft_strdup(tab[i]);
		i++;
	}
	tab2[i] = 0;
	return (tab2);
}

void	ft_display_map(char **tab)
{
	int j;

	j = 0;
	while (tab[j])
	{
		ft_putstr_fd(tab[j], 0);
		ft_putstr_fd("\n", 0);
		j++;
	}
}

int		ft_check_for_0(char **tab)
{
	int	i;
	int	j;

	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == '0')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int		is_spawn(char c)
{
	if (c == 'N' || c == 'N' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	ft_rgbconv(t_struct_t *s)
{
	s->hexaf = 256 * 256 * s->f_r + 256 * s->f_g + s->f_b;
	s->hexac = 256 * 256 * s->c_r + 256 * s->c_g + s->c_b;
}
