/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:05:47 by jdemenet          #+#    #+#             */
/*   Updated: 2021/04/07 14:05:48 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

void	init_t_ray(my_struct_t *s)
{
	s->rayx = 0;
	s->dirx = 0;
	s->diry = 0;
	s->time = 0;
	s->oldtime = 0;
	s->drawend = 0;
	s->drawstart = 0;
	s->hit = 0;
	s->camerax = 0;
	s->raydirx = 0;
	s->raydiry = 0;
	s->mapx = 0;
	s->mapy = 0;
	s->deltadistx = 0;
	s->deltadisty = 0;
	s->stepx = 0;
	s->stepy = 0;
	s->posx = (double)s->spawn.y;
	s->posy = (double)s->spawn.x;
	s->sp.zbuffer = (double *)malloc(sizeof(double) * s->width);
	init_colortab(s);
	s->lines = malloc(sizeof(int *) * s->width + 1);
	s->starts = malloc(sizeof(int *) * s->width + 1);
	s->sidehits = malloc(sizeof(int *) * s->width + 1);
}

void	init_colortab(my_struct_t *s)
{
	int i;

	i = 0;
	if (s->width >= s->height)
	{
		s->colortab = malloc(sizeof(int *) * s->width + 1);
		while (i < s->width)
		{
			s->colortab[i] = malloc(sizeof(int) * s->width);
			i++;
		}
	}
	else
	{
		s->colortab = malloc(sizeof(int *) * s->height + 1);
		while (i < s->height)
		{
			s->colortab[i] = malloc(sizeof(int) * s->height);
			i++;
		}
	}
}

void	init_dir(my_struct_t *s)
{
	if (s->spawn.type == 'N')
	{
		s->dirx = -1;
		s->diry = 0;
		s->planx = 0;
		s->plany = 0.66;
	}
	else if (s->spawn.type == 'S')
	{
		s->dirx = 1;
		s->diry = 0;
		s->planx = 0;
		s->plany = -0.66;
	}
	init_dir2(s);
}

void	init_dir2(my_struct_t *s)
{
	if (s->spawn.type == 'E')
	{
		s->dirx = 0;
		s->diry = 1;
		s->planx = 0.66;
		s->plany = 0;
	}
	else if (s->spawn.type == 'W')
	{
		s->dirx = 0;
		s->diry = -1;
		s->planx = -0.66;
		s->plany = 0;
	}
}

int		ft_raycaster(my_struct_t *s)
{
	s->rayx = 0;
	while (s->rayx < s->width)
	{
		ray1(s);
		if (s->raydiry < 0)
		{
			s->stepy = -1;
			s->sidedisty = (s->posy - s->mapy) * s->deltadisty;
		}
		else
		{
			s->stepy = 1;
			s->sidedisty = (s->mapy + 1.0 - s->posy) * s->deltadisty;
		}
		ray2(s);
		ray3(s);
		ray4(s);
		s->rayx++;
	}
	s->lines[s->rayx] = 0;
	s->starts[s->rayx] = 0;
	s->sidehits[s->rayx] = 0;
	ft_wall(s);
	return (1);
}
