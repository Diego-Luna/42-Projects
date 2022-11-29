/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:38:37 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/28 18:52:28 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function receives the parameters of the program call, and
// checks if there are repeated numbers, returns 1 when they are
// repeated and 0 when they are not.
int ft_repeating_numbers(char **argv)
{
	int	i;
	int	ii;

	i = 0;
	while (argv[++i] && argv[i + 1])
	{
		ii = 0;
		while (argv[i + ++ii])
			if (ft_atoi(argv[i]) == ft_atoi(argv[i + ii]))
				return (1);
	}
	return (0);
}

// This function is responsible for checking the parameters
// of the program call
int	ft_check_params(char **argv)
{
	int	i;
	int	ii;

	i = 1;
	while (argv[i])
	{
		ii = 0;
		if (argv[i][ii] == '-')
			ii++;
		while (argv[i][ii])
		{
			if (ft_isdigit(argv[i][ii]) == 0)
				return (0);
			ii++;
		}
		if (ii < 1)
			return (0);
		i++;
	}
	if (i < 1)
		return (0);
	if (ft_repeating_numbers(argv) == 1)
	{
		return (0);
	}
	return (1);
}

// This function creates a new tlist, and puts it at the end
// of the list, receives the list to add to and the memory
// address of the value to add to the new tlist
void	ft_lstlast_new_table(t_list *lst, void *content)
{
	t_list	*tmp;

	tmp = ft_lstnew(content);
	ft_lstadd_back(&lst, tmp);
}

// This function returns the tlist at the indicated position,
// receives the tlist where to search and the position
t_list	*ft_get_list_n(t_list *lst, int num)
{
	int	i;

	i = 1;
	if (num == 0)
	{
		num = 1;
	}
	while (lst && i <= num)
	{
		if (i == num)
		{
			return (lst);
		}
		i++;
		lst = lst->next;
	}
	if (i == num)
	{
		return (lst);
	}
	return (NULL);
}

/*  This function returns the int value of the tlist at the
 indicated position, receives the tlist where to search
 and the position */
int	ft_gnl(t_list *lst, int num)
{
	int	value;

	if (num > ft_lstsize(lst))
	{
		return (0);
	}
	value = *(int *)(ft_get_list_n(lst, num))->content;
	return (value);
}

// Get index in tlist.
int	ft_git(t_list *lst, int num)
{
	int	i;
	int	max;

	i = 1;
	max = ft_lstsize(lst);
	while (i <= max)
	{
		if (ft_gnl(lst, i) == num)
		{
			return (i);
		}
		i++;
	}
	return (0);
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

// We make a whole tlist free.
void	ft_free_tlist(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
	{
		return ;
	}
	while (lst)
	{
		tmp = lst->next;
		free(lst->content);
		free(lst);
		lst = tmp;
	}
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

int	main(int argc, char **argv)
{
	t_state	state;
	int zise;

	state.l_a = NULL;
	state.l_b = NULL;
	zise =  argc - 1;
	state.max_number = zise + 1;
	if (argc > 2 && ft_check_params(argv) == 1)
	{
		if (zise > 250)
		{
			state.chunk = 30;
		}
		else
		{
			state.chunk = 15;
		}
		state.addchunk = state.chunk;
		ft_create_lists(&state, argv);
		if (zise <= 2)
		{
			ft_arrange_2_format(&state);
		}
		else if (zise <= 3)
		{
			ft_arrange_3_format(&state);
		}
		else if (zise <= 5)
		{
			ft_arrange_5_format(&state);
		}
		else
		{
				ft_big_to_b(&state);
				ft_sort_big_a(&state);
		}
		ft_free_tlist(state.l_a);
		ft_free_tlist(state.l_b);
	}
	else
	{
		ft_exit();
	}
	return (0);
}
