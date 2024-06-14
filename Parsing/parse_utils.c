/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:38:25 by mac               #+#    #+#             */
/*   Updated: 2024/06/14 21:29:44 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int	valid_letter(char letter)
{
	if (letter == '0' || letter == 'N' || letter == 'S' || letter == 'E'
		|| letter == 'W' || letter == ' ' || letter == '1')
		return (0);
	return (1);
}

int	check_digit(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (!ft_isdigit(string[i]))
		{
			free(string);
			return (0);
		}
		i++;
	}
	free(string);
	return (1);
}
