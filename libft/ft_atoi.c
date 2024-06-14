/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhakypo <tzhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:36:08 by tzhakypo          #+#    #+#             */
/*   Updated: 2024/06/13 17:36:20 by tzhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_iswhitespaces(const int c)
{
	return (c == ' ' || c == '\n' || c == '\t'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(const char *str)
{
	size_t			i;
	long			n;
	long long		result;

	i = 0;
	n = 1;
	result = 0;
	while (str[i] && ft_iswhitespaces(str[i]))
		i++;
	if (str[i] == '-' && ++i)
		n = -1;
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		if (n == -1 && result * 10 < result)
			return (0);
		else if (n == 1 && result * 10 < result)
			return (-1);
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * n);
}
