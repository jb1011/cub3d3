/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:05:10 by jdemenet          #+#    #+#             */
/*   Updated: 2021/04/07 14:05:11 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

void	ft_map_line_check(t_struct_t *my_struct, t_check_map_t *map_checker)
{
	int j;
	int k;

	j = 0;
	while (j < my_struct->last_columns)
	{
		k = 0;
		if (my_struct->map[j][k] != '1' && my_struct->map[j][k] != ' ')
			ft_put_less(my_struct, map_checker);
		j++;
	}
	j = 0;
	while (j < my_struct->last_columns)
	{
		k = ft_strlen(my_struct->map[j]) - 1;
		if (my_struct->map[j][k] != '1' && my_struct->map[j][k] != ' ')
			ft_put_less(my_struct, map_checker);
		j++;
	}
	if (my_struct->result_map == 0)
		ft_map_check_validity(my_struct);
	else
		ft_putstr_fd("Error\nwith map\n", 0);
}

void	ft_put_less(t_struct_t *my_struct, t_check_map_t *map_checker)
{
	map_checker->result_map--;
	my_struct->result_map--;
}

void	check_validity_2(t_struct_t *my_struct, int i, int j, int res)
{
	if (ft_check_for_spawn(my_struct) && ft_check_right_spawn(my_struct)
		&& ft_check_garbage(my_struct))
	{
		if (ft_check_for_spaces(my_struct) == 1)
		{
			while (j < my_struct->last_columns)
			{
				i = 1;
				while (my_struct->map[j][i] == ' ' ||
					my_struct->map[j][i] == '1')
					i++;
				res = ft_strlen(my_struct->map[j]) - 1;
				while (i < res)
				{
					check_utilss(my_struct, i, j);
					i++;
				}
				j++;
			}
		}
		else
			printf("Error\nSpaces in map\n");
	}
	else
		printf("Error\nwith spawn\n");
}

void	ft_map_check_left(t_struct_t *my_struct, int i, int j)
{
	int x;
	int y;

	y = j;
	x = i;
	while (x >= 0)
	{
		if (my_struct->mapcpyleft[y][x] == '1' ||
				my_struct->mapcpyleft[y][x] == 'X')
			my_struct->mapcpyleft[j][i] = 'X';
		x--;
	}
}

void	ft_map_check_up(t_struct_t *my_struct, int i, int j)
{
	int x;
	int y;

	y = j;
	x = i;
	while (y >= 0)
	{
		if ((size_t)x < ft_strlen(my_struct->mapcpyup[y]))
		{
			if (my_struct->mapcpyup[y][x] == '1' ||
					my_struct->mapcpyup[y][x] == 'X')
				my_struct->mapcpyup[j][i] = 'X';
		}
		y--;
	}
}
