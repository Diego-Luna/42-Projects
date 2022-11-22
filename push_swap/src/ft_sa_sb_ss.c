/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa_sb_ss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:24:04 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/22 10:56:55 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mov_sb(t_list **lst)
{
	void *tem;
	t_list *c_first;

	if (ft_lstsize(*lst) < 1)
	{
		return ;
	}
	c_first = *lst;
	tem = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = tem;
	ft_printf("\nsb");
}
void	ft_mov_sa(t_list **lst)
{
	void *tem;
	t_list *c_first;

	if (ft_lstsize(*lst) < 1)
	{
		return ;
	}
	c_first = *lst;
	tem = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = tem;
	ft_printf("\nsa");
}

void	ft_mov_ss(t_list **l_a, t_list **l_b)
{
	void *tem;
	t_list *c_first;
	if (ft_lstsize(*l_a) < 1 || ft_lstsize(*l_b) < 1)
	{
		return ;
	}
	c_first = *l_a;
	tem = (*l_a)->content;
	(*l_a)->content = (*l_a)->next->content;
	(*l_a)->next->content = tem;

	c_first = *l_b;
	tem = (*l_b)->content;
	(*l_b)->content = (*l_b)->next->content;
	(*l_b)->next->content = tem;
	ft_printf("\nss");
}
