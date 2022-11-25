/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:30:06 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/08 10:47:37 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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
