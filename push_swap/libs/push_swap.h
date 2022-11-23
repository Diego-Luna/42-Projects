/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:34:41 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/23 12:42:41 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

// control
void	ft_arrange_3_format(t_list **l_a, t_list **l_b);
void	ft_arrange_5_format(t_list **l_a, t_list **l_b);

// utils
t_list *ft_get_list_n(t_list *lst, int num);
void	ft_print_list(t_list *lst);

// Movements
void	ft_mov_sb(t_list **lst);
void	ft_mov_sa(t_list **lst);
void	ft_mov_ss(t_list **l_a, t_list **l_b);

void	ft_mov_pa(t_list **l_a, t_list **l_b);
void	ft_mov_pb(t_list **l_a, t_list **l_b);

void	ft_mov_ra(t_list **l_a);
void	ft_mov_rb(t_list **l_b);
void	ft_mov_rr(t_list **l_a, t_list **l_b);

void	ft_mov_rra(t_list **l_a);
void	ft_mov_rrb(t_list **l_a);
void	ft_mov_rrr(t_list **l_a, t_list **l_b);

#endif
