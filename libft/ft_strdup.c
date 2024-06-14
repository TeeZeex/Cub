/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:39:10 by tzhakypo          #+#    #+#             */
/*   Updated: 2024/06/13 22:21:06 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s;

	s = malloc(ft_strlen(s1) + 1);
	if (!s)
		return (NULL);
	s = ft_memcpy(s, s1, ft_strlen(s1) + 1);
	return (s);
}
