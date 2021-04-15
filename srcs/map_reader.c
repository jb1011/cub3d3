/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:05:39 by jdemenet          #+#    #+#             */
/*   Updated: 2021/04/07 14:05:41 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

void	ft_caller(t_struct_t *my_struct, t_check_error_t *checker)
{
	int fd;

	fd = open(my_struct->doc, O_RDONLY);
	ft_check_error(my_struct, checker, fd);
	if (checker->result == 8 && checker->count == 8)
	{
		map_reader_check(my_struct, fd);
		if (my_struct->error == 0 && my_struct->result_map == 0)
		{
			ft_free_check_error(checker);
			window_init(my_struct);
		}
		else
		{
			ft_free_check_error(checker);
			ft_free_s(my_struct);
		}
	}
	else
	{
		ft_free_check_error(checker);
		ft_free_s(my_struct);
	}
}

void	map_reader_check(t_struct_t *my_struct, int fd)
{
	t_check_map_t map_checker;

	ft_init_check_map(&map_checker);
	ft_map_malloc(my_struct, fd, &map_checker);
}

void	ft_map_malloc(t_struct_t *my_struct, int fd, t_check_map_t *checker)
{
	int		i;
	int		ret;
	char	*str;

	i = 1;
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		if (str[0] == '1' || str[0] == ' ' || str[0] == '0' || str[0] == '2')
			i++;
		else if (is_map(str[0]) == 0 || str[0] == 0)
			ft_call_f(my_struct);
		free(str);
	}
	if (is_map(str[0]) == 0)
	{
		printf("Error\nError in map\n");
		my_struct->error = 1;
	}
	if (my_struct->error == 0)
	{
		ft_map_malloc_3(my_struct, i, fd, str);
		ft_check_error_map(my_struct, checker);
	}
	else
		free(str);
}

void	ft_init_check_map(t_check_map_t *map_checker)
{
	map_checker->result_map = 0;
	map_checker->left_check = 0;
	map_checker->right_check = 0;
	map_checker->up_check = 0;
	map_checker->down_check = 0;
}

void	ft_check_error_map(t_struct_t *my_struct, t_check_map_t *map_checker)
{
	int i;

	i = -1;
	while (my_struct->map[0][++i])
	{
		if (my_struct->map[0][i] != '1' && my_struct->map[0][i] != ' ')
		{
			printf("Error\nfirst line of map invalid\n");
			map_checker->result_map--;
			break ;
		}
	}
	i = 0;
	while (my_struct->map[my_struct->last_columns][i])
	{
		if (my_struct->map[my_struct->last_columns][i] != '1' &&
			my_struct->map[my_struct->last_columns][i] != ' ')
		{
			printf("Error\nlast line of map invalid\n");
			ft_put_less(my_struct, map_checker);
			break ;
		}
		i++;
	}
	ft_map_line_check(my_struct, map_checker);
}
