/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:55:19 by tzhakypo          #+#    #+#             */
/*   Updated: 2024/06/15 00:54:25 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	render_rays(t_cub3d *game)
{
	t_cast	ray_info;

	initialize_cast(&ray_info, game);
	ray_info.rays = 0;
	while (ray_info.rays < 800)
	{
		ray_info.angle_diff = game->player.p_angle - ray_info.r_angle;
		if (ray_info.angle_diff < 0)
			ray_info.angle_diff += 360;
		ray_info.player.x = game->player.p_x;
		ray_info.player.y = game->player.p_y;
		set_horizontals(game, &ray_info);
		set_rayh(game, &ray_info);
		set_vertical_rays(game, &ray_info);
		fov(&ray_info);
		cast_n_project(game, &ray_info);
		ray_info.rays++;
	}
}

void	set_horizontals(t_cub3d *game, t_cast *cast)
{
	float	angle_rad;

	cast->dof = 0;
	if (cast->r_angle > 180)
	{
		cast->rayh.y = (((int)game->player.p_y >> 6) << 6) - 0.0001;
		cast->off.y = -64;
	}
	else
	{
		cast->rayh.y = (((int)game->player.p_y >> 6) << 6) + 64;
		cast->off.y = 64;
	}
	angle_rad = deg2rad(cast->r_angle);
	cast->rayh.x = game->player.p_x + (game->player.p_y - cast->rayh.y) * (1
			/ tan(angle_rad));
	cast->off.x = -cast->off.y * (1 / tan(angle_rad));
}

void	set_rayh(t_cub3d *game, t_cast *cast)
{
	int	dof_count;

	dof_count = 0;
	while (dof_count++ < DOF)
	{
		cast->disth = 100000;
		if (cast->rayh.y / 64 < game->map.height && cast->rayh.y / 64 >= 0
			&& cast->rayh.x / 64 < game->map.width && cast->rayh.x / 64 >= 0
			&& game->map.points[(int)(cast->rayh.y / 64)][(int)(cast->rayh.x
				/ 64)] == '1')
		{
			cast->disth = dist(cast->player, cast->rayh, cast->r_angle);
			break ;
		}
		else
		{
			cast->rayh.x += cast->off.x;
			cast->rayh.y += cast->off.y;
		}
	}
	if (cast->rayh.x <= 0)
		cast->rayh.x = 0;
	if (cast->rayh.y <= 0)
		cast->rayh.y = 0;
}
