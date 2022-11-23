/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra_rb_rr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:51:35 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/23 14:23:44 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mov_r_utils(t_list **l_1)
{
	void	*save_inicial;
	void	*save_tem;
	t_list	*l_tem_first;
	t_list	*l_tem_end;
	int		size[2];

	size[0] = 1;
	size[1] = ft_lstsize(*l_1);
	save_inicial = (*l_1)->content;
	while (size[1] > 1)
	{
		l_tem_first = ft_get_list_n(*l_1, size[0]);
		l_tem_end = ft_get_list_n(*l_1, size[0] + 1);
		save_tem = l_tem_first->content;
		l_tem_first->content = l_tem_end->content;
		l_tem_end->content = save_tem;
		size[1]--;
		size[0]++;
	}
}
// void	ft_mov_r_utils(t_list **l_1)
// {
// 	void *save_inicial;
// 	void *save_tem;
// 	t_list *l_tem_first;
// 	t_list *l_tem_end;
// 	int size;
// 	int i;

// 	i = 1;
// 	size = ft_lstsize(*l_1);
// 	save_inicial = (*l_1)->content;
// 	while (size > 1)
// 	{
// 		l_tem_first =ft_get_list_n(*l_1, i);
// 		l_tem_end =ft_get_list_n(*l_1, i + 1);
// 		save_tem = l_tem_first->content;
// 		l_tem_first->content = l_tem_end->content;
// 		l_tem_end->content = save_tem ;
// 		size--;
// 		i++;
// 	}
// }

void	ft_mov_ra(t_list **l_a)
{
	ft_mov_r_utils(l_a);
	ft_printf("ra\n");
}

void	ft_mov_rb(t_list **l_b)
{
	ft_mov_r_utils(l_b);
	ft_printf("rb\n");
}

void	ft_mov_rr(t_list **l_a, t_list **l_b)
{
	ft_mov_r_utils(l_a);
	ft_mov_r_utils(l_b);
	ft_printf("rr\n");
}
