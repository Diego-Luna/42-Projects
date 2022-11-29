/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange_big.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 14:17:22 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/28 18:47:21 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_smaller_chunk(t_list *list, int chunk, int number)
{
	int i;
	int ii;
	int first;
	int last;

	i = 1;
	while (ft_gnl(list, i) <= ((number / 2) - chunk)
		  || ft_gnl(list, i) >= ((number / 2) + chunk))
	{
		i++;
	}
	first = ft_gnl(list, i);
	ii = ft_lstsize(list) - 1;
	// ii = ft_lstsize(list);
	while (ft_gnl(list, ii) <= ((number / 2) - chunk) || ft_gnl(list, ii) >= ((number / 2) + chunk))
	{
		ii--;
	}
	last = ft_gnl(list, ii);
	if (number - ii < i)
	{
		return (last);
	}
	return (first);
}

int ft_remaining_numbers(t_list *list, int chunk, int n_total)
{
	int i;
	int max;

	i = 1;
	max = ft_lstsize(list);
	while (i <= max)
	{
		if (ft_gnl(list, i) > ((n_total / 2) - chunk) &&
				ft_gnl(list, i) < ((n_total / 2) + chunk))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_big_to_b(t_state *state)
{
	while (ft_gnl(state->l_a, 1) != 0)
	{
		state->next = ft_find_smaller_chunk(state->l_a, state->chunk, state->max_number);
		state->index = ft_git(state->l_a, state->next);
		// ft_printf("\n state->index{%d}, state->next{%d}", state->index, state->next);
		// exit(1);
		while (ft_gnl(state->l_a, 1) != state->next)
		{
			if (state->index < (ft_lstsize(state->l_a) / 2))
			{
				ft_mov_ra(state);
			}
			else
			{
				ft_mov_rra(state);
			}
		}
		ft_mov_pb(state);
		if (ft_gnl(state->l_b, 0) < state->max_number / 2 && ft_lstsize(state->l_b) != 0)
		{
			ft_mov_rb(state);
		}
		if (ft_remaining_numbers(state->l_a, state->chunk, state->max_number) == 1)
		{
			state->chunk += state->addchunk;
		}
	}
	state->before_last = 0;
	state->next = state->max_number -1;
}

void ft_sort_big_a(t_state *state)
{
	while (ft_gnl(state->l_b, 1) != 0)
	{
		state->index = ft_git(state->l_b, state->next);
		while (ft_gnl(state->l_b, 1) != state->next)
		{
			if (ft_gnl(state->l_b, 1) == state->next - 1)
			{
				ft_mov_pa(state);
				state->before_last = 1;
			}else if (state->index < ft_lstsize(state->l_b) / 2)
			{
				ft_mov_rb(state);
			}
			else
			{
				ft_mov_rrb(state);
			}
		}
		ft_mov_pa(state);
		if (state->before_last == 1)
		{
			state->next -= 2;
			state->before_last = 0;
			ft_mov_sa(state);
		}
		else
		{
			state->next--;
		}
	}
}