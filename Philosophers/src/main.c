/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:33:45 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/07 18:54:45 by dluna-lo         ###   ########.fr       */
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

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	size_t	result;

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

void	ft_create_mutex(t_state *state)
{
	int i = 0;

	state->forks = malloc(sizeof(pthread_mutex_t) * state->n_philos);
	while (i < state->n_philos)
	{
		pthread_mutex_init(state->forks, NULL);
		i++;
	}
}

void	ft_create_philos(t_state *state)
{
	int i = 0;

	state->philos = malloc(sizeof(t_philo) * state->n_philos);
	while (i < state->n_philos)
	{
		state->philos[i].id = i + 1;
		state->philos[i].death = 0;
		state->philos[i].l_fork = i;
		state->philos[i].r_fork = (i + 1) % state->n_philos;
		state->philos[i].n_of_meal = state->ntp_must_eat;
		state->philos[i].time_eat = state->t_eat;
		state->philos[i].time_dead = state->t_die;
		state->philos[i].time_sleep = state->t_sleep;
		i++;
	}
}

void	ft_print_state(t_state *state)
{
	int i = 0;

	printf("\n Philos\n");
	while (i < state->n_philos)
	{
		printf(" id{%d}", state->philos[i].id);
		printf(" death{%d}", state->philos[i].death);
		printf(" l_fork{%d}", state->philos[i].l_fork);
		printf(" r_fork{%d}", state->philos[i].r_fork);
		printf(" n_of_meal{%d}", state->philos[i].n_of_meal);
		printf(" time_eat{%lld}", state->philos[i].time_eat);
		printf(" time_dead{%lld}", state->philos[i].time_dead);
		printf(" time_sleep{%lld}", state->philos[i].time_sleep);
		printf("\n");
		i++;
	}
}

int main(int argc, char const **argv)
{
	t_state state;

	if (argc >= 5 && argc <= 6 && ft_check_number(argv) == 1 && ft_max_int(argv) == 1 && ft_positive_number(argv) == 1)
	{
		state.n_philos = ft_atoi (argv[1]);
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
			state.ntp_must_eat = -1;
		}
		// create mutex
		ft_create_mutex(&state);
		// create philos
		ft_create_philos(&state);
		// create threads
		// 	check eating, think, etc.
		// 	todo print state philo
		ft_print_state(&state);
		state.time_working = ft_get_time(&state);
		printf("\n{%lld}", state.time_working);
		printf("\nDiego philosophers.h\n");
	}
	return 0;
}
