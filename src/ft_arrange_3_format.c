/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange_3_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:22:11 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/25 18:03:55 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_arrange_2_format(t_state *state)
{
	if (ft_check_organize(state->l_a, 1, 2) == 1)
	{
		return;
	}
	ft_mov_sa(state);
}

void	ft_arrange_3_format(t_state *state)
{
	int	num_t1;
	int	num_t2;
	int	num_t3;

	if (ft_check_organize(state->l_a, 1, 3) == 1)
	{
		// ft_printf("\n D{%d}\n", ft_check_organize(state->l_a, 1, 3));
		return;
	}
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
	int	num_t1;
	int i;

	i = ft_lstsize(state->l_a) - 3;
	while (i > 0 && ft_check_organize(state->l_a, 2, 4) == 0)
	{
		ft_mov_pb(state);
		i--;
	}
	i = ft_lstsize(state->l_b);
	if (i > 1 && ft_gnl(state->l_b, 1) > ft_gnl(state->l_b, 2))
	{
		ft_mov_sb(state);
	}
	ft_arrange_3_format(state);
	while (i > 0)
	{
		num_t1 = ft_gnl(state->l_b, 1);
		if (num_t1 > ft_gnl(state->l_a, ft_lstsize(state->l_a)))
		{
			ft_mov_pa(state);
			ft_mov_ra(state);
		}
		else if (num_t1 > ft_gnl(state->l_a, 1) && num_t1 < ft_gnl(state->l_a, 2))
		{
			ft_mov_pa(state);
			ft_mov_sa(state);
		}
		else if (num_t1 < ft_gnl(state->l_a, 1) && num_t1 < ft_gnl(state->l_a, 2))
		{
			ft_mov_pa(state);
		}
		else if (num_t1 > ft_gnl(state->l_a, 1) && num_t1 < ft_gnl(state->l_a, ft_lstsize(state->l_a)) && i == 1 &&  num_t1 > ft_gnl(state->l_a, 3))
		{
			ft_mov_rra(state);
			ft_mov_pa(state);
			ft_mov_ra(state);
			ft_mov_ra(state);
		}
		else if (num_t1 > ft_gnl(state->l_a, 1) && num_t1 < ft_gnl(state->l_a, ft_lstsize(state->l_a)) && i == 1)
		{
			ft_mov_pb(state);
			ft_mov_pb(state);
			ft_mov_rrb(state);
			ft_mov_pa(state);
			ft_mov_pa(state);
			ft_mov_pa(state);
		}
		else if (num_t1 > ft_gnl(state->l_a, 1) && num_t1 < ft_gnl(state->l_a, ft_lstsize(state->l_a)) && i == 2)
		{
			ft_mov_pa(state);
			ft_mov_rra(state);
			ft_mov_sa(state);
			ft_mov_ra(state);
			ft_mov_ra(state);
		}
		i--;
	}
}

void	ft_arrange_formats(t_state *state)
{
	int	num_t1;
	int i;

	i = ft_lstsize(state->l_a) - 3;
	while (i > 0 && ft_check_organize(state->l_a, 2, 4) == 0)
	{
		ft_mov_pb(state);
		i--;
	}
	i = ft_lstsize(state->l_b);
	if (i > 1 && ft_gnl(state->l_b, 1) > ft_gnl(state->l_b, 2))
	{
		ft_mov_sb(state);
	}
	ft_arrange_3_format(state);
	while (i > 0)
	{
		num_t1 = ft_gnl(state->l_b, 1);
		if (num_t1 > ft_gnl(state->l_a, ft_lstsize(state->l_a)))
		{
			ft_mov_pa(state);
			ft_mov_ra(state);
		}
		else if (num_t1 > ft_gnl(state->l_a, 1) && num_t1 < ft_gnl(state->l_a, 2))
		{
			ft_mov_pa(state);
			ft_mov_sa(state);
		}
		else if (num_t1 < ft_gnl(state->l_a, 1) && num_t1 < ft_gnl(state->l_a, 2))
		{
			ft_mov_pa(state);
		}
		else if (num_t1 > ft_gnl(state->l_a, 1) && num_t1 < ft_gnl(state->l_a, ft_lstsize(state->l_a)) && i == 1 &&  num_t1 > ft_gnl(state->l_a, 3))
		{
			ft_mov_rra(state);
			ft_mov_pa(state);
			ft_mov_ra(state);
			ft_mov_ra(state);
		}
		else if (num_t1 > ft_gnl(state->l_a, 1) && num_t1 < ft_gnl(state->l_a, ft_lstsize(state->l_a)) && i == 1)
		{
			ft_mov_pb(state);
			ft_mov_pb(state);
			ft_mov_rrb(state);
			ft_mov_pa(state);
			ft_mov_pa(state);
			ft_mov_pa(state);
		}
		else if (num_t1 > ft_gnl(state->l_a, 1) && num_t1 < ft_gnl(state->l_a, ft_lstsize(state->l_a)) && i == 2)
		{
			ft_mov_pa(state);
			ft_mov_rra(state);
			ft_mov_sa(state);
			ft_mov_ra(state);
			ft_mov_ra(state);
		}
		i--;
	}
}
