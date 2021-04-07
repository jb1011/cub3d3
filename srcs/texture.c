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

void    get_text(my_struct_t *s)
{
    if (!(s->texture[0].img = mlx_xpm_file_to_image(s->mlx_ptr, s->no, &(s->texture[0].width), &(s->texture[0].height))))
        printf("Error\nproblem with texture\n");
    s->texture[0].addr = (int *)mlx_get_data_addr(s->texture[0].img, &s->texture[0].bpp, &s->texture[0].line_height, &s->texture[0].endian);

    if (!(s->texture[1].img = mlx_xpm_file_to_image(s->mlx_ptr, s->so, &(s->texture[1].width), &(s->texture[1].height))))
        printf("Error\nproblem with texture\n");
    s->texture[1].addr = (int *)mlx_get_data_addr(s->texture[1].img, &s->texture[1].bpp, &s->texture[1].line_height, &s->texture[1].endian);

    if (!(s->texture[2].img = mlx_xpm_file_to_image(s->mlx_ptr, s->we, &(s->texture[2].width), &(s->texture[2].height))))
        printf("Error\nproblem with texture\n");
    s->texture[2].addr = (int *)mlx_get_data_addr(s->texture[2].img, &s->texture[2].bpp, &s->texture[2].line_height, &s->texture[2].endian);

    if (!(s->texture[3].img = mlx_xpm_file_to_image(s->mlx_ptr, s->ea, &(s->texture[3].width), &(s->texture[3].height))))
        printf("Error\nproblem with texture\n");
    s->texture[3].addr = (int *)mlx_get_data_addr(s->texture[3].img, &s->texture[3].bpp, &s->texture[3].line_height, &s->texture[3].endian);

    if (!(s->texture[4].img = mlx_xpm_file_to_image(s->mlx_ptr, s->s, &(s->texture[4].width), &(s->texture[4].height))))
        printf("Error\nproblem with texture\n");
    s->texture[4].addr = (int *)mlx_get_data_addr(s->texture[4].img, &s->texture[4].bpp, &s->texture[4].line_height, &s->texture[4].endian);
}
