/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhakypo <tzhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:36:24 by tzhakypo          #+#    #+#             */
/*   Updated: 2024/06/13 17:36:26 by tzhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	void	*h;

	if (size && SIZE_MAX / size < count)
		return (NULL);
	i = count * size;
	h = malloc(i);
	if (!h)
		return (NULL);
	ft_memset(h, 0, i);
	return (h);
}
