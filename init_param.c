/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:36:29 by abrun             #+#    #+#             */
/*   Updated: 2021/04/02 11:16:39 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../game.h"

int			init_param(t_param *param)
{
	int		fd;

	param->mlx = mlx_init();
	param->max_w = 2000;
	param->max_h = 1000;
	init_checks(param);
	fd = open(param->cub, O_RDONLY);
	if (!get_param_cub(param, fd))
	{
		close(fd);
		return (0);
	}
	close(fd);
	init_wall1_img(&param->walls.wall1, *param);
	init_wall2_img(&param->walls.wall2, *param);
	init_wall3_img(&param->walls.wall3, *param);
	init_wall4_img(&param->walls.wall4, *param);
	init_sprite_img(&param->walls.sprite, *param);
	if (!(init_map(&param->map, param->tab, param)))
		return (0);
	param->d_max = get_dist_max(param->map);
	init_img(&param->img, *param);
	param->win = mlx_new_window(param->mlx, param->width,
			param->height, "Cub3D");
	init_hero(&param->hero, param->map);
	return (1);
}

void		init_img(t_img *img, t_param param)
{
	int		bpp;
	int		size_line;
	int		endian;
	void	*image;
	char	*img_data;

	image = mlx_new_image(param.mlx, param.width, param.height);
	img_data = mlx_get_data_addr(image, &bpp, &size_line, &endian);
	img->bpp = bpp;
	img->endian = endian;
	img->size_line = size_line;
	img->data = img_data;
	img->image = image;
}

int			init_map(t_map *map, char *tab, t_param *param)
{
	if (!(map->map = get_map(tab, param)))
		return (0);
	map->height = get_height(tab);
	map->max_width = get_max_width(tab);
	if (!is_pos_hero(map->map) || !check_spaces(map->map, map->height)
		|| !check_cases(map->map))
	{
		free_map_param(param);
		return (0);
	}
	if (!check_map(*map))
	{
		ft_putstr_fd("La map n'est pas fermée !\n", 1);
		free_map_param(param);
		return (0);
	}
	map->dir = get_dir(*map);
	map->len_pix = 32;
	free(tab);
	return (1);
}

void		init_hero(t_player *hero, t_map map)
{
	t_point		pt_h;

	pt_h = get_pos_hero(map);
	hero->angle = get_angle(map);
	hero->vec.x = (pt_h.x + 1) * map.len_pix - map.len_pix / 2;
	hero->vec.y = (pt_h.y + 1) * map.len_pix - map.len_pix / 2;
	hero->len = 2;
	hero->speed = 3;
}

void		init_checks(t_param *param)
{
	int		counter;

	counter = 0;
	while (counter < 8)
	{
		param->checks[counter] = 0;
		counter++;
	}
}
