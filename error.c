/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:26:45 by mac               #+#    #+#             */
/*   Updated: 2024/06/14 21:29:39 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	file_check(char *string)
{
	char	*str;

	str = ft_strchr(string, '.');
	if (str && ft_strcmp(str, ".cub") == 0)
		return (1);
	else
	{
		printf(RED"Error: file invalid\n"RESET);
		exit(1);
	}
	return (0);
}

void	error_p(t_cub3d *game, char *str)
{
	if (str)
	{
		while (*str)
			write(2, str++, 1);
	}
	close_free(game);
	exit(1);
}

void	close_free(t_cub3d *cube)
{
	if (cube->map.i_e)
		free_point(cube->map.i_e);
	if (cube->map.i_w)
		free_point(cube->map.i_w);
	if (cube->map.i_n)
		free_point(cube->map.i_n);
	if (cube->map.i_s)
		free_point(cube->map.i_s);
	if (cube->map.points)
		ft_freesplit(cube->map.points);
	if (cube->map.file_map)
		ft_freesplit(cube->map.file_map);
}

void	free_point(unsigned int **map)
{
	int	i;

	i = 0;
	while (i < 65)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	ft_freesplit(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
