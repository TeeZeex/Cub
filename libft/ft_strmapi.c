/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:39:27 by tzhakypo          #+#    #+#             */
/*   Updated: 2024/06/13 22:20:12 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*map;

	if (!s || !f)
		return (NULL);
	map = ft_strdup(s);
	if (!map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		map[i] = f(i, map[i]);
		i++;
	}
	return (map);
}
