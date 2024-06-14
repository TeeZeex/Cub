/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:35:37 by tzhakypo          #+#    #+#             */
/*   Updated: 2024/06/13 19:54:38 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	keydown(int keycode, t_cub3d *game)
{
	if (keycode == W)
		game->player.w = true;
	else if (keycode == A)
		game->player.a = true;
	else if (keycode == S)
		game->player.s = true;
	else if (keycode == D)
		game->player.d = true;
	else if (keycode == LEFT)
		game->player.left = true;
	else if (keycode == RIGHT)
		game->player.right = true;
	else if (keycode == SHIFT)
		game->player.shift = true;
	return (0);
}

int	close_esc(int keycode, t_cub3d *game)
{
	(void)keycode;
	mlx_destroy_window(game->mlx, game->mlx_window);
	free(game->mlx);
	close_free(game);
	exit(0);
	return (0);
}

int	keyup(int keycode, t_cub3d *game)
{
	if (keycode == ESC)
		return (close_esc(keycode, game));
	else if (keycode == W)
		game->player.w = false;
	else if (keycode == A)
		game->player.a = false;
	else if (keycode == S)
		game->player.s = false;
	else if (keycode == D)
		game->player.d = false;
	else if (keycode == LEFT)
		game->player.left = false;
	else if (keycode == RIGHT)
		game->player.right = false;
	else if (keycode == SHIFT)
		game->player.shift = false;
	return (0);
}

int	move(t_cub3d *game)
{
	change_angle(game);
	change_position(game);
	if (game->player.w)
	{
		game->player.p_x += game->player.p_dx;
		if (condition(game))
			game->player.p_x -= game->player.p_dx;
		game->player.p_y += game->player.p_dy;
		if (condition(game))
			game->player.p_y -= game->player.p_dy;
	}
	if (game->player.s)
	{
		game->player.p_x -= game->player.p_dx;
		if (condition(game))
			game->player.p_x += game->player.p_dx;
		game->player.p_y -= game->player.p_dy;
		if (condition(game))
			game->player.p_y += game->player.p_dy;
	}
	check_boundaries(game);
	draw(game);
	return (0);
}

void	hooks(t_cub3d cub3d)
{
	mlx_hook(cub3d.mlx_window, 17, 0, close_x, &cub3d);
	mlx_hook(cub3d.mlx_window, 2, 1L << 0, keydown, &cub3d);
	mlx_hook(cub3d.mlx_window, 3, (1L << 1), keyup, &cub3d);
	mlx_loop_hook(cub3d.mlx, move, &cub3d);
}
