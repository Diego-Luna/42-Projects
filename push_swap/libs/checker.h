/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:34:41 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/05 16:36:03 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
// # include <stdio.h>
# include <errno.h>

typedef struct s_state
{
	struct s_list	*l_a;
	struct s_list	*l_b;
	int				chunk;
	int				addchunk;
	int				index;
	int				max_number;
	int				next;
	int				before_last;
	int				error_tlist;
}					t_state;

// Exit
void				ft_exit(void);
void				ft_free_tlist(t_list *lst);

// control
int					ft_check_comand_family_s(t_state *state, char *comand,
						int *find);
int					ft_check_comand_family_p(t_state *state, char *comand,
						int *find);
int					ft_check_comand_family_r(t_state *state, char *comand,
						int *find);
int					ft_check_comand_family_rr(t_state *state, char *comand,
						int *find);

// utils
int					ft_check_params(char **argv);
void				ft_create_lists(t_state *state, char **argv);

// utils tlist
t_list				*ft_get_list_n(t_list *lst, int num);
int					ft_git(t_list *lst, int num);

// get de value in int
int					ft_gnl(t_list *lst, int num);
int					ft_check_organize(t_list *lst, int start, int end);

// void				ft_print_list(t_list *lst);

// Movements
void				ft_mov_sb(t_state *state);
void				ft_mov_sa(t_state *state);
void				ft_mov_ss(t_state *state);

void				ft_mov_pa(t_state *state);
void				ft_mov_pb(t_state *state);

void				ft_mov_ra(t_state *state);
void				ft_mov_rb(t_state *state);
void				ft_mov_rr(t_state *state);

void				ft_mov_rra(t_state *state);
void				ft_mov_rrb(t_state *state);
void				ft_mov_rrr(t_state *state);

#endif
