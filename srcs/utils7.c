/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:15:38 by jdemenet          #+#    #+#             */
/*   Updated: 2021/04/16 11:15:40 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

void	ft_floor_utils(t_check_error_t *checker)
{
	checker->result -= 1;
	printf("Error\nproblem with commas in floor\n");
}

int		ft_check_cub(t_struct_t *s)
{
	int	i;

	i = 0;
	while (s->doc[i])
		i++;
	if (s->doc[i - 1] == 'b' && s->doc[i - 2] == 'u' && s->doc[i - 3] == 'c'
		&& s->doc[i - 4] == '.')
	{
		return (1);
	}
	else
		ft_putstr_fd("Error\nfile is not .cub", 0);
	return (0);
}

int		ft_check_xpm(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (s[i - 1] == 'm' && s[i - 2] == 'p' && s[i - 3] == 'x'
	&& s[i - 4] == '.')
		return (1);
	return (0);
}

void	ft_screen_res(t_struct_t *s)
{
	if (s->width > s->sizex || s->width > 100000)
		s->width = s->sizex;
	if (s->height > s->sizey || s->height > 100000)
		s->height = s->sizey;
}

void	ft_reader_malloc(t_struct_t *my_struct, char *str, int i,
							t_check_map_t *checker)
{
	if (my_struct->error == 0 && my_struct->ismap == 1)
	{
		ft_map_malloc_3(my_struct, i, str);
		ft_check_error_map(my_struct, checker);
	}
	else
	{
		my_struct->error = 1;
		free(str);
	}
}
