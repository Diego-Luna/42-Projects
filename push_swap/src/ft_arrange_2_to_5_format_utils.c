/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrange_2_to_5_format_utils.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 16:12:18 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/05 16:15:35 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_the_2_bigger_value(t_list *list, int value)
{
	int	i;
	int	ii;
	int	smallest;

	i = ft_lstsize(list);
	ii = 1;
	if (ft_lstsize(list) <= 0)
	{
		return (0);
	}
	smallest = ft_gnl(list, 1);
	while (ii < i)
	{
		if (smallest < ft_gnl(list, ii + 1) && value != ft_gnl(list, ii + 1))
		{
			smallest = ft_gnl(list, ii + 1);
		}
		ii++;
	}
	return (smallest);
}

int	ft_the_smallest_value(t_list *list)
{
	int	i;
	int	ii;
	int	smallest;

	i = ft_lstsize(list);
	ii = 1;
	if (ft_lstsize(list) <= 0)
	{
		return (0);
	}
	smallest = ft_gnl(list, 1);
	while (ii < i)
	{
		if (smallest > ft_gnl(list, ii + 1))
		{
			smallest = ft_gnl(list, ii + 1);
		}
		ii++;
	}
	return (smallest);
}

int	ft_the_bigger_value(t_list *list)
{
	int	i;
	int	ii;
	int	smallest;

	i = ft_lstsize(list);
	ii = 1;
	if (ft_lstsize(list) <= 0)
	{
		return (0);
	}
	smallest = ft_gnl(list, 1);
	while (ii < i)
	{
		if (smallest < ft_gnl(list, ii + 1))
		{
			smallest = ft_gnl(list, ii + 1);
		}
		ii++;
	}
	return (smallest);
}
