/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:15:00 by jdemenet          #+#    #+#             */
/*   Updated: 2021/04/07 14:15:02 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

void	ft_ceiling_util(t_check_error_t *checker)
{
	char *tmp;

	tmp = ft_strtrim(checker->c, "C ");
	free(checker->c);
	checker->c = ft_strdup(tmp);
	free(tmp);
	checker->tab3 = ft_split(checker->c, ',');
	if (ft_commas(checker->c) == 0)
	{
		checker->result -= 1;
		printf("Error\ntoo many commas in ceiling\n");
	}
}

void	check_error_util(char *str, t_check_error_t *checker)
{
	if (str[0] == 'F')
		checker->f = ft_strdup(str);
	else if (str[0] == 'C')
		checker->c = ft_strdup(str);
	else if (str[0] == 0)
		checker->count--;
}

void	ft_freee22(t_struct_t *s)
{
	if (s->colortab)
		ft_free_double_pointer_int(s);
	if (s->sidehits)
		free(s->sidehits);
	if (s->starts)
		free(s->starts);
	if (s->lines)
		free(s->lines);
}

void	ft_create_image(t_struct_t *s)
{
	s->x = 0;
	s->y = 0;
	s->img_ptr = mlx_new_image(s->mlx_ptr, s->width, s->height);
	s->img_data = (int *)mlx_get_data_addr(s->img_ptr, &s->bpp,
		&s->size_line, &s->endian);
}

void	key_more_more(int key, t_struct_t *s)
{
	if (key == ROTATE_RIGHT)
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
}
