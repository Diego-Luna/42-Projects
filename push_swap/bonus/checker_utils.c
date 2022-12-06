/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 19:03:47 by diegofranci       #+#    #+#             */
/*   Updated: 2022/12/06 14:28:07 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// This function creates a list with a table of strings.
// Receives the status of our project and the string
// of parameters.
void	ft_create_lists(t_state *state, char **argv)
{
	int		i;
	int		*num;
	t_list	*tmp;

	i = 1;
	while (argv[i])
	{
		num = malloc(sizeof(int *));
		*num = ft_atoi(argv[i]);
		tmp = ft_lstnew((void *)num);
		ft_lstadd_back(&state->l_a, tmp);
		i++;
	}
}

int	ft_check_comand_family_s(t_state *state, char *comand, int *find)
{
	if (ft_strncmp(comand, "sb\n", 3) == 0)
	{
		ft_mov_sb(state);
	}
	else if (ft_strncmp(comand, "sa\n", 3) == 0)
	{
		ft_mov_sa(state);
	}
	else if (ft_strncmp(comand, "ss\n", 3) == 0)
	{
		ft_mov_ss(state);
	}
	else
	{
		return (0);
	}
	*find = 1;
	return (1);
}

int	ft_check_comand_family_p(t_state *state, char *comand, int *find)
{
	if (ft_strncmp(comand, "pa\n", 3) == 0)
	{
		ft_mov_pa(state);
	}
	else if (ft_strncmp(comand, "pb\n", 3) == 0)
	{
		ft_mov_pb(state);
	}
	else
	{
		return (0);
	}
	*find = 1;
	return (1);
}

int	ft_check_comand_family_r(t_state *state, char *comand, int *find)
{
	if (ft_strncmp(comand, "ra\n", 3) == 0)
	{
		ft_mov_ra(state);
	}
	else if (ft_strncmp(comand, "rb\n", 3) == 0)
	{
		ft_mov_rb(state);
	}
	else if (ft_strncmp(comand, "rr\n", 3) == 0)
	{
		ft_mov_rr(state);
	}
	else
	{
		return (0);
	}
	*find = 1;
	return (1);
}

int	ft_check_comand_family_rr(t_state *state, char *comand, int *find)
{
	if (ft_strncmp(comand, "rra\n", 3) == 0)
	{
		ft_mov_rra(state);
	}
	else if (ft_strncmp(comand, "rrb\n", 3) == 0)
	{
		ft_mov_rrb(state);
	}
	else if (ft_strncmp(comand, "rrr\n", 3) == 0)
	{
		ft_mov_rrr(state);
	}
	else
	{
		return (0);
	}
	*find = 1;
	return (1);
}
