
#include "../Include/cub3d.h"

void	ft_map_line_check(my_struct_t *my_struct, t_check_map_t *map_checker)
{
	int j;
	int k;

	j = 0;
	while (j < my_struct->last_columns)
	{
		k = 0;
		if (my_struct->map[j][k] != '1' && my_struct->map[j][k] != ' ')
		{
			map_checker->result_map--;
			my_struct->result_map--;
		}
		j++;
	}
	j = 0;
	while (j < my_struct->last_columns)
	{
		k = ft_strlen(my_struct->map[j]) - 1;
		if (my_struct->map[j][k] != '1' && my_struct->map[j][k] != ' ')
		{
			map_checker->result_map--;
			my_struct->result_map--;
		}
		j++;
	}
	if (my_struct->result_map == 0)
		ft_map_check_validity(my_struct);
	else
		ft_putstr_fd("Error\nwith beginning or end of map", 0);
}

void	ft_map_check_validity(my_struct_t *my_struct)
{
	int	i;
	int	j;
	int	res;

	j = 1;
	my_struct->mapcpy = ft_tabcpy(my_struct->map);
	my_struct->mapcpyup = ft_tabcpy(my_struct->map);
	my_struct->mapcpydown = ft_tabcpy(my_struct->map);
	my_struct->mapcpyleft = ft_tabcpy(my_struct->map);
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
					ft_map_check_left(my_struct, i, j);
					ft_map_check_right(my_struct, i, j);
					ft_map_check_up(my_struct, i, j);
					ft_map_check_down(my_struct, i, j);
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
	if (ft_check_for_0(my_struct->mapcpy) &&
		ft_check_for_0(my_struct->mapcpydown)
			&& ft_check_for_0(my_struct->mapcpyup) &&
				ft_check_for_0(my_struct->mapcpyleft))
	{
		ft_free_double_pointer(my_struct->mapcpy);
		ft_free_double_pointer(my_struct->mapcpyup);
		ft_free_double_pointer(my_struct->mapcpydown);
		ft_free_double_pointer(my_struct->mapcpyleft);
	}
	else
	{
		my_struct->error += 1;
		ft_putstr_fd("Error\nwith map", 0);
		ft_free_double_pointer(my_struct->mapcpy);
		ft_free_double_pointer(my_struct->mapcpyup);
		ft_free_double_pointer(my_struct->mapcpydown);
		ft_free_double_pointer(my_struct->mapcpyleft);
	}
}

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

void	ft_map_check_left(my_struct_t *my_struct, int i, int j)
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

void	ft_map_check_up(my_struct_t *my_struct, int i, int j)
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
