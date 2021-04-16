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
	printf("Error\ntoo many commas in floor\n");
}

int		ft_check_cub(t_struct_t *s)
{
	int i;

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