/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:06:00 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/29 11:01:22 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
