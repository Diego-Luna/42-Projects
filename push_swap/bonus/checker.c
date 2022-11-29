/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 10:53:36 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/29 13:21:27 by dluna-lo         ###   ########.fr       */
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
	num = malloc(sizeof(int));
	*num = ft_atoi(argv[i]);
	state->l_a = ft_lstnew((void *)num);
	i++;
	while (argv[i])
	{
		num = malloc(sizeof(int *));
		*num = ft_atoi(argv[i]);
		tmp = ft_lstnew((void *)num);
		ft_lstadd_back(&state->l_a, tmp);
		i++;
	}
}

// This function checks that they are organized from smallest
// to largest in the tlist, receives the starting and ending
// point. It returns a 1 if it is organized and if it is
// not it is 0.
int	ft_check_organize(t_list *lst, int start, int end)
{
	if (start <= 0)
	{
		start = 1;
	}
	while (start < end)
	{
		if (ft_gnl(lst, start) > ft_gnl(lst, start + 1))
		{
			return (0);
		}
		start++;
	}
	return (1);
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

int	ft_check_comand(t_state *state, char *comand)
{
	int find = -1;
	ft_check_comand_family_s(state, comand, &find);
	ft_check_comand_family_p(state, comand, &find);
	ft_check_comand_family_r(state, comand, &find);
	ft_check_comand_family_rr(state, comand, &find);
	if (find == -1)
	{
		return (0);
	}
	return (1);
}

void	ft_checker(t_state *state)
{
	char	*movent;
	int		response;

	response = 0;
	while (1)
	{
		movent = get_next_line(0);
		if (movent == NULL)
			break ;
		response = ft_check_comand(state, movent);
		free(movent);
		if (response == 0)
		{
			ft_free_tlist(state->l_a);
			ft_free_tlist(state->l_b);
			ft_exit();
		}
	}
	if (ft_check_organize(state->l_a, 1, ft_lstsize(state->l_a)) == 1
		|| ft_lstsize(state->l_b) == 0 || state->error_tlist != -1)
		ft_printf("0K\n");
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_state	state;
	int		zise;

	state.l_a = NULL;
	state.l_b = NULL;
	zise = argc - 1;
	state.max_number = zise + 1;
	if (argc > 2 && ft_check_params(argv) == 1)
	{
		if (zise > 250)
			state.chunk = 30;
		else
			state.chunk = 15;
		state.addchunk = state.chunk;
		state.error_tlist = 0;
		ft_create_lists(&state, argv);
		ft_checker(&state);
		ft_free_tlist(state.l_a);
		ft_free_tlist(state.l_b);
	}
	return (0);
}
