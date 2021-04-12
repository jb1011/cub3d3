/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 10:17:04 by jdemenet          #+#    #+#             */
/*   Updated: 2021/04/08 10:17:06 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

void    ft_header(t_struct_t *s, int fd)
{
    int tmp;

    write(fd, "BM", 2);
    tmp = 14 + 40 + 4 * s->width * s->height;
    write(fd, &tmp, 4);
	tmp = 0;
	write(fd, &tmp, 2);
	write(fd, &tmp, 2);
	tmp = 54;
	write(fd, &tmp, 4);
	tmp = 40;
	write(fd, &tmp, 4);
	write(fd, &s->width, 4);
	write(fd, &s->height, 4);
	tmp = 1;
	write(fd, &tmp, 2);
	write(fd, &s->bpp, 2);
	tmp = 0;
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
	write(fd, &tmp, 4);
}

void    ft_save(t_struct_t *s)
{
    int fd;
    int x;
    int y;

    y = s->height;
    if ((fd = open("./image.bmp", O_CREAT | O_RDWR)) == -1)
        ft_putstr_fd("Error\nwith bmp file", 0);
    ft_header(s, fd);
    
    while (y >= 0)
    {
        x = 0;
        while (x < s->width)
        {
            write(fd, &s->img_data[y * s->size_line / 4 + x], 4);
            x++;
        }
        y--;
    }
    system("chmod 777 image.bmp");
}
