/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_pb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:02:18 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/21 19:21:31 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mov_pa(t_list *l_a, t_list *l_b)
{
	int *num;
	void *tem;
	t_list *new;
	t_list *new_lb;

	if (ft_lstsize(l_b) < 1)
	{
		return ;
	}
	num = malloc(sizeof(int));
	*num = *(int *)l_b->content;
	new = ft_lstnew((void *)num);
	ft_printf("\n D:{%d}", *(int *)new->content);
	tem = l_a->content;
	l_a->content = new->content;
	new->content = tem;
	new->next = l_a->next;
	l_a->next = new;

	free(l_b->content);
	new_lb = l_b->next;
	// free(l_b);
	*l_b = *new_lb;
}
