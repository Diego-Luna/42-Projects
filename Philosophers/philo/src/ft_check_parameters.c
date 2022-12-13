/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parameters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:01:24 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/13 11:12:43 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_number(char const **argv)
{
	int	i;
	int	ii;

	i = 1;
	ii = 0;
	while (argv[i])
	{
		ii = 0;
		while (argv[i][ii])
		{
			if (ft_isdigit(argv[i][ii]) == 0)
			{
				return (0);
			}
			ii++;
		}
		i++;
	}
	return (1);
}

int	ft_max_int(char const **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoilz(argv[i]) > 2147483647 || ft_atoilz(argv[i]) < -2147483648)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_positive_number(char const **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (ft_atoilz(argv[i]) <= 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_parameters(char const **argv)
{
	if (ft_check_number(argv) == 1 && ft_max_int(argv) == 1
		&& ft_positive_number(argv) == 1)
	{
		return (1);
	}
	return (0);
}
