/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:20:12 by mayan             #+#    #+#             */
/*   Updated: 2024/06/14 21:28:53 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	validate_and_join(char **str, char *line, t_cub3d *cub3d)
{
	int	j;

	j = 0;
	while (line[j])
	{
		if (valid_letter(line[j]))
		{
			free(*str);
			error_p(cub3d, RED "Error: Map wrong\n" RESET);
		}
		j++;
	}
	*str = ft_strjoinfree(*str, "\n", 1);
	*str = ft_strjoinfree(*str, line, 1);
}

char	*get_pl(t_cub3d *cub3d, int i, char *str)
{
	cub3d->player.p_angle = -1;
	if (ft_strchr(cub3d->map.points[i], 'N') != NULL)
	{
		str = ft_strchr(cub3d->map.points[i], 'N');
		cub3d->player.p_angle = 270;
	}
	if (ft_strchr(cub3d->map.points[i], 'S') != NULL)
	{
		str = ft_strchr(cub3d->map.points[i], 'S');
		cub3d->player.p_angle = 90;
	}
	if (ft_strchr(cub3d->map.points[i], 'E') != NULL)
	{
		str = ft_strchr(cub3d->map.points[i], 'E');
		cub3d->player.p_angle = 180;
	}
	if (ft_strchr(cub3d->map.points[i], 'W') != NULL)
	{
		str = ft_strchr(cub3d->map.points[i], 'W');
		cub3d->player.p_angle = 0;
	}
	if (cub3d->player.p_angle < 0
		|| (ft_strlen(str) != ft_strlen(ft_strrchr(str, str[0]))))
		error_p(cub3d, RED "Error: Wrong number of players\n" RESET);
	return (str);
}

int	if_player(t_cub3d *cub3d, int i)
{
	int	c1;

	c1 = 0;
	if (ft_strchr(cub3d->map.points[i], 'N') != NULL)
		c1++;
	if (ft_strchr(cub3d->map.points[i], 'S') != NULL)
		c1++;
	if (ft_strchr(cub3d->map.points[i], 'E') != NULL)
		c1++;
	if (ft_strchr(cub3d->map.points[i], 'W') != NULL)
		c1++;
	return (c1 - 1);
}

void	wallcheck_vert(t_cub3d *cub3d, int row, int colom)
{
	int	vert;

	vert = row;
	while (cub3d->map.points[vert][colom] != '1')
	{
		vert--;
		if (vert < 0 || colom >= (int)ft_strlen(cub3d->map.points[vert])
			|| valid_letter(cub3d->map.points[vert][colom]) == 1)
			error_p(cub3d, RED "Error: vert wall\n" RESET);
	}
	vert = row;
	while (cub3d->map.points[vert][colom] != '1')
	{
		vert++;
		if (vert >= cub3d->map.height
			|| valid_letter(cub3d->map.points[vert][colom]) == 1)
			error_p(cub3d, RED "Error: vert wall\n" RESET);
	}
}

int	wallcheck_hor(t_cub3d *cub3d, int row, int colom)
{
	int	hor;

	hor = colom;
	while (cub3d->map.points[row][hor] != '1')
	{
		hor--;
		if (hor < 0 || valid_letter(cub3d->map.points[row][hor]) == 1)
			error_p(cub3d, RED "Error: horizontal wall\n" RESET);
	}
	hor = colom;
	while (cub3d->map.points[row][hor] != '1')
	{
		hor++;
		if (hor >= cub3d->map.width
			|| valid_letter(cub3d->map.points[row][hor]) == 1)
			error_p(cub3d, RED "Error: horizontal wall\n" RESET);
	}
	return (1);
}
