/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:47:09 by jdemenet          #+#    #+#             */
/*   Updated: 2021/04/07 15:47:11 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

void	ray1(t_struct_t *s)
{
	s->drawend = 0;
	s->drawstart = 0;
	s->hit = 0;
	s->camerax = 2 * s->rayx / (double)s->width - 1;
	s->raydirx = s->dirx + s->planx * s->camerax;
	s->raydiry = s->diry + s->plany * s->camerax;
	s->mapx = (int)s->posx + 0.5;
	s->mapy = (int)s->posy + 0.5;
	s->deltadistx = sqrt(1 + (s->raydiry * s->raydiry) /
								(s->raydirx * s->raydirx));
	s->deltadisty = sqrt(1 + (s->raydirx * s->raydirx) /
								(s->raydiry * s->raydiry));
	if (s->raydirx < 0)
	{
		s->stepx = -1;
		s->sidedistx = (s->posx - s->mapx) * s->deltadistx;
	}
	else
	{
		s->stepx = 1;
		s->sidedistx = (s->mapx + 1.0 - s->posx) * s->deltadistx;
	}
}

void	ray2(t_struct_t *s)
{
	while (s->hit == 0)
	{
		if (s->sidedistx < s->sidedisty)
		{
			s->sidedistx = s->sidedistx + s->deltadistx;
			s->mapx = s->mapx + s->stepx;
			s->side = 0;
		}
		else
		{
			s->sidedisty = s->sidedisty + s->deltadisty;
			s->mapy = s->mapy + s->stepy;
			s->side = 1;
		}
		if (s->map[s->mapx][s->mapy] == '1')
			s->hit = 1;
	}
	if (s->side == 0)
		s->perpwalldist = (s->mapx - s->posx +
						(1 - s->stepx) / 2) /
						s->raydirx;
	else
		s->perpwalldist = (s->mapy - s->posy +
						(1 - s->stepy) / 2) /
						s->raydiry;
}

void	ray3(t_struct_t *s)
{
	s->lineheight = (int)(s->height / s->perpwalldist);
	s->drawstart = -s->lineheight / 2 + s->height / 2;
	if (s->drawstart < 0)
		s->drawstart = 0;
	s->drawend = s->lineheight / 2 + s->height / 2;
	if (s->drawend >= s->height)
		s->drawend = s->height - 1;
	s->lines[s->rayx] = s->drawend;
	s->starts[s->rayx] = s->drawstart;
	s->sidehits[s->rayx] = s->side;
	s->sp.zbuffer[s->rayx] = s->perpwalldist;
	if (s->side == 0 && s->raydirx < 0)
		s->tnum = 0;
	if (s->side == 0 && s->raydirx > 0)
		s->tnum = 1;
	if (s->side == 1 && s->raydiry < 0)
		s->tnum = 2;
	if (s->side == 1 && s->raydiry > 0)
		s->tnum = 3;
	if (s->side == 0)
		s->t.wallx = s->posy + s->perpwalldist * s->raydiry;
	else
		s->t.wallx = s->posx + s->perpwalldist * s->raydirx;
}

void	ray4(t_struct_t *s)
{
	int g;
	int j;

	s->t.wallx -= floor(s->t.wallx);
	s->t.texx = s->texture[s->tnum].width - s->t.texx - 1;
	s->t.texx = (int)(s->t.wallx * (double)s->texture[s->tnum].width);
	s->t.step = 1.0 * s->texture[s->tnum].height / s->lineheight;
	s->t.texpos = (s->drawstart - s->height / 2 +
				s->lineheight / 2) *
				s->t.step;
	g = s->drawstart;
	j = 0;
	while (g < s->drawend)
	{
		s->t.texy = (int)s->t.texpos & (s->texture[s->tnum].height - 1);
		s->t.texpos += s->t.step;
		s->t.color = s->texture[s->tnum].addr[s->t.texy *
					s->texture[s->tnum].line_height / 4 +
						s->t.texx];
		if (s->side == 1)
			s->t.color = (s->t.color >> 1) & 8355711;
		s->colortab[j][s->rayx] = s->t.color;
		g++;
		j++;
	}
}
