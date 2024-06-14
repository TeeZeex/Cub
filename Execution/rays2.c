/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:41:08 by tzhakypo          #+#    #+#             */
/*   Updated: 2024/06/15 00:54:04 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	initialize_vertical_ray(t_cub3d *game, t_cast *cast)
{
	if (cast->r_angle > 90 && cast->r_angle < 270)
	{
		cast->rayv.x = (((int)game->player.p_x >> 6) << 6) + 64;
		cast->off.x = 64;
	}
	else
	{
		cast->rayv.x = (((int)game->player.p_x >> 6) << 6) - 0.0001;
		cast->off.x = -64;
	}
	cast->rayv.y = game->player.p_y + (game->player.p_x - cast->rayv.x)
		* tan(deg2rad(cast->r_angle));
	cast->off.y = -cast->off.x * tan(deg2rad(cast->r_angle));
	cast->dof = 0;
}

void	cast_vertical_ray(t_cub3d *game, t_cast *cast)
{
	while (cast->dof < DOF)
	{
		cast->distv = 100000;
		if (cast->rayv.x / 64 >= 0 && cast->rayv.y / 64 >= 0 && cast->rayv.y
			/ 64 < game->map.height && cast->rayv.x / 64 < game->map.width
			&& game->map.points[(int)(cast->rayv.y / 64)][(int)(cast->rayv.x
				/ 64)] == '1')
		{
			cast->distv = dist(cast->player, cast->rayv, cast->r_angle);
			break ;
		}
		else
		{
			cast->rayv.x += cast->off.x;
			cast->rayv.y += cast->off.y;
		}
		cast->dof++;
	}
}

void	set_vertical_rays(t_cub3d *game, t_cast *cast)
{
	initialize_vertical_ray(game, cast);
	cast_vertical_ray(game, cast);
}
