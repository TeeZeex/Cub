/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tzhakypo <tzhakypo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:37:47 by tzhakypo          #+#    #+#             */
/*   Updated: 2024/06/13 17:37:50 by tzhakypo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_node;
	t_list	*new_node;

	first_node = NULL;
	while (lst)
	{
		new_node = ft_lstnew((f)(lst -> content));
		if (!new_node)
		{
			ft_lstclear(&first_node, del);
			return (NULL);
		}
		ft_lstadd_back(&first_node, new_node);
		lst = lst -> next;
	}
	return (first_node);
}
