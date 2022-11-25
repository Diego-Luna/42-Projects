/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:24:04 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/25 18:53:32 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// The function that is responsible for the operation of
// sb, sa, ss
void	ft_mov_s_utils(t_list **lst)
{
	void	*tem;
	t_list	*c_first;

	if (ft_lstsize(*lst) < 1)
	{
		return ;
	}
	c_first = *lst;
	tem = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = tem;
}

void	ft_mov_sb(t_state *state)
{
	ft_mov_s_utils(&state->l_b);
	ft_printf("sb\n");
}

void	ft_mov_sa(t_state *state)
{
	ft_mov_s_utils(&state->l_a);
	ft_printf("sa\n");
}

void	ft_mov_ss(t_state *state)
{
	if (ft_lstsize(state->l_a) < 1 || ft_lstsize(state->l_b) < 1)
	{
		return ;
	}
	ft_mov_s_utils(&state->l_a);
	ft_mov_s_utils(&state->l_b);
	ft_printf("ss\n");
}
