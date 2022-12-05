/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:06:00 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/05 16:19:23 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(void)
{
	ft_printf("Error\n");
	exit(0);
}

// We make a whole tlist free.
void	ft_free_tlist(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
	{
		return ;
	}
	while (lst)
	{
		tmp = lst->next;
		free(lst->content);
		free(lst);
		lst = tmp;
	}
}

void	ft_free_table(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

// This function checks that they are organized from smallest
// to largest in the tlist, receives the starting and ending
// point. It returns a 1 if it is organized and if it is
// not it is 0.
int	ft_check_organize(t_list *lst, int start, int end)
{
	if (start <= 0)
	{
		start = 1;
	}
	while (start < end)
	{
		if (ft_gnl(lst, start) > ft_gnl(lst, start + 1))
		{
			return (0);
		}
		start++;
	}
	return (1);
}
