/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 01:03:26 by tzhakypo          #+#    #+#             */
/*   Updated: 2024/06/13 19:54:50 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

double	deg2rad(double degrees)
{
	return (degrees * (PIE / 180.0));
}

float	dist(t_point player, t_point ray, float angle)
{
	(void)angle;
	return (sqrt(((ray.x - player.x) * (ray.x - player.x)) + ((ray.y - player.y)
				* (ray.y - player.y))));
}

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && y >= 0) && (x < 800 && y < 800))
	{
		dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

bool	v_condition(t_point x1, float increase_x, float increase_y, int i)
{
	if (x1.x + (increase_x * i) >= 0 && x1.x + (increase_x * i) < 800 && x1.y
		+ (increase_y * i) >= 0 && x1.y + (increase_y * i) < 800)
		return (true);
	return (false);
}

bool	v_angle(t_cast *cast)
{
	if (cast->r_angle > 90 && cast->r_angle < 270)
		return (true);
	return (false);
}
