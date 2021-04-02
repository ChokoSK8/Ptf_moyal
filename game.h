/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 10:46:38 by abrun             #+#    #+#             */
/*   Updated: 2021/04/02 11:19:14 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H

# define GAME_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "../mlx.h"
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../printf/printf.h"

typedef struct		s_moves
{
	int		right;
	int		left;
	int		up;
	int		down;
	int		r_2;
	int		l_2;
	int		u_2;
	int		d_2;
}					t_moves;

typedef struct		s_line
{
	double		a;
	double		b;
	double		c;
}					t_line;

typedef struct		s_lines
{
	t_line	d;
	t_line	d_2;
}					t_lines;

typedef struct		s_eq
{
	double		a;
	double		b;
	double		c;
	double		d;
}					t_eq;

typedef struct		s_vector
{
	double		x;
	double		y;
}					t_vector;

typedef struct		s_vectors
{
	t_vector	v;
	t_vector	v_2;
}					t_vectors;

typedef struct		s_player
{
	t_vector	vec;
	int			len;
	int			angle;
	int			speed;
}					t_player;

typedef struct		s_img
{
	int			bpp;
	int			size_line;
	int			endian;
	char		*data;
	void		*image;
	int			width;
	int			height;
}					t_img;

typedef struct		s_map
{
	int		height;
	int		max_width;
	int		len_pix;
	int		dir;
	char	**map;
}					t_map;

typedef struct		s_wall
{
	int			height;
	int			width;
	int			n;
	t_img		img;
	int			h_min;
	double		coef;
	int			angle;
}					t_wall;

typedef struct		s_loc
{
	int		ret;
	int		x;
	int		y;
}					t_loc;

typedef struct		s_vect
{
	double		x;
	double		y;
	int			dir;
	int			cond;
	t_vector	sp;
	t_loc		loc;
}					t_vect;

typedef struct		s_walls
{
	t_wall		wall1;
	t_wall		wall2;
	t_wall		wall3;
	t_wall		wall4;
	t_wall		sprite;
}					t_walls;

typedef struct		s_param
{
	void		*mlx;
	void		*win;
	void		*win_map;
	t_img		img_map;
	int			height;
	int			width;
	int			max_w;
	int			max_h;
	int			d_max;
	t_walls		walls;
	t_wall		wall;
	t_player	hero;
	t_img		img;
	t_map		map;
	char		*no;
	char		*ea;
	char		*we;
	char		*so;
	char		*sp;
	char		*tab;
	int			*floor;
	int			*roof;
	int			checks[8];
	char		*cub;
	int			x;
	char		*save;
}					t_param;

typedef struct		s_point
{
	int		x;
	int		y;
	int		init;
}					t_point;

double				convert(double degre);

void				get_pt_a_hori(t_player hero, t_vect *pt_a,
		t_map map, double angle);

void				get_pt_a_hori_90(t_player hero, t_vect *pt_a,
		t_map map, double angle);

void				get_vector_hori(double angle, int len_pix, t_vector *vector);

int					is_wall_hori(t_vect pt, double angle, t_param param);

t_vect				get_pt_h(t_param param, t_map map, double angle);

void				get_pt_a_vert(t_player hero, t_vect *pt_a,
		t_map map, double angle);

void				get_pt_a_vert_90(t_player hero, t_vect *pt_a,
		t_map map, double angle);

void				get_vector_vert(double angle, int len_pix, t_vector *vector);

int					get_x(t_vect pt, double angle, t_param param);

t_loc				is_wall_vert(t_vect pt, double angle, t_param param);

t_vect				get_pt_v(t_param param, t_map map, double angle);

t_vect				get_dist_min(t_vect pt_h, t_vect pt_v,
		t_param *param, double angle);

void				get_dim(t_wall *wall, double dist, t_param *param, double angle);

double				get_d(t_player hero, t_vect pt_a, double counter);

double				get_angle_right(int angle_h, double counter);

void				dis_textures(t_wall wall, t_param *param, int pos_x);

void				draw_wall(t_wall wall, int pos_x,
		t_param *param, int color);

t_vect				get_pt_a_90(t_param *param, double angle);

double				get_distances(t_vect pt_h, t_vect pt_v, double *dist_h,
		t_param param);

void				display_multi_angle(t_param *param, int color);

int					move_hero(int key, t_param *param);

int					is_wall_around(t_player hero, t_img img);

int					is_wall_12(t_player hero, t_img img_map);

int					is_wall_6(t_player hero, t_img img_map);

void				move_key_12(t_player *hero, t_img img);

void				move_key_6(t_player *hero, t_img img);

size_t				get_height(char *tab);

size_t				get_max_width(char *tab);

size_t				get_length(char *tab);

int					fill_tabulation(char **map, int i, int *j);

char				*get_tab();

size_t				get_width(char *tab);

char				**get_map(char *tab, t_param *param);

int					loop_get_map(char *tab, char **map, int max_width, t_param *param);

int					init_map(t_map *map, char *tab, t_param *param);

int					get_dir(t_map map);

int					is_pos_hero(char **map);

void				init_img(t_img *img, t_param param);

void				init_hero(t_player *hero, t_map map);

void				init_wall1_img(t_wall *wall, t_param param);

void				init_wall2_img(t_wall *wall, t_param param);

void				init_wall3_img(t_wall *wall, t_param param);

void				init_wall4_img(t_wall *wall, t_param param);

void				init_sprite_img(t_wall *wall, t_param param);

void				put_xpm_to_final(char *data_final, char *data,
		int size_line, t_img img);

t_point				get_pos_hero(t_map map);

int					get_angle(t_map map);

int					init_param(t_param *param);

int					get_dist_max(t_map map);

void				init_checks(t_param *param);

void				display_map_case(t_map map, t_point	img_pt, t_param param);

void				display_map_empty_case(t_map map, t_point img_pt,
		t_param param);

void				display_map(t_map map, t_param param);

void				change_hero_pos(t_param param, int color);

void				display_pt_a(t_param param, int color, t_vect pt_a);

void				display_background(t_param param);

void				display_roof(t_param param, int height,
		int width, int size_line);

void				display_floor(t_param param, int height,
		int width, int size_line);

int					get_resolution(t_param *param, char *line);

int					check_resolution(int id, char *line);

int					fill_w_h(t_param *param, char *line, int id);

int					get_n(char *line);

int					get_param_cub(t_param *param, int fd);

int					get_no_path(t_param *param, char *line);

int					get_so_path(t_param *param, char *line);

int					get_we_path(t_param *param, char *line);

int					get_ea_path(t_param *param, char *line);

int					get_sp_path(t_param *param, char *line);

int					check_texture(char *id, char *line);

char				*get_element(int fd, t_param *param);

int					fill_param(t_param *param, char *line);

int					is_map(char *line);

int					fill_tab_map(char *line, int fd, char *tab, t_param *param);

int					get_color(char *line, t_param *param, int d);

int					fill_floor(t_param *param, int *tab);

int					fill_roof(t_param *param, int *tab);

int					*get_color_fill_tab(char *line);

int					check_color(int id, char *line);

int					check_all(int *checks, t_param *param);

void				free_param(t_param *param);

void				free_tab_checks(t_param *param);

void				free_map_param(t_param *param);

void				free_in_loop(t_param *param, int i, char **map);

void				get_pt_start(t_point *pt, char **map);

int					is_0_around(t_point pt, char **map, int max_w, int hei);

int					go_left(t_point pt, char **map, int max_w, int hei);

int					go_down(t_point pt, char **map, int max_w, int hei);

int					go_right(t_point pt, char **map, int max_w, int hei);

int					go_up(t_point pt, char **map, int max_w, int hei);

void				config_right(t_point *pt, t_moves *dir);

void				config_left(t_point *pt, t_moves *dir);

void				config_down(t_point *pt, t_moves *dir);

void				config_up(t_point *pt, t_moves *dir);

int					move_pt(t_point *pt, t_map map, t_point *end, t_moves *dir);

int					check_around(t_point pt, t_map map);

t_point				get_hero(char **map);

char				*get_final_data(t_img img, t_param param);

int					is_print_dist(t_loc loc, t_vector hero, t_vect pt, t_param param);

t_line				get_line_2_pts(t_vect pt_1, t_vector pt_2);

t_line				get_d_perpendicular(t_line d, t_vect pt);

double				get_angle_sprite(t_vector hero, t_vect cube);

double				conv_rad(double rad);

t_vector			get_end(t_line d, t_vect cen, double angle, t_vector *end_2);

t_vect				get_inter(t_line d_1, t_line d_2);

int					is_print(t_vect pt, t_vector end_1, t_vector end_2);

int					is_printable(t_vect pt, t_vector end_1, t_vector end_2, t_vect pt_a);

int					is_print_dist(t_loc loc, t_vector hero, t_vect pt, t_param param);

void				change_end_2(t_vector *e, t_vector d);

double				modulo(double x, int a);

t_line				get_d_angle_hero(t_player h, t_map map);

double				get_dist(t_vector pt, t_vect pt_2);

int					get_c(int wid);

void				get_pix(char *data, t_param *param, int size_line);

void				get_header(t_param *param);

int					ft_len(char *s);

char				*ft_convert_base(char *n, char *base_from, char *base_to);

long int			ft_pow_conv(long int nb, int power);

long int			ft_strstr_conv(char *str, char to_find);

int					mlx_get_screen_size(void *mlx_ptr, int *sizex, int *sizey);

int					get_loc_y(double angle, t_vect pt, t_param param);

t_vect				init_sp_cube_n(double *n, t_loc *sp, t_vect pt, t_param *param);

double				init_angle_ds(t_lines *ds, t_vect cube, t_param *param);

t_vect				get_pt_sprite(double angle, t_param param, t_map map);

int					loop_cond(int n_wall, int width, t_loc loc, t_loc sp);

double				display_sprite(int *n_wall, t_param *param,
				double counter, t_vect pt);

t_vect				get_inter(t_line d_1, t_line d_2);

int					is_print(t_vect pt, t_vector end_1, t_vector end_2);

double				conv_rad(double rad);

double				get_angle_sprite(t_vector hero, t_vect cube);

t_line				get_d_angle_hero(t_player hero, t_map map);

t_vector			get_end_270(t_vector end_1, t_vector *end_2);

t_vector			get_end_360(t_vector end_1, t_vector *end_2);

t_vector			get_end(t_line d, t_vect cen, double angle, t_vector *end_2);

t_line				get_d_perpendicular(t_line d, t_vect pt);

int					get_x_sprite(t_vector pt_1, t_vect pt_2);

void				change_end_2(t_vector *end_2, t_vector end_1);

t_eq				get_eq_end(t_line d, t_vect cen);

void				get_ends_end(t_eq eq, t_line d,
				t_vector *end_1, t_vector *end_2);
	
t_vector			get_end_90(t_vector end_1, t_vector *end_2);

t_vector			get_end_180(t_vector end_1, t_vector *end_2);

t_line				get_line_2_pts(t_vect pt_1, t_vector pt_2);

double				get_dist(t_vector pt_1, t_vect pt_2);

t_vector			get_end_spe_2(t_vect cube, double angle, t_vector *end_2);

t_vector			get_end_spe(t_vect cube, double angle, t_vector *end_2);

long int			ft_put_puissance_conv(long int n, unsigned int base);

char				*ft_putnbr_base_conv(long int n, char *b, int size, long int tab[2]);

int				ft_put_pui_save(int n, int l);

void				put_conv_in(char *s, char *h, int len, int j);

char				*putnbr_base(int n, char *b, int size);

void				fill_len_fic(char *h, t_param param);

void				fill_chp_res(char *h);

void				fill_offset(char *h);

void				fill_len_img(char *h);

void				fill_wid_hei(char *h, t_param param);

void				fill_n_plan(char *h);

void				fill_comp(char *h);

void				fill_n_oct(char *h);

void				get_resu(char *h, char *save);

int				get_save_len(t_param param);

void				fill_bit_per_pix(char *h);

int					check_spaces(char **map, int h);

int					is_one_around(char **map, int i, int j, int h);

int					check_map(t_map map);

int					is_surrounded(t_map map, int y, int x);

int					check_up_down(char **map, int i, int j, int height);

int					check_right_left(char **map, int i, int j);

int					check_cases(char **map);
#endif
