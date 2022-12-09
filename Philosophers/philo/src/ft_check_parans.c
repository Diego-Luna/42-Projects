/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parans.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:01:24 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/08 20:04:01 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long int	ft_atoilz(const char *str)
{
	long int	i;
	int			sign;
	long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

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

int	ft_check_parans(char const **argv)
{
	if (ft_check_number(argv) == 1 && ft_max_int(argv) == 1 && ft_positive_number(argv) == 1)
	{
		return (1);
	}
	return (0);
}