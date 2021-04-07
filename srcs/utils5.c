/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:09:55 by jdemenet          #+#    #+#             */
/*   Updated: 2021/04/07 15:10:00 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

void	ft_map_check_right(my_struct_t *my_struct, int i, int j)
{
	int x;
	int y;

	y = j;
	x = i;
	while ((size_t)x < ft_strlen(my_struct->mapcpy[j]))
	{
		if (my_struct->mapcpy[y][x] == '1' || my_struct->mapcpy[y][x] == 'X')
			my_struct->mapcpy[j][i] = 'X';
		x++;
	}
}
