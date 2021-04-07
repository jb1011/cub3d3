/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:03:49 by jdemenet          #+#    #+#             */
/*   Updated: 2021/04/07 14:03:53 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

void	ft_free_check_error(t_check_error_t *checker)
{
	if (checker->f)
		free(checker->f);
	if (checker->c)
		free(checker->c);
	if (checker->r)
		free(checker->r);
	if (checker->no)
		free(checker->no);
	if (checker->so)
		free(checker->so);
	if (checker->we)
		free(checker->we);
	if (checker->ea)
		free(checker->ea);
	if (checker->s)
		free(checker->s);
	if (checker->tab)
		ft_free_double_pointer(checker->tab);
	ft_freee(checker);
}

void	ft_freee(t_check_error_t *checker)
{
	if (checker->tab2)
		ft_free_double_pointer(checker->tab2);
	if (checker->tab3)
		ft_free_double_pointer(checker->tab3);
	if (checker->tab4)
		ft_free_double_pointer(checker->tab4);
	if (checker->tab5)
		ft_free_double_pointer(checker->tab5);
	if (checker->tab6)
		ft_free_double_pointer(checker->tab6);
	if (checker->tab7)
		ft_free_double_pointer(checker->tab7);
	if (checker->tab8)
		ft_free_double_pointer(checker->tab8);
}

void	ft_free_double_pointer(char **tab)
{
	int j;

	j = 0;
	while (tab[j])
	{
		free(tab[j]);
		j++;
	}
	free(tab);
}

void	ft_free_s(my_struct_t *s)
{
	if (s->no)
		free(s->no);
	if (s->so)
		free(s->so);
	if (s->we)
		free(s->we);
	if (s->ea)
		free(s->ea);
	if (s->s)
		free(s->s);
	if (s->sp.zbuffer)
		free(s->sp.zbuffer);
	if (s->c)
		free(s->c);
	if (s->sp.order)
		free(s->sp.order);
	if (s->sp.dist)
		free(s->sp.dist);
	if (s->map)
		ft_free_double_pointer(s->map);
	ft_freee22(s);
}

void	ft_free_double_pointer_int(my_struct_t *s)
{
	int n;

	n = 0;
	if (s->width >= s->height)
	{
		while (n < s->width)
		{
			free(s->colortab[n]);
			n++;
		}
	}
	else
	{
		while (n < s->height)
		{
			free(s->colortab[n]);
			n++;
		}
	}
	free(s->colortab);
	s->colortab = NULL;
}
