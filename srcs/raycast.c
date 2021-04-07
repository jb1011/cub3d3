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

void    init_t_ray(my_struct_t *s)
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

void    init_dir(my_struct_t *s)
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
	else if (s->spawn.type == 'E')
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

int	ft_raycaster(my_struct_t *s)
{
	int i;

	i = 0;
	s->rayx = 0;
	while (s->rayx < s->width)
	{
		s->drawend = 0;
		s->drawstart = 0;
		s->hit = 0;
		
		s->camerax = 2 * s->rayx / (double)s->width - 1;
		s->raydirx = s->dirx + s->planx * s->camerax;
		s->raydiry = s->diry + s->plany * s->camerax;

		s->mapx = (int)s->posx;
		s->mapy = (int)s->posy;

		s->deltadistx = sqrt(1 + (s->raydiry * s->raydiry) / (s->raydirx * s->raydirx));
		s->deltadisty = sqrt(1 + (s->raydirx * s->raydirx) / (s->raydiry * s->raydiry));

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
			s->perpwalldist = (s->mapx - s->posx + (1 - s->stepx) / 2) / s->raydirx;
		else
			s->perpwalldist = (s->mapy - s->posy + (1 - s->stepy) / 2) / s->raydiry;
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

		//texture
		if (s->side == 0 && s->raydirx < 0)
			s->tnum = 0;
		if (s->side == 0 && s->raydirx > 0)
			s->tnum = 1;
		if (s->side == 1 &&  s->raydiry < 0)
			s->tnum = 2;
		if (s->side == 1 && s->raydiry > 0)
			s->tnum = 3;
		if (s->side == 0)
			s->t.wallx = s->posy + s->perpwalldist * s->raydiry;
		else
			s->t.wallx = s->posx + s->perpwalldist * s->raydirx;
		s->t.wallx -= floor(s->t.wallx);
		s->t.texx = s->texture[s->tnum].width - s->t.texx - 1;
		s->t.texx = (int)(s->t.wallx * (double)s->texture[s->tnum].width);
		s->t.step = 1.0 * s->texture[s->tnum].height / s->lineheight;
		s->t.texpos = (s->drawstart - s->height / 2 + s->lineheight / 2) * s->t.step;
		int g = s->drawstart;
		int j = 0;
		while (g < s->drawend)
		{
			s->t.texy = (int)s->t.texpos & (s->texture[s->tnum].height -1);
			s->t.texpos += s->t.step;
			s->t.color = s->texture[s->tnum].addr[s->t.texy * s->texture[s->tnum].line_height / 4 + s->t.texx];
			if (s->side == 1)
				s->t.color = (s->t.color >> 1) & 8355711;
			s->colortab[j][s->rayx] = s->t.color;
			g++;
			j++;
		}
		
		s->rayx++;
	}
	s->lines[s->rayx] = 0;
	s->starts[s->rayx] = 0;
	s->sidehits[s->rayx] = 0;
	ft_wall(s);
	return (1);
}

void	init_num_text(my_struct_t *s)
{
	if (s->side == 0 && s->raydirx < 0)
		s->tnum = 0;
	if (s->side == 0 && s->raydirx >= 0)
		s->tnum = 1;
	if (s->side == 1 && s->raydirx < 0)
		s->tnum = 2;
	if (s->side == 1 && s->raydirx >= 0)
		s->tnum = 3;
	if (s->side == 0)
		s->wallx = s->posy + s->perpwalldist * s->raydiry;
	else
		s->wallx = s->posx + s->perpwalldist * s->raydirx;
	s->wallx -= floor(s->wallx);
}


// void	put_text_col(my_struct_t *s)
// {
// 	int i;
// 	int j;
// 	j = -1;
// 	s->drawend = s->height - s->drawstart;
// 	i = s->drawend;
// 	//PEUT ETRE UN PB AVEC LE X QUON DONNE EN PARAMETRE
// 	while (++j < s->drawstart)
// 		s->img_data[j * s->size_line / 4 + s->rayx] = -1;
// 	if (j <= s->drawend)
// 		draw_text(s, s->rayx, j);
// 	j = i;
// 	while (++j < s->height)
// 		s->img_data[j * s->size_line / 4 + s->rayx] = -1;
// }

// void	draw_text(my_struct_t *s, int x, int y)
// {
// 	y = s->drawstart - 1;
// 	init_text(s);
// 	s->step = 1.0 * s->texture[0].height / s->lineheight;
// 	s->texx = (int)(s->wallx * (double)s->texture[s->texdir].width);
// 	if (s->side == 0 && s->raydirx > 0)
// 		s->texx = s->texture[s->texdir].width - s->texx - 1;
// 	if (s->side == 1 && s->raydiry < 0)
// 		s->texx = s->texture[s->texdir].width - s->texx - 1;
// 	s->texpos = (s->drawstart - s->height / 2 + s->lineheight / 2) * s->step;
// 	while (++y <= s->drawend)
// 	{
// 		s->texy = (int)s->texpos & (s->texture[s->texdir].height - 1);
// 		s->texpos += s->step;
// 		if (y < s->height && x < s->width)
// 			s->img_data[y + s->size_line / 4 + x] = s->texture[s->texdir].addr[s->texy * s->texture[s->texdir].line_height / 4 + s->texx];
// 	}
	
// }

