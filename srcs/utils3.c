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

void	ft_freee22(my_struct_t *s)
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
