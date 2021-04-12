/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdemenet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:39:58 by jdemenet          #+#    #+#             */
/*   Updated: 2021/04/12 11:40:00 by jdemenet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# define SPEED 0.1

# define ROTSPEED 0.1

# define ROTATE_LEFT 65361
# define ROTATE_RIGHT 65363
# define FORWARD 119
# define BACK 115
# define RIGHT 100
# define LEFT 97
# define ESCAPE 65307

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_spawn
{
	double		x;
	double		y;
	char		type;
}				t_spawn;

typedef struct	s_sprite
{
	int			nbspr;
	int			*order;
	double		*dist;
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			spriteheight;
	int			drawstartx;
	int			drawstarty;
	int			drawendy;
	int			drawendx;
	int			spritewidth;
	double		*zbuffer;
}				t_sprite;

typedef struct	s_coord
{
	double		x;
	double		y;
}				t_coord;

typedef struct	s_data
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img;
	int			*addr;
	int			width;
	int			height;
	int			bpp;
	int			line_height;
	int			endian;
}				t_data;

typedef struct	s_texture
{
	int			texdir;
	double		wallx;
	int			texx;
	int			texy;
	double		step;
	double		texpos;
	int			color;
}				t_texture;

typedef struct	s_struct_s
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	void		*mlx_ptr;
	void		*win_ptr;
	int			x;
	int			y;
	int			error;
	int			width;
	int			height;
	int			f_r;
	int			f_g;
	int			f_b;
	int			c_r;
	int			c_g;
	int			c_b;
	char		**map;
	char		**mapcpy;
	char		**mapcpyleft;
	char		**mapcpyup;
	char		**mapcpydown;
	int			last_columns;
	char		*doc;
	int			bpp;
	int			size_line;
	int			endian;
	void		*img_ptr;
	int			*img_data;
	int			result_map;
	int			sizex;
	int			sizey;
	int			*lines;
	int			*starts;
	int			*sidehits;
	int			hexac;
	int			hexaf;
	t_spawn		spawn;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	double		raydirx;
	double		raydiry;
	double		camerax;
	double		time;
	double		oldtime;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			rayx;
	double		olddirx;
	double		olddiry;
	double		oldplanx;
	double		oldplany;
	int			texdir;
	double		wallx;
	int			texx;
	int			texy;
	double		step;
	double		texpos;
	int			texnum;
	t_data		texture[5];
	t_texture	t;
	float		raydirx0;
	float		raydiry0;
	float		raydirx1;
	float		raydiry1;
	int			p;
	float		posz;
	float		rowdistance;
	float		floorstepx;
	float		floorstepy;
	float		floorx;
	float		floory;
	int			cellx;
	int			celly;
	int			tx;
	int			ty;
	int			**colortab;
	int			tnum;
	char		*save;
	int			saved;
	t_sprite	sp;
	t_coord		*c;
}				t_struct_t;

typedef struct	s_check_error_s
{
	char		*r;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*s;
	char		*f;
	char		*c;
	int			result;
	int			count;
	char		**tab;
	char		**tab2;
	char		**tab3;
	char		**tab4;
	char		**tab5;
	char		**tab6;
	char		**tab7;
	char		**tab8;
}				t_check_error_t;

typedef struct	s_check_map_s
{
	int			result_map;
	int			left_check;
	int			right_check;
	int			up_check;
	int			down_check;
}				t_check_map_t;

void			ft_caller(t_struct_t *my_struct, t_check_error_t *checker);
void			map_reader_check(t_struct_t *my_struct, int fd);
int				get_next_line(int fd, char **line);
void			pixel_put(char *str);
char			**ft_tabcpy(char **map);
int				ft_tablen(char **map);
void			ft_display_pixel(char *str, t_struct_t *my_struct);
void			ft_resolution(t_check_error_t *checker, t_struct_t *my_struct);
void			ft_check_error(t_struct_t *my_struct, t_check_error_t *checker,
					int fd);
void			ft_parser_error(t_check_error_t *checker,
					t_struct_t *my_struct);
void			ft_init_my_struct(t_struct_t *my_struct);
int				ft_count(char const *s, char c);
void			ft_floor_check(t_check_error_t *checker,
					t_struct_t *my_struct);
void			ft_ceiling_check(t_check_error_t *checker,
					t_struct_t *my_struct);
int				is_rgb(int i);
void			ft_init_struct_check_error(t_check_error_t *check_error);
int				ft_strcmp(char *s1, char *s2);
void			ft_check_path(t_check_error_t *checker, t_struct_t *my_struct);
void			ft_check_path_s(t_check_error_t *checker,
					t_struct_t *my_struct);
int				ft_path_compare(char *s1);
void			ft_map_malloc(t_struct_t *my_struct, int fd,
					t_check_map_t *checker);
void			ft_check_error_map(t_struct_t *my_struct,
					t_check_map_t *map_checker);
int				ft_tab_len(char **tab);
void			ft_map_opener(t_struct_t *my_struct);
void			ft_init_check_map(t_check_map_t *map_checker);
void			ft_map_line_check(t_struct_t *my_struct,
					t_check_map_t *map_checker);
void			ft_map_check_validity(t_struct_t *my_struct);
void			ft_map_check_left(t_struct_t *my_struct, int i, int j);
void			ft_map_check_right(t_struct_t *my_struct, int i, int j);
void			ft_map_check_up(t_struct_t *my_struct, int i, int j);
void			ft_map_check_down(t_struct_t *my_struct, int i, int j);
void			ft_display_map(char **tab);
int				ft_check_for_0(char **tab);
int				ft_check_for_spaces(t_struct_t *my_struct);
int				ft_check_right_spawn(t_struct_t *my_struct);
int				ft_check_for_spawn(t_struct_t *my_struct);
int				ft_check_garbage(t_struct_t *my_struct);
void			window_init(t_struct_t *s);
void			display_map(t_struct_t *s);
void			replace_spawn(t_struct_t *s);
void			ft_fill_inside(t_struct_t *s, int color);
void			ft_place_player(t_struct_t *s);
int				is_spawn(char c);
void			ft_create_image(t_struct_t *s);
void			ft_fill_image(t_struct_t *s);
void			put_pixel(t_struct_t *s, int x, int y, int color);
int				deal_key(int key, t_struct_t *s);
void			ft_free_check_error(t_check_error_t *checker);
void			ft_free_double_pointer(char **tab);
void			ray_manager(t_struct_t *s);
void			init_dir(t_struct_t *s);
void			init_t_ray(t_struct_t *s);
int				ft_raycaster(t_struct_t *s);
void			ft_wall(t_struct_t *s);
void			get_text(t_struct_t *s);
void			ft_raycast_floor(t_struct_t *s);
void			draw_text(t_struct_t *s, int x, int y);
void			init_num_text(t_struct_t *s);
void			put_text_col(t_struct_t *s);
int				raycast_manager(t_struct_t *s);
void			ft_rgbconv(t_struct_t *s);
void			ft_free_double_pointer_int(t_struct_t *s);
void			ft_free_s(t_struct_t *s);
void			ft_dis_order2(t_struct_t *s);
void			ft_dis_order(t_struct_t *s);
void			ft_calc(t_struct_t *s, int i);
int				ft_sprite(t_struct_t *s);
void			ft_count_2(t_struct_t *s);
int				ft_init_sprite(t_struct_t *s);
void			ft_init_sprite2(t_struct_t *s, int i, int j, int v);
int				ft_exit(t_struct_t *s);
void			init_colortab(t_struct_t *s);
void			ft_init_2(t_struct_t *my_struct);
void			ft_ceiling_util(t_check_error_t *checker);
void			check_error_util(char *str, t_check_error_t *checker);
void			ft_freee(t_check_error_t *checker);
void			ft_freee22(t_struct_t *s);
void			ft_check_path2(t_check_error_t *checker,
					t_struct_t *my_struct);
void			ft_check_path1(t_check_error_t *checker,
					t_struct_t *my_struct);
void			key_more(int key, t_struct_t *s);
void			key_more_more(int key, t_struct_t *s);
void			ft_wall2(int j, int color, int i, t_struct_t *s);
void			check_validity_2(t_struct_t *my_struct, int i, int j, int res);
void			check_utilss(t_struct_t *my_struct, int i, int j);
void			check_free(t_struct_t *my_struct);
void			ft_put_less(t_struct_t *my_struct, t_check_map_t *map_checker);
void			map_malloc2(t_struct_t *my_struct, int i, int fd, char *str);
void			ft_map_malloc_3(t_struct_t *my_struct, int i,
					int fd, char *str);
void			ray1(t_struct_t *s);
void			ray2(t_struct_t *s);
void			ray3(t_struct_t *s);
void			ray4(t_struct_t *s);
void			init_dir2(t_struct_t *s);
void			ft_save(t_struct_t *s);
void			ft_header(t_struct_t *s, int fd);
void			ft_main2(t_check_error_t *checker, t_struct_t *my_struct,
					int argc, char **argv);

#endif
