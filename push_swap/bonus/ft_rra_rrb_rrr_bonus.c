/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra_rrb_rrr_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 11:27:06 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/01 20:11:56 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_mov_rr_utils(t_list **l_1)
{
	void	*save_tem;
	t_list	*l_tem_first;
	t_list	*l_tem_end;
	int		size[2];

	size[0] = 1;
	size[1] = ft_lstsize(*l_1);
	while (size[1] > 1)
	{
		l_tem_first = ft_get_list_n(*l_1, size[1]);
		l_tem_end = ft_get_list_n(*l_1, size[1] - 1);
		save_tem = l_tem_first->content;
		l_tem_first->content = l_tem_end->content;
		l_tem_end->content = save_tem;
		size[1]--;
		size[0]++;
	}
}

void	ft_mov_rra(t_state *state)
{
	if (ft_lstsize(state->l_a) < 1)
	{
		state->error_tlist = -1;
		return ;
	}
	ft_mov_rr_utils(&state->l_a);
}

void	ft_mov_rrb(t_state *state)
{
	if (ft_lstsize(state->l_b) < 1)
	{
		state->error_tlist = -1;
		return ;
	}
	ft_mov_rr_utils(&state->l_b);
}

void	ft_mov_rrr(t_state *state)
{
	if (ft_lstsize(state->l_a) < 1 || ft_lstsize(state->l_b) < 1)
	{
		state->error_tlist = -1;
		return ;
	}
	ft_mov_rr_utils(&state->l_a);
	ft_mov_rr_utils(&state->l_b);
}
