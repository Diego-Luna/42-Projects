/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange_2_to_5_format.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:22:11 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/28 19:11:06 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_arrange_2_format(t_state *state)
{
	if (ft_check_organize(state->l_a, 1, 2) == 1)
	{
		return ;
	}
	ft_mov_sa(state);
}

void	ft_arrange_3_format(t_state *state)
{
	int	num_t1;
	int	num_t2;
	int	num_t3;

	if (ft_check_organize(state->l_a, 1, 3) == 1)
		return ;
	num_t1 = ft_gnl(state->l_a, 1);
	num_t2 = ft_gnl(state->l_a, 2);
	num_t3 = ft_gnl(state->l_a, 3);
	if (num_t1 > num_t2 && num_t1 < num_t3)
		ft_mov_sa(state);
	else if (num_t1 > num_t2 && num_t1 > num_t3 && num_t2 > num_t3)
	{
		ft_mov_sa(state);
		ft_mov_rra(state);
	}
	else if (num_t1 > num_t2 && num_t1 > num_t3 && num_t2 < num_t3)
		ft_mov_ra(state);
	else if (num_t1 < num_t2 && num_t2 > num_t3 && num_t1 < num_t3)
	{
		ft_mov_sa(state);
		ft_mov_ra(state);
	}
	else if (num_t1 > num_t3 && num_t1 < num_t2 && num_t2 > num_t3)
		ft_mov_rra(state);
}

void	ft_arrange_5_format(t_state *state)
{
	int	zise;

	zise = ft_lstsize(state->l_a) - 3;
	if (ft_check_organize(state->l_a, 1, ft_lstsize(state->l_a)) == 1)
		return ;
	while (ft_gnl(state->l_a, 4) != 0)
	{
		if (ft_gnl(state->l_a, 1) <= zise)
			ft_mov_pb(state);
		else
		{
			if (ft_gnl(state->l_a, ft_lstsize(state->l_a)) <= zise)
				ft_mov_rra(state);
			else
				ft_mov_ra(state);
		}
	}
	ft_arrange_3_format(state);
	if (ft_gnl(state->l_b, 1) < ft_gnl(state->l_b, 2))
		ft_mov_sb(state);
	while (ft_gnl(state->l_b, 1) != 0)
		ft_mov_pa(state);
}
