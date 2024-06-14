/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 19:24:01 by mac               #+#    #+#             */
/*   Updated: 2024/06/13 23:37:05 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	close_x(t_cub3d *game)
{
	mlx_destroy_window(game->mlx, game->mlx_window);
	free(game->mlx);
	close_free(game);
	exit(0);
	return (0);
}

void	check_text(t_cub3d *game)
{
	if (access(game->map.t_n, F_OK | R_OK) == -1 || access(game->map.t_s,
			F_OK | R_OK) == -1 || access(game->map.t_w, F_OK | R_OK) == -1
		|| access(game->map.t_e, F_OK | R_OK) == -1)
	{
		mlx_destroy_window(game->mlx, game->mlx_window);
		free(game->mlx);
		error_p(game, RED"Error texture didnt exist\n"RESET);
	}
}

char	*load_image(t_cub3d *game, char *file_path, int *w, int *h)
{
	char	*data;

	game->img.img = mlx_xpm_file_to_image(game->mlx, file_path, w, h);
	if (game->img.img == NULL)
		error_p(game, RED"Error texture didnt exist\n"RESET);
	data = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_length, &game->img.endian);
	return (data);
}

unsigned int	**create_texture(char *data, t_cub3d *game)
{
	t_text	a;

	a.texture = ft_calloc(65, sizeof(unsigned int *));
	a.j = 0;
	while (a.j < 65)
	{
		a.texture[a.j] = ft_calloc(65, sizeof(unsigned int));
		a.j++;
	}
	a.j = 0;
	while (a.j < 64)
	{
		a.i = 0;
		while (a.i < 64)
		{
			a.pixel_position = ((63 - a.j) * game->img.line_length + a.i
					* (game->img.bpp / 8));
			a.texture[a.j][a.i] = *(unsigned int *)&data[a.pixel_position];
			a.i++;
		}
		a.j++;
	}
	mlx_destroy_image(game->mlx, game->img.img);
	return (a.texture);
}

unsigned int	**load_texture(t_cub3d *game, char *file_path, int w, int h)
{
	char			*data;
	unsigned int	**texture;

	data = load_image(game, file_path, &w, &h);
	texture = create_texture(data, game);
	return (texture);
}
