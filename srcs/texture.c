/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:06:06 by jdemenet          #+#    #+#             */
/*   Updated: 2021/04/07 14:06:08 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

int		ft_exit1(t_struct_t *s)
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
	exit(0);
	return (0);
}

int		get_text(t_struct_t *s)
{
	if (!(s->texture[0].img = mlx_xpm_file_to_image(s->mlx_ptr, s->no,
		&(s->texture[0].width), &(s->texture[0].height))))
	{
		printf("Error\nproblem with texture 0\n");
		ft_exit1(s);
		return (0);
	}
	s->texture[0].addr = (int *)mlx_get_data_addr(s->texture[0].img,
		&s->texture[0].bpp, &s->texture[0].line_height, &s->texture[0].endian);
	if (!(s->texture[1].img = mlx_xpm_file_to_image(s->mlx_ptr, s->so,
		&(s->texture[1].width), &(s->texture[1].height))))
	{
		printf("Error\nproblem with texture 1\n");
		ft_exit1(s);
		return (0);
	}
	s->texture[1].addr = (int *)mlx_get_data_addr(s->texture[1].img,
		&s->texture[1].bpp, &s->texture[1].line_height, &s->texture[1].endian);
	if (!(s->texture[2].img = mlx_xpm_file_to_image(s->mlx_ptr, s->we,
		&(s->texture[2].width), &(s->texture[2].height))))
	{
		ft_exit1(s);
		return (0);
	}
	return (1);
}

int		get_text2(t_struct_t *s)
{
	s->texture[2].addr = (int *)mlx_get_data_addr(s->texture[2].img,
		&s->texture[2].bpp, &s->texture[2].line_height, &s->texture[2].endian);
	if (!(s->texture[3].img = mlx_xpm_file_to_image(s->mlx_ptr, s->ea,
		&(s->texture[3].width), &(s->texture[3].height))))
	{
		printf("Error\nproblem with texture 3\n");
		ft_exit1(s);
		return (0);
	}
	s->texture[3].addr = (int *)mlx_get_data_addr(s->texture[3].img,
		&s->texture[3].bpp, &s->texture[3].line_height, &s->texture[3].endian);
	if (!(s->texture[4].img = mlx_xpm_file_to_image(s->mlx_ptr, s->s,
		&(s->texture[4].width), &(s->texture[4].height))))
	{
		printf("Error\nproblem with texture 4\n");
		ft_exit1(s);
		return (0);
	}
	s->texture[4].addr = (int *)mlx_get_data_addr(s->texture[4].img,
		&s->texture[4].bpp, &s->texture[4].line_height, &s->texture[4].endian);
	return (1);
}
