/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayan <mayan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:39:05 by tzhakypo          #+#    #+#             */
/*   Updated: 2024/06/13 22:21:08 by mayan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inside(char const *s, char c, int left)
{
	int	c1;

	c1 = 0;
	while (s[left] != c && s[left] != '\0')
	{
		left++;
		c1++;
	}
	return (c1 + 1);
}

static int	ft_count(char const *s, char c)
{
	int	a;
	int	a1;
	int	ccount;

	a = 0;
	a1 = 0;
	ccount = 0;
	while (s[a])
	{
		while (s[a] == c && s[a])
		{
			a++;
			ccount++;
		}
		if (s[a] == '\0')
			break ;
		a1++;
		a += ft_inside(s, c, a) - 1;
	}
	if (ccount == a)
		return (1);
	return (a1 + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**main;
	char	*inside;
	size_t	left;
	int		m;
	size_t	len;

	left = 0;
	m = 0;
	len = ft_strlen(s);
	main = ft_calloc(sizeof(char *), (ft_count(s, c)));
	if (main == NULL)
		return (NULL);
	while (left < len && 1 != ft_count(s, c))
	{
		while (s[left] == c && s[left] != '\0')
			left++;
		if (s[left] == '\0')
			break ;
		inside = ft_substr(s, left, ft_inside(s, c, left) - 1);
		left += ft_inside(s, c, left) - 1;
		main[m] = inside;
		m++;
	}
	main[m] = NULL;
	return (main);
}
