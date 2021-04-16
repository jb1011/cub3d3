/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 14:02:26 by jdemenet          #+#    #+#             */
/*   Updated: 2021/04/07 14:02:40 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Include/cub3d.h"

void	ft_init_my_struct(t_struct_t *my_struct)
{
	my_struct->x = 0;
	my_struct->y = 0;
	my_struct->width = -1;
	my_struct->height = -1;
	my_struct->f_r = -1;
	my_struct->f_g = -1;
	my_struct->f_b = -1;
	my_struct->mlx_ptr = NULL;
	my_struct->win_ptr = NULL;
	my_struct->last_columns = 0;
	my_struct->spawn.x = 0;
	my_struct->spawn.y = 0;
	my_struct->bpp = 0;
	my_struct->size_line = 0;
	my_struct->endian = 0;
	my_struct->error = 0;
	my_struct->result_map = 0;
	my_struct->sizex = 0;
	my_struct->sizey = 0;
	ft_init_2(my_struct);
}

void	ft_init_2(t_struct_t *my_struct)
{
	my_struct->sp.spriteheight = 0;
	my_struct->sp.spritescreenx = 0;
	my_struct->sp.drawstartx = 0;
	my_struct->sp.drawstarty = 0;
	my_struct->sp.drawendx = 0;
	my_struct->sp.drawendy = 0;
	my_struct->sp.spritewidth = 0;
	my_struct->s = NULL;
	my_struct->sp.zbuffer = 0;
	my_struct->c = NULL;
	my_struct->sp.zbuffer = 0;
	my_struct->sp.order = 0;
	my_struct->sp.dist = 0;
	my_struct->map = NULL;
	my_struct->sidehits = 0;
	my_struct->starts = 0;
	my_struct->lines = 0;
	my_struct->no = NULL;
	my_struct->so = NULL;
	my_struct->we = NULL;
	my_struct->ea = NULL;
	my_struct->colortab = 0;
	my_struct->save = NULL;
}

void	ft_init_struct_check_error(t_check_error_t *check_error)
{
	check_error->result = 0;
	check_error->count = 0;
	check_error->s = NULL;
	check_error->r = NULL;
	check_error->no = NULL;
	check_error->so = NULL;
	check_error->we = NULL;
	check_error->ea = NULL;
	check_error->f = NULL;
	check_error->c = NULL;
	check_error->tab = NULL;
	check_error->tab2 = NULL;
	check_error->tab3 = NULL;
	check_error->tab4 = NULL;
	check_error->tab5 = NULL;
	check_error->tab6 = NULL;
	check_error->tab7 = NULL;
	check_error->tab8 = NULL;
}

int		main(int argc, char **argv)
{
	t_struct_t		my_struct;
	t_check_error_t	checker;

	my_struct.saved = 0;
	if (argc > 3 || argc < 2)
		printf("Error\nwrong number of argument\n");
	else
		ft_main2(&checker, &my_struct, argc, argv);
}

void	ft_main2(t_check_error_t *checker, t_struct_t *my_struct,
			int argc, char **argv)
{
	my_struct->doc = argv[1];
	if (ft_check_cub(my_struct) == 0)
		return ;
	if (argc == 3 && ft_strcmp(argv[2], "--save") == 0)
	{
		my_struct->saved = 1;
		my_struct->save = argv[2];
		ft_init_struct_check_error(checker);
		ft_init_my_struct(my_struct);
		ft_caller(my_struct, checker);
	}
	else if (argc == 3 && ft_strcmp(argv[2], "--save") != 0)
	{
		ft_putstr_fd("Error\ntypo in --save", 0);
		return ;
	}
	else if (argc == 2)
	{
		my_struct->saved = 0;
		ft_init_struct_check_error(checker);
		ft_init_my_struct(my_struct);
		ft_caller(my_struct, checker);
	}
	else
		ft_putstr_fd("Error\nwrong map file", 0);
}
