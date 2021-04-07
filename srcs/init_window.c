/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:05:02 by jdemenet          #+#    #+#             */
/*   Updated: 2021/04/07 14:05:04 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

void	window_init(my_struct_t *s)
{
	s->mlx_ptr = mlx_init();
	mlx_get_screen_size(s->mlx_ptr, &s->sizex, &s->sizey);
	if (s->width > s->sizex || s->width > 100000)
		s->width = s->sizex;
	if (s->height > s->sizey || s->height > 100000)
		s->height = s->sizey;
	s->win_ptr = mlx_new_window(s->mlx_ptr, s->width, s->height, "Hell");
	replace_spawn(s);
	ft_rgbconv(s);
	init_t_ray(s);
	
	init_dir(s);
	get_text(s);

	ft_init_sprite(s);
	mlx_hook(s->win_ptr, 33, 1L << 17, ft_exit, s);
	
	mlx_hook(s->win_ptr, 2, 1L << 0, deal_key, s);
	mlx_loop_hook(s->mlx_ptr, ft_raycaster, s);
	mlx_loop(s->mlx_ptr);
}



void	replace_spawn(my_struct_t *s)
{
	int i;
	int j;

	j = 0;
	while (s->map[j])
	{
		i = 0;
		while (s->map[j][i])
		{
			if (s->map[j][i] == 'N' || s->map[j][i] == 'S' || s->map[j][i] == 'E' || s->map[j][i] == 'W')
			{
				s->spawn.type = s->map[j][i];
				s->spawn.x = i;
				s->spawn.y = j;
				s->map[j][i] = '0';
			}
			i++;
		}
		j++;
	}
}

void	ft_create_image(my_struct_t *s)
{
	s->x = 0;
	s->y = 0;
	s->img_ptr = mlx_new_image(s->mlx_ptr, s->width, s->height);
	s->img_data = (int *)mlx_get_data_addr(s->img_ptr, &s->bpp, &s->size_line, &s->endian);
}



int	deal_key(int key, my_struct_t *s)
{
	if (key == FORWARD)
	{
		if ((s->map[(int)(s->posx + s->dirx * SPEED)][(int)s->posy] == '0') || (s->map[(int)(s->posx + s->dirx * SPEED)][(int)s->posy] == '2'))
			s->posx += s->dirx * SPEED;
		if ((s->map[(int)s->posx][(int)(s->posy + s->diry * SPEED)] == '0') || (s->map[(int)s->posx][(int)(s->posy + s->diry * SPEED)] == '2'))
			s->posy += s->diry * SPEED;
	}
	else if (key == BACK)
	{
		if ((s->map[(int)(s->posx - s->dirx * SPEED)][(int)(s->posy)] == '0') || (s->map[(int)(s->posx - s->dirx * SPEED)][(int)(s->posy)] == '2'))
			s->posx -= s->dirx * SPEED;
		if ((s->map[(int)(s->posx)][(int)(s->posy - s->diry * SPEED)] == '0') || (s->map[(int)(s->posx)][(int)(s->posy - s->diry * SPEED)] == '2'))
			s->posy -= s->diry * SPEED;
	}
	else if (key == RIGHT)
	{
		if (s->map[(int)(s->posx)][(int)(s->posy + s->dirx * SPEED)] == '0')
			s->posy -= s->dirx * SPEED;
		if (s->map[(int)(s->posx + s->diry *SPEED)][(int)(s->posy)] == '0')
			s->posx += s->diry * SPEED;
	}
	else if (key == LEFT)
	{
		if (s->map[(int)(s->posx)][(int)(s->posy - s->dirx * SPEED)] == '0')
			s->posy += s->dirx * SPEED;
		if (s->map[(int)(s->posx - s->diry *SPEED)][(int)(s->posy)] == '0')
			s->posx -= s->diry * SPEED;	
	}
	else if (key == ROTATE_RIGHT)
	{
		s->olddirx = s->dirx;
		s->dirx = s->dirx * cos(-ROTSPEED) - s->diry * sin(-ROTSPEED);
		s->diry = s->olddirx * sin(-ROTSPEED) + s->diry * cos(-ROTSPEED);
		s->oldplanx = s->planx;
		s->planx = s->planx * cos(-ROTSPEED) - s->plany * sin(-ROTSPEED);
		s->plany = s->oldplanx * sin(-ROTSPEED) + s->plany * cos(-ROTSPEED);
	}
	else if (key == ROTATE_LEFT)
	{
		s->olddirx = s->dirx;
		s->dirx = s->dirx * cos(ROTSPEED) - s->diry * sin(ROTSPEED);
		s->diry = s->olddirx * sin(ROTSPEED) + s->diry * cos(ROTSPEED);
		s->oldplanx = s->planx;
		s->planx = s->planx * cos(ROTSPEED) - s->plany * sin(ROTSPEED);
		s->plany = s->oldplanx * sin(ROTSPEED) + s->plany * cos(ROTSPEED);
	}
	if (key == ESCAPE)
		ft_exit(s);
	return (0);
}

int	ft_exit(my_struct_t *s)
{
	ft_free_s(s);
	if (s->texture[0].img)
		mlx_destroy_image(s->mlx_ptr, s->texture[0].img);
	if (s->texture[1].img)
		mlx_destroy_image(s->mlx_ptr, s->texture[1].img);
	if (s->texture[2].img)
		mlx_destroy_image(s->mlx_ptr, s->texture[2].img);
	if (s->texture[3].img)
		mlx_destroy_image(s->mlx_ptr, s->texture[3].img);
	if (s->texture[4].img)
		mlx_destroy_image(s->mlx_ptr, s->texture[4].img);
	mlx_destroy_display(s->mlx_ptr);
	mlx_destroy_window(s->mlx_ptr, s->win_ptr);
	exit(0);
}

void	ft_wall(my_struct_t *s)
{
	int i;
	int j;
	int k;
	int color;

	i = 0;
	s->x = 0;
	ft_create_image(s);
	while (i < s->width)
	{

		j = 0;
		s->y = 0;
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
		s->x++;
		i++;
	}
	ft_sprite(s);
	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, 0, 0);
	mlx_destroy_image(s->mlx_ptr, s->img_ptr);
}

void	put_pixel(my_struct_t *s, int x, int y, int color)
{
	s->img_data[x * 4 + 4 * s->width * y] = color;
}

// void	ft_fill_image(my_struct_t *s)
// {
// 	int i;
// 	int j;
// 	int x;

// 	j = 0;
// 	s->x = 0;
// 	s->y = 0;
// 	while (s->map[j])
// 	{
// 		i = 0;
// 		x = 0;
// 		s->x = 0;
// 		while (s->map[j][i])
// 		{
// 			if (j == (int)s->posx && i == (int)s->posy)
// 				ft_fill_inside(s, 8);
// 			else if (s->map[j][i] == '1' || s->map[j][i] == '2')
// 				ft_fill_inside(s, 700);
// 			else if (s->map[j][i] == '0')
// 				ft_fill_inside(s, 1500);
// 			s->x += 10;
// 			i++;
// 			x++;

// 		}
// 		s->y += 10;
// 		j++;
// 	}
// 	mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, 0, 0);
// 	mlx_destroy_image(s->mlx_ptr, s->img_ptr);
// }




// void	ft_fill_inside(my_struct_t *s, int color)
// {
// 	int x;
// 	int tmpx;
// 	int y;
// 	int i;
// 	int j;

// 	tmpx = s->x;
// 	y = s->y;
// 	i = 0;
// 	j = 0;
// 	while (j < 10)
// 	{
// 		x = tmpx;
// 		i = 0;
// 		put_pixel(s, x, y,  color);
// 		while (i < 10)
// 		{
// 			put_pixel(s, x, y, color);
// 			x++;
// 			i++;
// 		}
// 		j++;
// 		y++;
// 	}
// }
