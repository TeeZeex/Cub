/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:39:43 by tzhakypo          #+#    #+#             */
/*   Updated: 2024/06/13 21:09:02 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	change_angle(t_cub3d *game)
{
	if (game->player.left)
		game->player.p_angle += 4;
	if (game->player.right)
		game->player.p_angle -= 4;
	if (game->player.p_angle < 0)
		game->player.p_angle = 360;
	else if (game->player.p_angle >= 360)
		game->player.p_angle = 0;
}

void	change_position(t_cub3d *game)
{
	if (!game->player.shift)
	{
		game->player.p_dx = -cos(deg2rad(game->player.p_angle)) * 1;
		game->player.p_dy = sin(deg2rad(game->player.p_angle)) * 1;
	}
	else
	{
		game->player.p_dx = (-cos(deg2rad(game->player.p_angle))) * 5;
		game->player.p_dy = (sin(deg2rad(game->player.p_angle))) * 5;
	}
}

bool	condition(t_cub3d *game)
{
	int	x;
	int	y;

	x = game->player.p_y;
	y = game->player.p_x;
	if (game->map.points[x / 64][y / 64] == '1' || game->map.points[(x - 15)
		/ 64][(y - 15) / 64] == '1' || game->map.points[(x) / 64][(y - 15)
		/ 64] == '1' || game->map.points[(x - 15) / 64][(y) / 64] == '1'
		|| game->map.points[(x + 15) / 64][(y + 15) / 64] == '1'
		|| game->map.points[(x) / 64][(y + 15) / 64] == '1'
		|| game->map.points[(x + 15) / 64][(y) / 64] == '1'
		|| game->map.points[(x - 15) / 64][(y + 15) / 64] == '1'
		|| game->map.points[(x + 15) / 64][(y - 15) / 64] == '1')
		return (true);
	return (false);
}

void	check_boundaries(t_cub3d *game)
{
	if (game->player.a)
	{
		game->player.p_x += game->player.p_dy;
		if (condition(game))
			game->player.p_x -= game->player.p_dy;
		game->player.p_y -= game->player.p_dx;
		if (condition(game))
			game->player.p_y += game->player.p_dx;
	}
	if (game->player.d)
	{
		game->player.p_x -= game->player.p_dy;
		if (condition(game))
			game->player.p_x += game->player.p_dy;
		game->player.p_y += game->player.p_dx;
		if (condition(game))
			game->player.p_y -= game->player.p_dx;
	}
}
