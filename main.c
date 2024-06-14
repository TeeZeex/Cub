/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:20:24 by mac               #+#    #+#             */
/*   Updated: 2024/06/14 22:30:17 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	check_param(int argc, char **argv, t_cub3d *cub3d)
{
	if (argc != 2 || file_check(argv[1]) != 1)
	{
		printf("Error: WRONG ARGUMENTS");
		exit(1);
	}
	if (access(argv[1], F_OK) == -1 || access(argv[1], R_OK) == -1)
		error_p(cub3d, "");
}

void	create_map(t_cub3d *game)
{
	set_sides_and_mlx(game);
	draw(game);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;

	check_param(argc, argv, &cub3d);
	init(&cub3d);
	set_booleans(&cub3d);
	parsingfr(&cub3d, argv);
	create_map(&cub3d);
	hooks(cub3d);
	mlx_loop(cub3d.mlx);
}
