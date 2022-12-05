/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb_ss_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:24:04 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/01 20:12:01 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// The function that is responsible for the operation of
// sb, sa, ss
void	ft_mov_s_utils(t_list **lst)
{
	void	*tem;

	if (ft_lstsize(*lst) < 1)
	{
		return ;
	}
	tem = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = tem;
}

void	ft_mov_sb(t_state *state)
{
	if (ft_lstsize(state->l_b) < 1)
	{
		state->error_tlist = -1;
		return ;
	}
	ft_mov_s_utils(&state->l_b);
}

void	ft_mov_sa(t_state *state)
{
	if (ft_lstsize(state->l_a) < 1)
	{
		state->error_tlist = -1;
		return ;
	}
	ft_mov_s_utils(&state->l_a);
}

void	ft_mov_ss(t_state *state)
{
	if (ft_lstsize(state->l_a) < 1 || ft_lstsize(state->l_b) < 1)
	{
		state->error_tlist = -1;
		return ;
	}
	ft_mov_s_utils(&state->l_a);
	ft_mov_s_utils(&state->l_b);
}
