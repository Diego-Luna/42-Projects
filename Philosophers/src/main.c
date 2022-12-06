/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:33:45 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/06 17:53:52 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_number(char const **argv)
{
	int i = 1;
	int ii = 0;

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

int main(int argc, char const **argv)
{
	t_state state;

	if (argc >= 5 && argc <= 6 && ft_check_number(argv) == 1)
	{
		state.n_philo = ft_atoi (argv[1]);
		state.t_die = ft_atoi (argv[2]);
		state.t_eat = ft_atoi (argv[3]);
		state.t_sleep = ft_atoi (argv[4]);
		if (argc == 6)
			state.ntp_must_eat = ft_atoi (argv[5]);
		else
			state.ntp_must_eat = 0;
		ft_printf("\nDiego philosophers.h\n");
	}
	return 0;
}
