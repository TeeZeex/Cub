/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 20:27:20 by mayan             #+#    #+#             */
/*   Updated: 2024/06/14 21:24:11 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	player_info(t_cub3d *cub3d)
{
	char	*str;
	int		i;
	int		leter_count;

	i = 0;
	leter_count = 0;
	while (cub3d->map.points[i])
	{
		if (ft_strchr(cub3d->map.points[i], 'N') != NULL
			|| ft_strchr(cub3d->map.points[i], 'S') != NULL
			|| ft_strchr(cub3d->map.points[i], 'E') != NULL
			|| ft_strchr(cub3d->map.points[i], 'W') != NULL)
		{
			str = get_pl(cub3d, i, str);
			cub3d->map.p_row = i;
			cub3d->map.p_colom = ft_strlen(cub3d->map.points[i])
				- ft_strlen(str);
			leter_count += if_player(cub3d, i);
			leter_count++;
		}
		i++;
	}
	if (leter_count > 1)
		error_p(cub3d, RED "Error: Wrong number of players\n" RESET);
}

void	map_size(t_cub3d *cub3d)
{
	int	i;
	int	c1;

	i = 0;
	c1 = 0;
	c1 = ft_strlen(cub3d->map.points[i]);
	while (cub3d->map.points[i])
	{
		if ((int)ft_strlen(cub3d->map.points[i]) > c1)
			c1 = ft_strlen(cub3d->map.points[i]);
		i++;
	}
	cub3d->map.width = c1;
	cub3d->map.height = i;
}

void	map_checker(t_cub3d *cub3d)
{
	int	row;
	int	colom;

	row = 0;
	while (cub3d->map.points[row])
	{
		colom = 0;
		while (cub3d->map.points[row][colom])
		{
			if (cub3d->map.points[row][colom] == '0')
			{
				wallcheck_vert(cub3d, row, colom);
				wallcheck_hor(cub3d, row, colom);
			}
			colom++;
		}
		row++;
	}
}

void	check_player_exist(t_cub3d *cube)
{
	bool	flag;
	int		i;

	i = 0;
	flag = false;
	while (cube->map.points[i])
	{
		if (ft_strchr(cube->map.points[i], 'N')
			|| ft_strchr(cube->map.points[i], 'W')
			|| ft_strchr(cube->map.points[i], 'S')
			|| ft_strchr(cube->map.points[i], 'E'))
			flag = true;
		i++;
	}
	if (!flag)
		error_p(cube, RED "Error: Wrong number of players\n" RESET);
}

void	mapread(t_cub3d *cub3d, int start)
{
	int		i;
	char	*str;

	i = start;
	str = ft_strdup(cub3d->map.file_map[i]);
	while (cub3d->map.file_map[i])
	{
		validate_and_join(&str, cub3d->map.file_map[i], cub3d);
		i++;
	}
	str = ft_strtrim_free(str, "\n");
	cub3d->map.points = ft_split(str, '\n');
	free(str);
	check_player_exist(cub3d);
	map_size(cub3d);
	map_checker(cub3d);
	player_info(cub3d);
}
