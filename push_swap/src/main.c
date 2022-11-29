/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:38:37 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/28 19:33:19 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

// We print in the terminal all the values of our test.
void	ft_print_list(t_list *lst)
{
	while (lst)
	{
		ft_printf("\n data:{%d}", *(int *)lst->content);
		lst = lst->next;
	}
}

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

void	ft_push_swap(t_state *state, int zise, char **argv)
{
	if (zise > 250)
		state->chunk = 30;
	else
		state->chunk = 15;
	state->addchunk = state->chunk;
	ft_create_lists(state, argv);
	if (zise <= 2)
		ft_arrange_2_format(state);
	else if (zise <= 3)
		ft_arrange_3_format(state);
	else if (zise <= 5)
		ft_arrange_5_format(state);
	else
		ft_arrange_big(state);
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
		ft_push_swap(&state, zise, argv);
		ft_free_tlist(state.l_a);
		ft_free_tlist(state.l_b);
	}
	return (0);
}
