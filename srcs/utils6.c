/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:02:28 by jdemenet          #+#    #+#             */
/*   Updated: 2021/04/07 16:02:29 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

void	ft_count_2(t_struct_t *s)
{
	int i;
	int j;

	j = 0;
	while (s->map[j])
	{
		i = 0;
		while (s->map[j][i])
		{
			if (s->map[j][i] == '2')
			{
				s->sp.nbspr += 1;
			}
			i++;
		}
		j++;
	}
}

int		is_map(char c)
{
	if (c == '1' || c == ' ' || c == '0' || c == '2' || c == 0)
		return (1);
	return (0);
}

void	ft_call_f(t_struct_t *my_struct)
{
	printf("Error\nError in map\n");
	my_struct->error = 1;
}