/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa_pb_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 19:02:18 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/29 13:12:48 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_lst_add_front(t_list **orgin, t_list *new)
{
	void	*va_tem;

	new->next = (*orgin)->next->next;
	(*orgin)->next = new;
	va_tem = new->content;
	new->content = (*orgin)->content;
	(*orgin)->content = va_tem;
}

void	ft_mov_pa_utils(t_list **l_a, t_list **l_b)
{
	int		*num;
	t_list	*tem;
	t_list	*delete;

	if (ft_lstsize(*l_b) < 1)
	{
		return ;
	}
	num = malloc(sizeof(int));
	*num = *(int *)(*l_b)->content;
	tem = ft_lstnew((void *)num);
	ft_lstadd_front(l_a, tem);
	delete = *l_b;
	*l_b = (*l_b)->next;
	free(delete->content);
	free(delete);
}

void	ft_mov_pa(t_state *state)
{
	if (ft_lstsize(state->l_a) < 1 || ft_lstsize(state->l_b) < 1)
	{
		state->error_tlist = -1;
		return ;
	}
	ft_mov_pa_utils(&state->l_a, &state->l_b);
}

void	ft_mov_pb(t_state *state)
{
	if (ft_lstsize(state->l_a) < 1 || ft_lstsize(state->l_b) < 1)
	{
		state->error_tlist = -1;
		return ;
	}
	ft_mov_pa_utils(&state->l_b, &state->l_a);
}
