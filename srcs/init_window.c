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

void	window_init(t_struct_t *s)
{
	s->mlx_ptr = mlx_init();
	mlx_get_screen_size(s->mlx_ptr, &s->sizex, &s->sizey);
	if (s->width > s->sizex || s->width > 100000)
		s->width = s->sizex;
	if (s->height > s->sizey || s->height > 100000)
		s->height = s->sizey;
	if (s->saved == 0)
		s->win_ptr = mlx_new_window(s->mlx_ptr, s->width, s->height, "Hell");
	replace_spawn(s);
	ft_rgbconv(s);
	init_t_ray(s);
	init_dir(s);
	get_text(s);
	ft_init_sprite(s);
	if (s->saved == 0)
	{
		mlx_hook(s->win_ptr, 33, 1L << 17, ft_exit2, s);
		mlx_hook(s->win_ptr, 2, 1L << 0, deal_key, s);
		mlx_loop_hook(s->mlx_ptr, ft_raycaster, s);
		mlx_loop(s->mlx_ptr);
	}
	else
	{
		ft_raycaster(s);
		exit(0);
	}
}

void	replace_spawn(t_struct_t *s)
{
	int i;
	int j;

	j = 0;
	while (s->map[j])
	{
		i = 0;
		while (s->map[j][i])
		{
			if (s->map[j][i] == 'N' || s->map[j][i] == 'S' ||
				s->map[j][i] == 'E' || s->map[j][i] == 'W')
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

int		deal_key(int key, t_struct_t *s)
{
	if (key == FORWARD)
	{
		if (s->map[(int)(s->posx + s->dirx * SPEED)][(int)s->posy] == '0')
			s->posx += s->dirx * SPEED;
		if (s->map[(int)s->posx][(int)(s->posy + s->diry * SPEED)] == '0')
			s->posy += s->diry * SPEED;
	}
	else if (key == BACK)
	{
		if (s->map[(int)(s->posx - s->dirx * SPEED)][(int)(s->posy)] == '0')
			s->posx -= s->dirx * SPEED;
		if (s->map[(int)(s->posx)][(int)(s->posy - s->diry * SPEED)] == '0')
			s->posy -= s->diry * SPEED;
	}
	key_more(key, s);
	ft_exit(s, key);
	return (0);
}

int		ft_exit(t_struct_t *s, int key)
{
	if (key == ESCAPE)
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
	return (0);
}

void	ft_wall(t_struct_t *s)
{
	int i;
	int j;
	int color;

	i = 0;
	s->x = 0;
	color = 0;
	ft_create_image(s);
	while (i < s->width)
	{
		j = 0;
		s->y = 0;
		ft_wall2(j, color, i, s);
		s->x++;
		i++;
	}
	ft_sprite(s);
	if (s->saved == 0)
		mlx_put_image_to_window(s->mlx_ptr, s->win_ptr, s->img_ptr, 0, 0);
	if (s->saved != 0)
		ft_save(s);
	mlx_destroy_image(s->mlx_ptr, s->img_ptr);
}
