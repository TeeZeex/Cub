/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 20:35:21 by mayan             #+#    #+#             */
/*   Updated: 2024/06/14 20:53:47 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	*torch_load_image(t_cub3d *game, char *file_path, int *w, int *h)
{
	char	*data;

	game->img.img = mlx_xpm_file_to_image(game->mlx, file_path, w, h);
	if (game->img.img == NULL)
		error_p(game, RED "Error texture didnt exist\n" RESET);
	data = mlx_get_data_addr(game->img.img, &game->img.bpp,
			&game->img.line_length, &game->img.endian);
	return (data);
}

unsigned int	**torch_create_texture(char *data, t_cub3d *game)
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
			a.pixel_position = (a.j * game->img.line_length + a.i
					* (game->img.bpp / 8));
			a.texture[a.j][a.i] = *(unsigned int *)&data[a.pixel_position];
			a.i++;
		}
		a.j++;
	}
	mlx_destroy_image(game->mlx, game->img.img);
	return (a.texture);
}

unsigned int	**tor_load_tex(t_cub3d *game, char *file_path, int w, int h)
{
	char			*data;
	unsigned int	**texture;

	data = load_image(game, file_path, &w, &h);
	texture = torch_create_texture(data, game);
	return (texture);
}

void	load_torches(t_cub3d *game)
{
	game->map.torch = calloc(16, sizeof(unsigned int **));
	game->map.torch[0] = tor_load_tex(game, "tex/Torch_1.xpm", 64, 64);
	game->map.torch[1] = tor_load_tex(game, "tex/Torch_2.xpm", 64, 64);
	game->map.torch[2] = tor_load_tex(game, "tex/Torch_3.xpm", 64, 64);
	game->map.torch[3] = tor_load_tex(game, "tex/Torch_4.xpm", 64, 64);
	game->map.torch[4] = tor_load_tex(game, "tex/Torch_5.xpm", 64, 64);
	game->map.torch[5] = tor_load_tex(game, "tex/Torch_6.xpm", 64, 64);
	game->map.torch[6] = tor_load_tex(game, "tex/Torch_7.xpm", 64, 64);
	game->map.torch[7] = tor_load_tex(game, "tex/Torch_8.xpm", 64, 64);
	game->map.torch[8] = tor_load_tex(game, "tex/Torch_9.xpm", 64, 64);
	game->map.torch[9] = tor_load_tex(game, "tex/Torch_10.xpm", 64, 64);
	game->map.torch[10] = tor_load_tex(game, "tex/Torch_11.xpm", 64, 64);
	game->map.torch[11] = tor_load_tex(game, "tex/Torch_12.xpm", 64, 64);
	game->map.torch[12] = tor_load_tex(game, "tex/Torch_13.xpm", 64, 64);
	game->map.torch[13] = tor_load_tex(game, "tex/Torch_14.xpm", 64, 64);
	game->map.torch[14] = tor_load_tex(game, "tex/Torch_15.xpm", 64, 64);
	game->map.torch[15] = tor_load_tex(game, "tex/Torch_16.xpm", 64, 64);
}

void	free_torch(unsigned int ***torch)
{
	int	c;

	c = 0;
	while (c < 16)
	{
		free_point(torch[c]);
		c++;
	}
	free(torch);
}
