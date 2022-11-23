/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:38:37 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/23 17:20:25 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	return (1);
}

void	ft_lstlast_new_table(t_list *lst, void *content)
{
	t_list	*tmp;

	tmp = ft_lstnew(content);
	ft_lstadd_back(&lst, tmp);
}

t_list	*ft_get_list_n(t_list *lst, int num)
{
	int	i;

	i = 1;
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

void	ft_print_list(t_list *lst)
{
	while (lst)
	{
		ft_printf("\n data:{%d}", *(int *)lst->content);
		lst = lst->next;
	}
}

void	ft_create_lists(t_list **l_a, char **argv)
{
	int		i;
	int		*num;
	t_list	*tmp;

	i = 1;
	num = malloc(sizeof(int));
	*num = ft_atoi(argv[i]);
	*l_a = ft_lstnew((void *)num);
	i++;
	while (argv[i])
	{
		num = malloc(sizeof(int *));
		*num = ft_atoi(argv[i]);
		tmp = ft_lstnew((void *)num);
		ft_lstadd_back(l_a, tmp);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_list	*l_a;
	t_list	*l_b;
	// int *num;

	l_a = NULL;
	l_b = NULL;
	if (argc > 2 && ft_check_params(argv) == 1)
	{
		ft_create_lists(&l_a, argv);

		// ft_printf("\n ** l-a");
		// ft_print_list(l_a);
		// ft_printf("\n ** l-b");
		// ft_print_list(l_b);
		// ft_printf("\n -- ft_arrange_3_format");

		// ft_arrange_3_format(&l_a, &l_b);
		ft_arrange_5_format(&l_a, &l_b);

		// ft_printf("\n ** new l-a");
		// ft_print_list(l_a);
		// ft_printf("\n ** new l-b");
		// ft_print_list(l_b);

		ft_free_tlist(l_a);
		ft_free_tlist(l_b);
		// ft_printf("\n Diego");
	}
	return (0);
}
