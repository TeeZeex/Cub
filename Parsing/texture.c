/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 21:54:24 by mayan             #+#    #+#             */
/*   Updated: 2024/06/14 22:08:11 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// Transparency (t):
// Shift the transparency value left by 24 bits to place it in the highest byte.
// t << 24
// Red (r):
// Shift the red value left by 16 bits to place it in the second highest byte.
// r << 16
// Green (g):
// Shift the green value left by 8 bits to place it in the third highest byte.
// g << 8
// Blue (b):
// The blue value stays in the lowest byte, so no shifting is needed.

// Combine Using Bitwise OR:
// Use the bitwise OR operator (|) to combine these shifted
// values into a single 32-bit integer.
// t << 24 | r << 16 | g << 8 | b

int	get_color(char *line)
{
	char	**spl;
	int		i;
	int		ret;

	spl = ft_split(line, ',');
	i = 0;
	while (spl[i])
		i++;
	if (i != 3)
	{
		ft_freesplit(spl);
		return (-1);
	}
	if ((spl[0] && spl[1] && spl[2]) && (check_digit(ft_strtrim(spl[0],
					" ")) == 1) && (check_digit(ft_strtrim(spl[1], " ")) == 1)
		&& (check_digit(ft_strtrim(spl[2], " ")) == 1))
		ret = create_trgb(1, ft_atoi(spl[0]), ft_atoi(spl[1]), ft_atoi(spl[2]));
	else
	{
		ft_freesplit(spl);
		return (-1);
	}
	ft_freesplit(spl);
	return (ret);
}

void	path_validate(t_cub3d *cube)
{
	t_player	bol;
	int			i;

	i = 0;
	bol.w = false;
	bol.a = false;
	bol.s = false;
	bol.d = false;
	while (cube->map.file_map[i] && i < 4)
	{
		bol.w = (bol.w || (ft_strncmp(cube->map.file_map[i], "NO", 2) == 0));
		bol.a = (bol.a || (ft_strncmp(cube->map.file_map[i], "SO", 2) == 0));
		bol.s = (bol.s || (ft_strncmp(cube->map.file_map[i], "EA", 2) == 0));
		bol.d = (bol.d || (ft_strncmp(cube->map.file_map[i], "WE", 2) == 0));
		i++;
	}
	if (!bol.w || !bol.a || !bol.s || !bol.d)
		error_p(cube, RED "Error: Texture path\n" RESET);
}

int	addpath_n_color(t_cub3d *cub3d, char *line, int i)
{
	if (ft_strncmp(line, "NO", 2) == 0)
		cub3d->map.t_n = ft_strchr(cub3d->map.file_map[i], '.');
	else if (!ft_strncmp(line, "SO", 2))
		cub3d->map.t_s = ft_strchr(cub3d->map.file_map[i], '.');
	else if (!ft_strncmp(line, "EA", 2))
		cub3d->map.t_e = ft_strchr(cub3d->map.file_map[i], '.');
	else if (!ft_strncmp(line, "WE", 2))
		cub3d->map.t_w = ft_strchr(cub3d->map.file_map[i], '.');
	else if (!ft_strncmp(line, "F", 1))
		cub3d->map.f = get_color(ft_substr((cub3d->map.file_map[i]), 1,
					ft_strlen(cub3d->map.file_map[i])));
	else if (!ft_strncmp(line, "C", 1))
		cub3d->map.c = get_color(ft_substr((cub3d->map.file_map[i]), 1,
					ft_strlen(cub3d->map.file_map[i])));
	else
		return (1);
	return (0);
}

int	texture_parse(t_cub3d *cub3d)
{
	int		i;
	char	*line;

	i = 0;
	while (cub3d->map.file_map[i] != NULL)
	{
		line = ft_strtrim(cub3d->map.file_map[i], " ");
		if (addpath_n_color(cub3d, line, i) == 1)
			break ;
		free(line);
		i++;
	}
	if (cub3d->map.file_map[i] == NULL)
	{
		close_free(cub3d);
		exit(1);
	}
	if (line)
		free(line);
	if (cub3d->map.c == -1 || cub3d->map.f == -1)
		error_p(cub3d, RED "Error: Ceiling or Floor, wrong color\n" RESET);
	path_validate(cub3d);
	return (i);
}
