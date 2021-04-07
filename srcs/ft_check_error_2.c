/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:04:00 by jdemenet          #+#    #+#             */
/*   Updated: 2021/04/07 14:04:02 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

void	ft_check_path(t_check_error_t *checker, my_struct_t *my_struct)
{
	if (checker->no && checker->so && checker->we && checker->ea)
	{
		ft_check_path1(checker, my_struct);
		checker->tab6 = ft_split(checker->so, ' ');
		if (ft_path_compare(checker->tab6[1]) == 1)
		{
			my_struct->so = ft_strdup(checker->tab6[1]);
			checker->result += 1;
		}
		else
		{
			my_struct->so = ft_strdup("");
			printf("Error\ninvalid path for SO\n");
		}
		ft_check_path2(checker, my_struct);
	}
	else
		printf("Error\npath missing\n");
}

void	ft_check_path1(t_check_error_t *checker, my_struct_t *my_struct)
{
	checker->tab4 = ft_split(checker->no, ' ');
	if (ft_path_compare(checker->tab4[1]) == 1)
	{
		my_struct->no = ft_strdup(checker->tab4[1]);
		checker->result += 1;
	}
	else
	{
		my_struct->no = ft_strdup("");
		printf("Error\ninvalid path for NO\n");
	}
}

void	ft_check_path2(t_check_error_t *checker, my_struct_t *my_struct)
{
	checker->tab7 = ft_split(checker->we, ' ');
	if (ft_path_compare(checker->tab7[1]) == 1)
	{
		my_struct->we = ft_strdup(checker->tab7[1]);
		checker->result += 1;
	}
	else
	{
		my_struct->we = ft_strdup("");
		printf("Error\ninvalid path for WE\n");
	}
	checker->tab8 = ft_split(checker->ea, ' ');
	if (ft_path_compare(checker->tab8[1]) == 1)
	{
		my_struct->ea = ft_strdup(checker->tab8[1]);
		checker->result += 1;
	}
	else
	{
		my_struct->ea = ft_strdup("");
		printf("Error\ninvalid path for EA\n");
	}
}

void	ft_check_path_s(t_check_error_t *checker, my_struct_t *my_struct)
{
	checker->tab5 = ft_split(checker->s, ' ');
	if (ft_strcmp("./textures/tonneau.xpm", checker->tab5[1]) == 0)
	{
		my_struct->s = ft_strdup(checker->tab5[1]);
		checker->result += 1;
	}
	else
		printf("Error\ninvalid path for S\n");
}
