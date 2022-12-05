/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:38:37 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/05 16:46:25 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_index_organise(char *str_compare, char **strs)
{
	int	i;
	int	index;

	i = 1;
	index = 1;
	while (strs[i])
	{
		if (ft_atoi(str_compare) > ft_atoi(strs[i]))
		{
			index++;
		}
		i++;
	}
	return (index);
}

// This function creates a list with a table of strings.
// Receives the status of our project and the string
// of parameters.
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

// void	ft_push_swap(t_state *state, int zise)
void	ft_push_swap(t_state *state, int zise, char **argv)
{
	if (zise > 250)
		state->chunk = 30;
	else
		state->chunk = 15;
	state->addchunk = state->chunk;
	ft_create_lists_v2(state, argv);
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
	ft_free_tlist(state->l_a);
	ft_free_tlist(state->l_b);
}

int	ft_split_size_number_words(char *src, char sep)
{
	int	words;
	int	i;

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

int	main(int argc, char **argv)
{
	t_state	state;
	char	*split;
	int		is_str;

	state.l_a = NULL;
	state.l_b = NULL;
	is_str = 1;
	if (argc == 2 && ft_strchr(argv[1], ' ') != NULL)
	{
		split = ft_strjoin("push ", argv[1]);
		argc = ft_split_size_number_words(split, ' ');
		argv = ft_split(split, ' ');
		free(split);
		is_str = 2;
	}
	state.max_number = (argc - 1) + 1;
	if (argc > 2 && ft_check_params(argv) == 1)
		ft_push_swap(&state, (argc - 1), argv);
	else if (argc != 1)
		ft_exit();
	if (is_str == 2)
		ft_free_table(argv);
	return (0);
}
