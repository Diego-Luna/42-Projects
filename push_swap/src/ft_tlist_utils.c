/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tlist_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:28:32 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/29 17:26:36 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function creates a new tlist, and puts it at the end
// of the list, receives the list to add to and the memory
// address of the value to add to the new tlist
void	ft_lstlast_new_table(t_list *lst, void *content)
{
	t_list	*tmp;

	tmp = ft_lstnew(content);
	ft_lstadd_back(&lst, tmp);
}

// This function returns the tlist at the indicated position,
// receives the tlist where to search and the position
t_list	*ft_get_list_n(t_list *lst, int num)
{
	int	i;

	i = 1;
	if (num == 0)
	{
		num = 1;
	}
	while (lst && i <= num)
	{
		if (i == num)
		{
			return (lst);
		}
		i++;
		lst = lst->next;
	}
	if (i == num)
	{
		return (lst);
	}
	return (NULL);
}

/*  This function returns the int value of the tlist at the
 indicated position, receives the tlist where to search
 and the position */
int	ft_gnl(t_list *lst, int num)
{
	int	value;

	if (num > ft_lstsize(lst))
	{
		return (0);
	}
	value = *(int *)(ft_get_list_n(lst, num))->content;
	return (value);
}

// Get index in tlist.
int	ft_git(t_list *lst, int num)
{
	int	i;
	int	max;

	i = 1;
	max = ft_lstsize(lst);
	while (i <= max)
	{
		if (ft_gnl(lst, i) == num)
		{
			return (i);
		}
		i++;
	}
	return (0);
}
