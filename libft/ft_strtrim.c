/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:39:48 by tzhakypo          #+#    #+#             */
/*   Updated: 2024/06/13 22:19:03 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	i = ft_strlen(s1);
	while (i && ft_strchr(set, s1[i]))
		i--;
	return (ft_substr(s1, 0, i + 1));
}

char	*allocate_empty_string(char *s1)
{
	char	*ptr;

	free(s1);
	ptr = malloc(1);
	if (ptr == NULL)
		return (NULL);
	ptr[0] = '\0';
	return (ptr);
}

char	*ft_strtrim_free(char *s1, char const *set)
{
	int		left;
	int		right;
	int		i;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	left = 0;
	right = (ft_strlen(s1) - 1);
	while (ft_strchr(set, s1[left]) != NULL)
		left++;
	if (left > right)
		return (allocate_empty_string(s1));
	while (right >= 0 && ft_strchr(set, s1[right]) != NULL)
		right--;
	ptr = ft_calloc(sizeof(char), (right - left + 2));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (left <= right)
		ptr[i++] = s1[left++];
	free(s1);
	return (ptr);
}
