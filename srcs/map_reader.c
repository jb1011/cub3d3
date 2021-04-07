/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet@student.42.fr <jdemenet>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 13:08:31 by jdemenet          #+#    #+#             */
/*   Updated: 2021/03/31 14:51:18 by jdemenet@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

void	ft_caller(my_struct_t *my_struct, t_check_error_t *checker)
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

void	map_reader_check(my_struct_t *my_struct, int fd)
{
	t_check_map_t map_checker;

	ft_init_check_map(&map_checker);
	ft_map_malloc(my_struct, fd, &map_checker);
}

void	ft_map_malloc(my_struct_t *my_struct, int fd, t_check_map_t *checker)
{
	int		i;
	int		ret;
	char	*str;

	i = 1;
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		if (str[0] == '1' || str[0] == ' ' || str[0] == '0' || str[0] == '2')
			i++;
		else if (str[0] == 0)
		{
			printf("Error\nempty line in map\n");
			my_struct->error = 1;
		}
		free(str);
	}
	if (my_struct->error == 0)
	{
		if (str[0] == '1' || str[0] == ' ' || str[0] == '0' || str[0] == '2')
			i++;
		my_struct->last_columns = i - 1;
		my_struct->map = malloc(sizeof(char *) * (i + 1));
		my_struct->map[i] = 0;
		free(str);
		fd = open(my_struct->doc, O_RDONLY);
		i = 0;
		while ((ret = get_next_line(fd, &str)) > 0)
		{
			if (str[0] == '1' || str[0] == ' ' || str[0] == '0' || str[0] == '2')
			{
				my_struct->map[i] = ft_strdup(str);
				i++;
			}
			free(str);
		}
		if (str[0] == '1' || str[0] == ' ' || str[0] == '0' || str[0] == '2')
			my_struct->map[i] = ft_strdup(str);
		free(str);
		ft_check_error_map(my_struct, checker);
	}
	else
	{
		free(str);
		return ;
	}
}

void	ft_init_check_map(t_check_map_t *map_checker)
{
	map_checker->result_map = 0;
	map_checker->left_check = 0;
	map_checker->right_check = 0;
	map_checker->up_check = 0;
	map_checker->down_check = 0;
}

void	ft_check_error_map(my_struct_t *my_struct, t_check_map_t *map_checker)
{
	int i;

	i = 0;
	while (my_struct->map[0][i])
	{
		if (my_struct->map[0][i] != '1' && my_struct->map[0][i] != ' ')
		{
			printf("Error\nfirst line of map invalid\n");
			map_checker->result_map--;
			break ;
		}
		i++;
	}
	i = 0;
	while (my_struct->map[my_struct->last_columns][i])
	{
		if (my_struct->map[my_struct->last_columns][i] != '1' &&
			my_struct->map[my_struct->last_columns][i] != ' ')
		{
			printf("Error\nlast line of map invalid\n");
			map_checker->result_map--;
			break ;
		}
		i++;
	}
	ft_map_line_check(my_struct, map_checker);
}
