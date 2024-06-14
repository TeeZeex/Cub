/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 00:48:21 by tzhakypo          #+#    #+#             */
/*   Updated: 2024/06/15 00:44:59 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init(t_cub3d *game)
{
	game->map.points = NULL;
	game->map.file_map = NULL;
	game->map.t_n = NULL;
	game->map.t_s = NULL;
	game->map.t_e = NULL;
	game->map.t_w = NULL;
	game->map.i_n = NULL;
	game->map.i_s = NULL;
	game->map.i_e = NULL;
	game->map.i_w = NULL;
	game->map.torch = NULL;
}

void	set_booleans(t_cub3d *game)
{
	game->player.w = false;
	game->player.s = false;
	game->player.a = false;
	game->player.d = false;
	game->player.left = false;
	game->player.right = false;
	game->m = false;
	game->player.shift = false;
}

void	set_sides_and_mlx(t_cub3d *game)
{
	game->width = 800;
	game->height = 800;
	game->mlx = mlx_init();
	game->mlx_window = mlx_new_window(game->mlx, game->width, game->height, "");
	check_text(game);
	game->map.i_n = load_texture(game, game->map.t_n, 64, 64);
	game->map.i_s = load_texture(game, game->map.t_s, 64, 64);
	game->map.i_e = load_texture(game, game->map.t_e, 64, 64);
	game->map.i_w = load_texture(game, game->map.t_w, 64, 64);
	load_torches(game);
}

void	initialize_cast(t_cast *rend, t_cub3d *game)
{
	rend->rays = 0;
	rend->r_angle = game->player.p_angle - 30;
	rend->lines.x = 800;
	rend->lines.y = 0;
	rend->height.x = 800;
}

void	fov(t_cast *cast)
{
	cast->player.x /= 2;
	cast->player.y /= 2;
	cast->rayv.x /= 2;
	cast->rayv.y /= 2;
	cast->rayh.x /= 2;
	cast->rayh.y /= 2;
}
