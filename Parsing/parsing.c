/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 20:09:45 by mayan             #+#    #+#             */
/*   Updated: 2024/06/14 21:24:44 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*reading(int fd)
{
	char	*ntext;
	char	*text;
	bool	flag;

	text = get_next_line(fd);
	ntext = get_next_line(fd);
	flag = false;
	while (ntext != NULL)
	{
		text = ft_strjoinfree(text, ntext, 3);
		ntext = get_next_line(fd);
		if (flag && ntext && ft_strlen(ntext) == 1)
		{
			free(ntext);
			ntext = ft_strdup("00000");
			continue ;
		}
		if (ntext && ft_strncmp("NO", ntext, 2) && ft_strncmp("SO", ntext, 2)
			&& ft_strncmp("EA", ntext, 2) && ft_strncmp("WE", ntext, 2)
			&& ft_strncmp("F", ntext, 1) && ft_strncmp("C", ntext, 1)
			&& ft_strlen(ntext) > 1)
			flag = true;
	}
	return (text);
}

void	parsingfr(t_cub3d *cub3d, char *argv[])
{
	int		fd;
	char	*str;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_p(cub3d, RED "Error: No File Name\n" RESET);
	str = reading(fd);
	if (!str)
		error_p(cub3d, RED "Error: Empty file\n" RESET);
	cub3d->map.file_map = ft_split(str, '\n');
	free(str);
	mapread(cub3d, texture_parse(cub3d));
	cub3d->player.p_x = cub3d->map.p_colom * 64 + 32;
	cub3d->player.p_y = cub3d->map.p_row * 64 + 32;
	cub3d->player.p_dx = cos(cub3d->player.p_angle) * 1;
	cub3d->player.p_dy = sin(cub3d->player.p_angle) * 1;
}
