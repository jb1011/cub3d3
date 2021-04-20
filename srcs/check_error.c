/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:03:33 by jdemenet          #+#    #+#             */
/*   Updated: 2021/04/07 14:03:36 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

void	ft_check_error(t_struct_t *my_struct, t_check_error_t *checker, int fd)
{
	int		ret;
	char	*str;

	while ((ret = get_next_line(fd, &str)) > 0)
	{
		if (str[0] == 'R' && !checker->r)
			checker->r = ft_strdup(str);
		else if (str[0] == 'N' && str[1] == 'O' && !checker->no)
			checker->no = ft_strdup(str);
		else if ((str[0] == 'S' && str[1] == 'O') && !checker->so)
			checker->so = ft_strdup(str);
		else if (str[0] == 'W' && str[1] == 'E' && !checker->we)
			checker->we = ft_strdup(str);
		else if (str[0] == 'E' && str[1] == 'A' && !checker->ea)
			checker->ea = ft_strdup(str);
		else if (str[0] == 'S' && !checker->s)
			checker->s = ft_strdup(str);
		check_error_util(str, checker);
		if (str[0] == '1' || str[0] == ' ')
			break ;
		checker->count++;
		free(str);
	}
	free(str);
	ft_parser_error(checker, my_struct);
}

void	ft_parser_error(t_check_error_t *checker, t_struct_t *my_struct)
{
	if (checker->r)
		ft_resolution(checker, my_struct);
	if (checker->f)
		ft_floor_check(checker, my_struct);
	if (checker->c)
		ft_ceiling_check(checker, my_struct);
	if (checker->no || checker->so || checker->we || checker->ea)
		ft_check_path(checker, my_struct);
	if (checker->s)
		ft_check_path_s(checker, my_struct);
}

void	ft_resolution(t_check_error_t *checker, t_struct_t *my_struct)
{
	if (checker->r[0] == 'R')
		checker->tab = ft_split(checker->r, ' ');
	if ((ft_count(checker->r, ' ')) != 3)
		printf("Error\nwrong number of arguments for resolution\n");
	else
	{
		my_struct->width = ft_atoi(checker->tab[1]);
		my_struct->height = ft_atoi(checker->tab[2]);
	}
	if (my_struct->width > 0 && my_struct->height > 0)
		checker->result += 1;
	else
		printf("Error\ninvalid resolution number\n");
}

void	ft_floor_check(t_check_error_t *checker, t_struct_t *my_struct)
{
	char *tmp;

	if (checker->f[0] == 'F')
	{
		tmp = ft_strtrim(checker->f, "F ");
		free(checker->f);
		checker->f = ft_strdup(tmp);
		free(tmp);
		checker->tab2 = ft_split(checker->f, ',');
	}
	if ((ft_count(checker->f, ',')) != 3)
		printf("Error\nwrong number of arguments for floor colors\n");
	else
	{
		my_struct->f_r = ft_atoi(checker->tab2[0]);
		my_struct->f_g = ft_atoi(checker->tab2[1]);
		my_struct->f_b = ft_atoi(checker->tab2[2]);
	}
	if (ft_commas(checker->f) == 0)
		ft_floor_utils(checker);
	if (is_rgb(my_struct->f_r) == 1 && is_rgb(my_struct->f_g) == 1 &&
			is_rgb(my_struct->f_b) == 1)
		checker->result += 1;
	else
		printf("Error\nfloor color is invalid\n");
}

void	ft_ceiling_check(t_check_error_t *checker, t_struct_t *my_struct)
{
	if (checker->c[0] == 'C')
	{
		ft_ceiling_util(checker);
	}
	if ((ft_count(checker->c, ',')) != 3)
	{
		checker->result -= 1;
		printf("Error\nwrong number of arguments for ceiling colors\n");
	}
	else
	{
		my_struct->c_r = ft_atoi(checker->tab3[0]);
		my_struct->c_g = ft_atoi(checker->tab3[1]);
		my_struct->c_b = ft_atoi(checker->tab3[2]);
	}
	if (is_rgb(my_struct->c_r) == 1 && is_rgb(my_struct->c_g) == 1 &&
		is_rgb(my_struct->c_b) == 1)
		checker->result += 1;
	else
	{
		checker->result -= 1;
		printf("Error\nceiling color is invalid\n");
	}
}
