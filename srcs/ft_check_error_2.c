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

void	ft_check_path(t_check_error_t *checker, t_struct_t *my_struct)
{
	if (checker->no && checker->so && checker->we && checker->ea)
	{
		ft_check_path1(checker, my_struct);
		checker->tab6 = ft_split(checker->so, ' ');
		if (checker->tab6[1] && ft_check_xpm(checker->tab6[1]))
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
		printf("Error\nwith path\n");
}

void	ft_check_path1(t_check_error_t *checker, t_struct_t *my_struct)
{
	checker->tab4 = ft_split(checker->no, ' ');
	if (checker->tab4[1] && ft_check_xpm(checker->tab4[1]))
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

void	ft_check_path2(t_check_error_t *checker, t_struct_t *my_struct)
{
	checker->tab7 = ft_split(checker->we, ' ');
	if (checker->tab7[1] && ft_check_xpm(checker->tab7[1]))
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
	if (checker->tab8[1] && ft_check_xpm(checker->tab8[1]))
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

void	ft_check_path_s(t_check_error_t *checker, t_struct_t *my_struct)
{
	checker->tab5 = ft_split(checker->s, ' ');
	if (checker->tab5[1])
	{
		if (ft_check_xpm(checker->tab5[1]))
		{
			my_struct->s = ft_strdup(checker->tab5[1]);
			checker->result += 1;
		}
		else
			printf("Error\ninvalid path for S\n");
	}
	else
		printf("Error\ninvalid path for S\n");
}
