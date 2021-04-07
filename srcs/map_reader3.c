/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:05:24 by jdemenet          #+#    #+#             */
/*   Updated: 2021/04/07 14:05:25 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

void	ft_map_check_down(my_struct_t *my_struct, int i, int j)
{
	int x;
	int y;

	y = j;
	x = i;
	while (my_struct->mapcpydown[y])
	{
		if ((size_t)x < ft_strlen(my_struct->mapcpydown[y]))
		{
			if (my_struct->mapcpydown[y][x] == '1' ||
					my_struct->mapcpydown[y][x] == 'X')
				my_struct->mapcpydown[j][i] = 'X';
		}
		else
			return ;
		y++;
	}
}

int		ft_check_for_spaces(my_struct_t *my_struct)
{
	int i;
	int j;

	j = 1;
	while (j < my_struct->last_columns)
	{
		i = 0;
		while (my_struct->mapcpy[j][i])
		{
			if (my_struct->mapcpy[j][i] == '0')
			{
				if (my_struct->mapcpy[j][i - 1] == ' ')
					return (0);
				if (my_struct->mapcpy[j][i + 1] == ' ')
					return (0);
				if (my_struct->mapcpy[j - 1][i] == ' ')
					return (0);
				if (my_struct->mapcpy[j + 1][i] == ' ')
					return (0);
			}
			i++;
		}
		j++;
	}
	return (1);
}

int		ft_check_for_spawn(my_struct_t *my_struct)
{
	int i;
	int j;
	int count;

	j = 1;
	count = 0;
	while (j < my_struct->last_columns)
	{
		i = 0;
		while (my_struct->mapcpy[j][i])
		{
			if (my_struct->mapcpy[j][i] == 'N' ||
					my_struct->mapcpy[j][i] == 'S' ||
						my_struct->mapcpy[j][i] == 'E' ||
							my_struct->mapcpy[j][i] == 'W')
				count++;
			i++;
		}
		j++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int		ft_check_right_spawn(my_struct_t *my_struct)
{
	int i;
	int j;

	j = 0;
	while (++j < my_struct->last_columns)
	{
		i = 0;
		while (my_struct->mapcpy[j][i])
		{
			if (my_struct->mapcpy[j][i] == 'N' || my_struct->mapcpy[j][i] == 'S'
			|| my_struct->mapcpy[j][i] == 'E' || my_struct->mapcpy[j][i] == 'W')
			{
				if (my_struct->mapcpy[j][i - 1] == ' ')
					return (0);
				if (my_struct->mapcpy[j][i + 1] == ' ')
					return (0);
				if (my_struct->mapcpy[j - 1][i] == ' ')
					return (0);
				if (my_struct->mapcpy[j + 1][i] == ' ')
					return (0);
			}
			i++;
		}
	}
	return (1);
}

int		ft_check_garbage(my_struct_t *my_struct)
{
	int i;
	int j;

	j = 1;
	while (j < my_struct->last_columns)
	{
		i = 0;
		while (my_struct->mapcpy[j][i])
		{
			if (my_struct->mapcpy[j][i] != '0' && my_struct->mapcpy[j][i] != '1'
				&& my_struct->mapcpy[j][i] != '2' &&
					my_struct->mapcpy[j][i] != 'N'
					&& my_struct->mapcpy[j][i] != 'S' &&
						my_struct->mapcpy[j][i] != 'W' &&
							my_struct->mapcpy[j][i] != 'E'
							&& my_struct->mapcpy[j][i] != ' ')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
