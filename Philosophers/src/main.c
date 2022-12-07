/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:33:45 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/07 17:21:49 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

long long ft_get_time(t_state *state)
{
	struct timeval current_time;

  gettimeofday(&current_time, NULL);

	if (state->time_start == 0)
	{
		return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
	}
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000) - state->time_start);
}

int main(int argc, char const **argv)
{
	t_state state;

	if (argc >= 5 && argc <= 6 && ft_check_number(argv) == 1 && ft_max_int(argv) == 1 && ft_positive_number(argv) == 1)
	{
		state.n_philo = ft_atoi (argv[1]);
		state.t_die = ft_atoi (argv[2]);
		state.t_eat = ft_atoi (argv[3]);
		state.t_sleep = ft_atoi (argv[4]);
		state.death_occured = 0;
		state.error = 0;
		state.time_start = 0;
		state.time_start = ft_get_time(&state);
		if (argc == 6)
		{
			state.ntp_must_eat = ft_atoi (argv[5]);
		}
		else
		{
			state.ntp_must_eat = 0;
		}
		state.time_working = ft_get_time(&state);
		ft_printf("\n{%d}", state.time_working);
		ft_printf("\nDiego philosophers.h\n");
	}
	return 0;
}
