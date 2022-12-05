/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:38:37 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/05 15:31:59 by dluna-lo         ###   ########.fr       */
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

int	ft_find_index_organise(char *str_compare, char **strs)
{
	int i = 1;
	int index = 1;

	while (strs[i])
	{
		if (ft_atoi(str_compare) > ft_atoi(strs[i]))
		{
			index ++;
		}
		i++;
	}
	return (index);
}

void	ft_create_lists_v2(t_state *state, char **argv)
{
	int		i;
	int		*num;
	t_list	*tmp;

	i = 1;
	while (argv[i])
	{
		num = malloc(sizeof(int *));
		*num = ft_find_index_organise(argv[i], argv);
		tmp = ft_lstnew((void *)num);
		ft_lstadd_back(&state->l_a, tmp);
		i++;
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

// void	ft_push_swap(t_state *state, int zise, char **argv)
void	ft_push_swap(t_state *state, int zise)
{
	if (zise > 250)
		state->chunk = 30;
	else
		state->chunk = 15;
	state->addchunk = state->chunk;
	if (zise <= 2)
	{
		ft_arrange_2_format(state);
	}
	else if (zise <= 3)
	{
		ft_arrange_3_format(state);
	}
	else if (zise <= 5)
	{
		ft_arrange_5_format(state);
	}
	else
	{
		ft_arrange_big(state);
	}
}

int	ft_split_size_number_words(char *src, char sep)
{
	int		words;
	int		i;

	i = 0;
	words = 0;
	while (src[i])
	{
		while (src[i] == sep)
			i++;
		if (src[i] != sep && src[i])
			words++;
		while (src[i] != sep && src[i])
			i++;
	}
	return (words);
}

void ft_free_table(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	main(int argc, char **argv)
{
	t_state	state;
	int		zise;
	char	*split;
	int	is_str;

	state.l_a = NULL;
	state.l_b = NULL;
	zise = argc - 1;
	state.max_number = zise + 1;
	is_str = 1;
	if (ft_strchr(argv[1], ' ') != NULL && argc == 2)
	{
		split = ft_strjoin("push ", argv[1]);
		argc = ft_split_size_number_words(split, ' ');
		argv = ft_split(split, ' ');
		free(split);
		zise = argc - 1;
		state.max_number = zise + 1;
		is_str = 2;
	}
	if (argc >= 2 && ft_check_params(argv) == 1)
	{
		ft_create_lists_v2(&state, argv);
		ft_push_swap(&state, zise);
		ft_free_tlist(state.l_a);
		ft_free_tlist(state.l_b);
		if (is_str == 2)
		{
			ft_free_table(argv);
		}
	}
	else if (argc != 1)
	{
		ft_exit();
	}
	return (0);
}
