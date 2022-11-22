/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:34:41 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/21 19:09:57 by dluna-lo         ###   ########.fr       */
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

// Movements
void	ft_mov_sa_sb(t_list *lst);
void	ft_mov_ss(t_list *l_a, t_list *l_b);

void	ft_mov_pa(t_list *l_a, t_list *l_b);


#endif
