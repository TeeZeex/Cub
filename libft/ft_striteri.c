/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:39:13 by tzhakypo          #+#    #+#             */
/*   Updated: 2024/06/13 22:21:05 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!s)
		return ;
	i = ft_strlen(s);
	while (j < i)
	{
		(*f)(j, s);
		s++;
		j++;
	}
}
