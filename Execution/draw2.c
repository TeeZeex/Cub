/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:41:06 by tzhakypo          #+#    #+#             */
/*   Updated: 2024/06/15 00:46:30 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	dda(t_point x1, t_point x2, t_cub3d *game, int color)
{
	int		i;
	float	steps;
	float	increase_x;
	float	increase_y;

	if (fabsf(x2.x - x1.x) > fabsf(x2.y - x1.y))
	{
		steps = fabsf(x2.x - x1.x);
		increase_x = (x2.x - x1.x) / steps;
		increase_y = (x2.y - x1.y) / steps;
	}
	else
	{
		steps = fabsf(x2.y - x1.y);
		increase_x = (x2.x - x1.x) / steps;
		increase_y = (x2.y - x1.y) / steps;
	}
	i = 1;
	while (i++ <= steps)
		pixel_put(&game->img, x1.x + (increase_x * (i - 1)), x1.y + (increase_y
				* (i - 1)), color);
}

void	cast_n_project(t_cub3d *game, t_cast *cast)
{
	calculate_wals(cast);
	draw_all(game, cast);
	cast->height.x -= 1;
	cast->lines.x -= 1;
	cast->r_angle += 0.075;
	if (cast->r_angle < 0)
		cast->r_angle += 360;
	else if (cast->r_angle >= 360)
		cast->r_angle -= 360;
}

void	drawingtorch(t_cub3d *cube, unsigned int **map)
{
	int		y;
	float	mapy;
	int		x;
	float	mapx;

	y = 600;
	mapy = 0;
	while (y < 800)
	{
		x = 600;
		mapx = 0;
		while (x < 800)
		{
			if (map && map[(int)mapy][(int)mapx])
				pixel_put(&cube->img, x, y, map[(int)mapy][(int)mapx]);
			mapx += 0.25;
			x++;
		}
		mapy += 0.25;
		y++;
	}
}

void	draw(t_cub3d *game)
{
	game->img.img = mlx_new_image(game->mlx, game->width, game->height);
	game->img.addr = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_length, &game->img.endian);
	draw_floor(game);
	draw_top(game);
	render_rays(game);
	game->map.tnum++;
	if (game->map.tnum > 2)
	{
		game->map.tnum = 0;
		game->map.torchnum++;
		if (game->map.torchnum > 15)
			game->map.torchnum = 0;
	}
	drawingtorch(game, game->map.torch[game->map.torchnum]);
	mlx_put_image_to_window(game->mlx, game->mlx_window, game->img.img, 0, 0);
	mlx_destroy_image(game->mlx, game->img.img);
}

void	calculate_wals(t_cast *cast)
{
	if (cast->distv <= cast->disth)
		cast->distt = cast->distv;
	else
		cast->distt = cast->disth;
	cast->distt = cast->distt * cos(deg2rad(cast->angle_diff));
	cast->height.y = 64 * 400 / cast->distt;
	cast->lines.y = 400 - (cast->height.y / 2);
	cast->height.y += cast->lines.y;
}
