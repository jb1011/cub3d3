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

void	ft_map_check_right(t_struct_t *my_struct, int i, int j)
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

void	map_malloc2(t_struct_t *my_struct, int i, char *str)
{
	int ret;
	int	fd;

	my_struct->last_columns = i - 1;
	my_struct->map = malloc(sizeof(char *) * (i + 1));
	my_struct->map[i] = 0;
	free(str);
	fd = open(my_struct->doc, O_RDONLY);
	i = 0;
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		if (str[0] == '1' || str[0] == ' ' ||
			str[0] == '0' || str[0] == '2')
		{
			my_struct->map[i] = ft_strdup(str);
			i++;
		}
		free(str);
	}
	if (str[0] == '1' || str[0] == ' ' || str[0] == '0' || str[0] == '2')
		my_struct->map[i] = ft_strdup(str);
	free(str);
}

void	ft_map_malloc_3(t_struct_t *my_struct, int i, char *str)
{
	if (str[0] == '1' || str[0] == ' ' || str[0] == '0' || str[0] == '2')
		i++;
	map_malloc2(my_struct, i, str);
}

void	ft_dis_order2(t_struct_t *s)
{
	int i;

	i = -1;
	while (++i < s->sp.nbspr)
	{
		s->sp.order[i] = i;
		s->sp.dist[i] = ((s->posx - s->c[i].x) *
				(s->posx - s->c[i].x) + (s->posy -
					s->c[i].y) * (s->posy - s->c[i].y));
	}
}

void	ft_dis_order(t_struct_t *s)
{
	int		i;
	double	tmp;
	int		j;

	ft_dis_order2(s);
	i = -1;
	while (++i < s->sp.nbspr)
	{
		j = -1;
		while (++j < s->sp.nbspr - 1)
		{
			if (s->sp.dist[j] < s->sp.dist[j + 1])
			{
				tmp = s->sp.dist[j];
				s->sp.dist[j] = s->sp.dist[j + 1];
				s->sp.dist[j + 1] = tmp;
				tmp = s->sp.order[j];
				s->sp.order[j] = s->sp.order[j + 1];
				s->sp.order[j + 1] = (int)tmp;
			}
		}
	}
}
