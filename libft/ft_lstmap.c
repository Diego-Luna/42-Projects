/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 09:38:10 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/07 12:27:02 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first_elem;
	t_list	*new_elem;

	if (!f || !del)
		return (NULL);
	first_elem = NULL;
	while (lst)
	{
		new_elem = ft_lstnew((*f)(lst->content));
		if (!new_elem)
		{
			while (first_elem)
			{
				new_elem = first_elem->next;
				(*del)(first_elem->content);
				free(first_elem);
				first_elem = new_elem;
			}
			lst = NULL;
			return (NULL);
		}
		ft_lstadd_back(&first_elem, new_elem);
		lst = lst->next;
	}
	return (first_elem);
}
