/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange_3_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:22:11 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/23 17:23:02 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_arrange_3_format(t_list **l_a, t_list **l_b)
{
	int	num_t1;
	int	num_t2;
	int	num_t3;

	(void)l_b;
	num_t1 = *(int *)(*l_a)->content;
	num_t2 = *(int *)(*l_a)->next->content;
	num_t3 = *(int *)(*l_a)->next->next->content;
	if (num_t1 > num_t2 && num_t1 < num_t3)
		ft_mov_sa(l_a);
	else if (num_t1 > num_t2 && num_t1 > num_t3 && num_t2 > num_t3)
	{
		ft_mov_sa(l_a);
		ft_mov_rra(l_a);
	}
	else if (num_t1 > num_t2 && num_t1 > num_t3 && num_t2 < num_t3)
		ft_mov_ra(l_a);
	else if (num_t1 < num_t2 && num_t2 > num_t3 && num_t1 < num_t3)
	{
		ft_mov_sa(l_a);
		ft_mov_ra(l_a);
	}
	else if (num_t1 > num_t3 && num_t1 < num_t2 && num_t2 > num_t3)
		ft_mov_rra(l_a);
}

void	ft_arrange_5_format(t_list **l_a, t_list **l_b)
{
	int	num_t1;
	int i;

	i = ft_lstsize(*l_a) - 3;
	// ft_printf("\n i-1-{%d}", i);
	while (i > 0)
	{
		ft_mov_pb(l_a, l_b);
		i--;
	}
	i = ft_lstsize(*l_b);
	// ft_printf("\n i-2-{%d}", i);
	if (i > 1 && *(int *)(*l_b)->content > *(int *)(*l_b)->next->content)
	{
		ft_mov_sb(l_b);
	}
	ft_arrange_3_format(l_a, l_b);

	// ft_printf("\n ++ p l-a");
	// ft_print_list(*l_a);
	// ft_printf("\n ++ p l-b");
	// ft_print_list(*l_b);

	while (i > 0)
	{
		num_t1 = *(int *)(*l_b)->content;
		// if (num_t1 > *(int *)(ft_get_list_n(*l_a, 3))->content)
		if (num_t1 > *(int *)(ft_get_list_n(*l_a, ft_lstsize(*l_a)))->content)
		{
			// ft_printf("\n Acctions 1\n");
			ft_mov_pa(l_a, l_b);
			ft_mov_ra(l_a);
		}
		else if (num_t1 > *(int *)(ft_get_list_n(*l_a, 1))->content && num_t1 < *(int *)(ft_get_list_n(*l_a, 2))->content)
		{
			// ft_printf("\n Acctions 2\n");
			ft_mov_pa(l_a, l_b);
			ft_mov_sa(l_a);
		}
		else if (num_t1 < *(int *)(ft_get_list_n(*l_a, 1))->content && num_t1 < *(int *)(ft_get_list_n(*l_a, 2))->content)
		{
			// ft_printf("\n Acctions 3\n");
			ft_mov_pa(l_a, l_b);
		}
		else if (num_t1 > *(int *)(ft_get_list_n(*l_a, 1))->content && num_t1 < *(int *)(ft_get_list_n(*l_a, ft_lstsize(*l_a)))->content && i == 1 &&  num_t1 > *(int *)(ft_get_list_n(*l_a, 3))->content)
		{
			// ft_printf("\n Acctions 4\n");
			ft_mov_rra(l_a);
			ft_mov_pa(l_a, l_b);
		// 	ft_mov_sa(l_a);
			ft_mov_ra(l_a);
			ft_mov_ra(l_a);
		}
		else if (num_t1 > *(int *)(ft_get_list_n(*l_a, 1))->content && num_t1 < *(int *)(ft_get_list_n(*l_a, ft_lstsize(*l_a)))->content && i == 1)
		{
			// ft_printf("\n Acctions 5\n");
			ft_mov_pb(l_a, l_b);
			ft_mov_pb(l_a, l_b);
			ft_mov_rrb(l_a);
			ft_mov_pa(l_a, l_b);
			ft_mov_pa(l_a, l_b);
			ft_mov_pa(l_a, l_b);
		}
		else if (num_t1 > *(int *)(ft_get_list_n(*l_a, 1))->content && num_t1 < *(int *)(ft_get_list_n(*l_a, ft_lstsize(*l_a)))->content && i == 2)
		{
			// ft_printf("\n Acctions 6\n");
			ft_mov_pa(l_a, l_b);
			ft_mov_rra(l_a);
			ft_mov_sa(l_a);
			ft_mov_ra(l_a);
			ft_mov_ra(l_a);
		}
		i--;
	}
}
