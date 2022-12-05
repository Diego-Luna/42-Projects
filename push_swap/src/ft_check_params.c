/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 19:27:18 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/05 16:00:10 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// This function receives the parameters of the program call, and
// checks if there are repeated numbers, returns 1 when they are
// repeated and 0 when they are not.
int	ft_repeating_numbers(char **argv)
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

int	ft_max_int(char **argv)
{
	int i = 1;

	while (argv[i])
	{
		if (ft_atoilz(argv[i]) > 2147483647 || ft_atoilz(argv[i]) < -2147483648)
		{
			return (1);
		}
		i++;
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
	if (ft_repeating_numbers(argv) == 1 || ft_max_int(argv) == 1)
		return (0);
	return (1);
}
