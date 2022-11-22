/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:38:37 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/21 19:45:36 by dluna-lo         ###   ########.fr       */
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
	t_list  *tmp;
	t_list  *final;

	final = ft_lstlast(lst);
	tmp = ft_lstnew(content);
	final->next = tmp;
}

void ft_create_list_a(t_list *l_a, char**argv)
{
	int i = 1;
	int *num;

	num = malloc(sizeof(int));
	*num = ft_atoi(argv[i]);
	l_a->content = (void *)num;
	i++;
	while (argv[i])
	{
		num = malloc(sizeof(int));
		*num = ft_atoi(argv[i]);
		ft_lstlast_new_table(l_a, (void *)num);
		i++;
	}
}

void ft_print_list(t_list *lst)
{
	while (lst)
	{
		ft_printf("\n dieg:{%d}", *(int *)lst->content);
		lst = lst->next;
	}
}

void del(void* data)
{
		free(data);
		// (void)data;
}

void	ft_free_tlist(t_list *lst)
{
	int leng;
	t_list *tem;

	// ft_lstclear(&lst, &del);
	// leng = ft_lstsize(lst);
	// while (lst)
	// {
	// 	free(lst->content);
	// 	lst = lst->next;
	// }
	while (ft_lstsize(lst) > 0)
	{
		tem = ft_lstlast(lst);
		ft_lstdelone(ft_lstlast(lst), &del);
	}
	// free(lst->next);
	// ft_lstdelone();
	// ft_lstdelone(ft_lstlast(lst), &del);
	// (void)lst;
	// ft_printf("\n //{%d}", ft_lstsize(lst));
	// ft_lstdelone(ft_lstlast(lst), &del);
	// ft_printf("\n //{%d}", ft_lstsize(lst));
}

int	main(int argc, char **argv)
{
	t_list	l_a;

	if (argc > 2 && ft_check_params(argv) == 1)
	{
		ft_create_list_a(&l_a, argv);
		ft_print_list(&l_a);
		ft_free_tlist(&l_a);
		printf("\n Diego");
	}
	return (0);
}
// int	main(int argc, char **argv)
// {
// 	t_list	l_a;
// 	// t_list	l_b;

// 	if (argc > 2 && ft_check_params(argv) == 1)
// 	{
// 		ft_create_list_a(&l_a, argv);
// 		// ft_create_list_a(&l_b, argv);
// 		// ft_printf("\n - la");
// 		ft_print_list(&l_a);
// 		// ft_printf("\n - lb");
// 		// ft_print_list(&l_b);
// 		// ft_printf("\n ***");

// 		// ft_mov_pa(&l_a, &l_b);

// 		// ft_printf("\n - la");
// 		// ft_print_list(&l_a);
// 		// ft_printf("\n - lb");
// 		// ft_print_list(&l_b);
// 		ft_free_tlist(&l_a);
// 		// ft_free_tlist(&l_b);
// 		printf("\n Diego");
// 	}
// 	return (0);
// }
