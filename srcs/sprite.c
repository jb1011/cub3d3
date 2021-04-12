/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:05:56 by jdemenet          #+#    #+#             */
/*   Updated: 2021/04/07 14:05:59 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

void	ft_calc(t_struct_t *s, int i)
{
	s->sp.spritex = s->c[s->sp.order[i]].x - s->posx;
	s->sp.spritey = s->c[s->sp.order[i]].y - s->posy;
	s->sp.invdet = 1.0 / (s->planx * s->diry -
			s->dirx * s->plany);
	s->sp.transformx = s->sp.invdet * (s->diry *
			s->sp.spritex - s->dirx * s->sp.spritey);
	s->sp.transformy = s->sp.invdet * (-s->plany *
			s->sp.spritex + s->planx * s->sp.spritey);
	s->sp.spritescreenx = (int)((s->width / 2) * (1 + s->sp.transformx
				/ s->sp.transformy));
	s->sp.spriteheight = abs((int)(s->height / (s->sp.transformy)));
	s->sp.drawstarty = -s->sp.spriteheight / 2 + s->height / 2;
	if (s->sp.drawstarty < 0)
		s->sp.drawstarty = 0;
	s->sp.drawendy = s->sp.spriteheight / 2 + s->height / 2;
	if (s->sp.drawendy >= s->height)
		s->sp.drawendy = s->height;
	s->sp.spritewidth = abs((int)(s->height / (s->sp.transformy)));
	s->sp.drawstartx = -s->sp.spritewidth / 2 + s->sp.spritescreenx;
	if (s->sp.drawstartx < 0)
		s->sp.drawstartx = 0;
	s->sp.drawendx = s->sp.spritewidth / 2 + s->sp.spritescreenx;
	if (s->sp.drawendx >= s->width)
		s->sp.drawendx = s->width;
}

void	ft_draw_spr(t_struct_t *s, int y, int texx, int stripe)
{
	int d;
	int texy;

	while (y < s->sp.drawendy)
	{
		d = (y) * 256 - s->height * 128 + s->sp.spriteheight * 128;
		texy = ((d * s->texture[4].height) / s->sp.spriteheight) / 256;
		if (s->texture[4].addr[texy * s->texture[4].line_height /
			4 + texx] != 0)
		{
			s->img_data[y * s->size_line / 4 + stripe] =
				s->texture[4].addr[texy * s->texture[4].line_height / 4 + texx];
		}
		y++;
	}
}

int		ft_sprite(t_struct_t *s)
{
	int i;
	int y;
	int stripe;
	int texx;

	i = -1;
	ft_dis_order(s);
	while (++i < s->sp.nbspr)
	{
		ft_calc(s, i);
		stripe = s->sp.drawstartx - 1;
		while (++stripe < s->sp.drawendx)
		{
			texx = (int)(256 * (stripe - (-s->sp.spritewidth / 2 +
			s->sp.spritescreenx)) * s->texture[4].width /
				s->sp.spritewidth) / 256;
			if (s->sp.transformy > 0 && stripe >= 0 && stripe < s->width &&
				s->sp.transformy < s->sp.zbuffer[stripe])
			{
				y = s->sp.drawstarty;
				ft_draw_spr(s, y, texx, stripe);
			}
		}
	}
	return (0);
}

int		ft_init_sprite(t_struct_t *s)
{
	int j;

	j = 0;
	s->sp.nbspr = 0;
	ft_count_2(s);
	if (!(s->c = (t_coord *)malloc(sizeof(t_coord) * s->sp.nbspr)))
		return (0);
	if (!(s->sp.order = (int *)malloc(sizeof(int) * s->sp.nbspr)))
		return (0);
	if (!(s->sp.dist = (double *)malloc(sizeof(double) * s->sp.nbspr)))
		return (0);
	ft_init_sprite2(s, 0, 0, 0);
	return (1);
}

void	ft_init_sprite2(t_struct_t *s, int i, int j, int v)
{
	while (s->map[j])
	{
		i = 0;
		while (s->map[j][i])
		{
			if (s->map[j][i] == '2')
			{
				s->c[v].y = (double)i + 0.5;
				s->c[v].x = (double)j + 0.5;
				v++;
			}
			i++;
		}
		j++;
	}
}
