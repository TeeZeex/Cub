/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:51:23 by tzhakypo          #+#    #+#             */
/*   Updated: 2024/06/13 19:54:47 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	draw_floor(t_cub3d *game)
{
	t_point	start;
	t_point	end;

	start.x = 0;
	start.y = 0;
	end.x = 800;
	end.y = 0;
	while (end.y < 400)
	{
		dda(start, end, game, game->map.c);
		end.y++;
		start.y++;
	}
}

void	draw_top(t_cub3d *game)
{
	t_point	start;
	t_point	end;

	start.x = 0;
	start.y = 400;
	end.x = 800;
	end.y = 400;
	while (end.y < 800)
	{
		dda(start, end, game, game->map.f);
		end.y++;
		start.y++;
	}
}

void	draw_all(t_cub3d *game, t_cast *cast)
{
	if (cast->distv <= cast->disth)
		wall_text_v(cast->height, cast->lines, game, cast);
	else
		wall_text_h(cast->height, cast->lines, game, cast);
}

void	wall_text_v(t_point x1, t_point x2, t_cub3d *game, t_cast *cast)
{
	int		i;
	float	steps;
	float	increase_x;
	float	increase_y;
	float	increase_t;

	if (fabsf(x2.x - x1.x) > fabsf(x2.y - x1.y))
		steps = fabsf(x2.x - x1.x);
	else
		steps = fabsf(x2.y - x1.y);
	increase_x = (x2.x - x1.x) / steps;
	increase_y = (x2.y - x1.y) / steps;
	increase_t = 64 / steps;
	i = -1;
	while (++i < steps)
	{
		if (v_angle(cast) && v_condition(x1, increase_x, increase_y, i))
			pixel_put(&game->img, x1.x + (increase_x * i),
				x1.y + (increase_y * i), game->map.i_e[
				(int)fabsf(increase_t * i)][(int)(cast->rayv.y * 4) % 64]);
		else
			pixel_put(&game->img, x1.x + (increase_x * i),
				x1.y + (increase_y * i), game->map.i_w[
				(int)fabsf(increase_t * i)][(int)(cast->rayv.y * 4) % 64]);
	}
}

void	wall_text_h(t_point x1, t_point x2, t_cub3d *game, t_cast *cast)
{
	t_dda	h;

	if (fabsf(x2.x - x1.x) > fabsf(x2.y - x1.y))
		h.s = fabsf(x2.x - x1.x);
	else
		h.s = fabsf(x2.y - x1.y);
	h.x = (x2.x - x1.x) / h.s;
	h.y = (x2.y - x1.y) / h.s;
	h.t = 64 / h.s;
	h.i = 0;
	while (h.i++ <= h.s)
	{
		if (cast->r_angle > 0 && cast->r_angle < 180)
			pixel_put(&game->img, x1.x + (h.x * (h.i - 1)),
				x1.y + (h.y * (h.i - 1)), game->map.i_s[
				(int)fabsf(h.t * (h.i - 1))][(int)(cast->rayh.x * 4) % 64]);
		else
			pixel_put(&game->img, x1.x + (h.x * (h.i - 1)),
				x1.y + (h.y * (h.i - 1)), game->map.i_n[
				(int)fabsf(h.t * (h.i - 1))]
			[(int)(cast->rayh.x * 4) % 64]);
	}
}
