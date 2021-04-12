/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:44:17 by jdemenet          #+#    #+#             */
/*   Updated: 2021/04/07 14:44:21 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

void	key_more(int key, t_struct_t *s)
{
	if (key == RIGHT)
	{
		if (((s->map[(int)(s->posx)][(int)(s->posy + s->dirx * SPEED)] == '0')
		|| (s->map[(int)(s->posx)][(int)(s->posy + s->dirx * SPEED)] == '2'))
		&& (s->map[(int)(s->posx)][(int)(s->posy + 0.3 + s->dirx * SPEED)] != '1'))
			s->posy -= s->dirx * SPEED;
		if (((s->map[(int)(s->posx + s->diry * SPEED)][(int)(s->posy)] == '0')
		|| (s->map[(int)(s->posx + s->diry * SPEED)][(int)(s->posy)] == '2'))
		&& (s->map[(int)(s->posx + 0.3 + s->diry * SPEED)][(int)(s->posy)] != '1'))
			s->posx += s->diry * SPEED;
	}
	else if (key == LEFT)
	{
		if (((s->map[(int)(s->posx)][(int)(s->posy - s->dirx * SPEED)] == '0')
		|| (s->map[(int)(s->posx)][(int)(s->posy - s->dirx * SPEED)] == '2'))
		&& (s->map[(int)(s->posx)][(int)((s->posy - 0.3) - s->dirx * SPEED)] != '1'))
			s->posy += s->dirx * SPEED;
		if (((s->map[(int)(s->posx - s->diry * SPEED)][(int)(s->posy)] == '0')
		|| (s->map[(int)(s->posx - s->diry * SPEED)][(int)(s->posy)] == '2'))
		&& (s->map[(int)((s->posx - 0.3) - s->diry * SPEED)][(int)(s->posy)] != '1'))
			s->posx -= s->diry * SPEED;
	}
	key_more_more(key, s);
}

void	ft_wall2(int j, int color, int i, t_struct_t *s)
{
	int k;

	while (j < s->starts[i])
	{
		s->img_data[s->y * s->size_line / 4 + s->x] = s->hexac;
		s->y++;
		j++;
	}
	k = 0;
	while (j < s->lines[i] && j < s->height)
	{
		color = s->colortab[k][i];
		s->img_data[s->y * s->size_line / 4 + s->x] = color;
		s->y++;
		k++;
		j++;
	}
	while (j < s->height)
	{
		s->img_data[s->y * s->size_line / 4 + s->x] = s->hexaf;
		s->y++;
		j++;
	}
}

void	ft_map_check_validity(t_struct_t *my_struct)
{
	int	i;
	int	j;
	int	res;

	j = 1;
	i = 0;
	res = 0;
	my_struct->mapcpy = ft_tabcpy(my_struct->map);
	my_struct->mapcpyup = ft_tabcpy(my_struct->map);
	my_struct->mapcpydown = ft_tabcpy(my_struct->map);
	my_struct->mapcpyleft = ft_tabcpy(my_struct->map);
	check_validity_2(my_struct, i, j, res);
	if (ft_check_for_0(my_struct->mapcpy) &&
		ft_check_for_0(my_struct->mapcpydown)
			&& ft_check_for_0(my_struct->mapcpyup) &&
				ft_check_for_0(my_struct->mapcpyleft))
	{
		check_free(my_struct);
	}
	else
	{
		my_struct->error += 1;
		ft_putstr_fd("Error\nwith map\n", 0);
		check_free(my_struct);
	}
}

void	check_free(t_struct_t *my_struct)
{
	ft_free_double_pointer(my_struct->mapcpy);
	ft_free_double_pointer(my_struct->mapcpyup);
	ft_free_double_pointer(my_struct->mapcpydown);
	ft_free_double_pointer(my_struct->mapcpyleft);
}

void	check_utilss(t_struct_t *my_struct, int i, int j)
{
	ft_map_check_left(my_struct, i, j);
	ft_map_check_right(my_struct, i, j);
	ft_map_check_up(my_struct, i, j);
	ft_map_check_down(my_struct, i, j);
}
