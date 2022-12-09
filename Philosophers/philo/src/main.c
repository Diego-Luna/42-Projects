/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:33:45 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/08 20:06:41 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	ft_get_time(t_state *state)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	if (state->time_start == 0)
	{
		return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
	}
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000)
		- state->time_start);
}


void	ft_create_philos(t_state *state)
{
	int	i;

	i = 0;
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
		state->philos[i].time_start = -1;
		state->philos[i].time_working = -1;
		i++;
	}
}

void	ft_print_state(t_state *state)
{
	int	i;

	i = 0;
	printf("\n Philos\n");
	while (i < state->n_philos)
	{
		printf(" id{%d}", state->philos[i].id);
		printf(" death{%d}", state->philos[i].death);
		printf(" l_fork{%d}", state->philos[i].l_fork);
		printf(" r_fork{%d}", state->philos[i].r_fork);
		printf(" n_of_meal{%d}", state->philos[i].n_of_meal);
		printf(" t_eat{%lld}", state->philos[i].time_eat);
		printf(" t_dead{%lld}", state->philos[i].time_dead);
		printf(" t_sleep{%lld}", state->philos[i].time_sleep);
		printf(" t_start{%lld}", state->philos[i].time_start);
		printf(" t_working{%lld}", state->philos[i].time_working);
		printf("\n");
		i++;
	}
}



int	main(int argc, char const **argv)
{
	t_state	state;

	if (argc >= 5 && argc <= 6 && ft_check_parans(argv) == 1)
	{
		// start state
		ft_init_state(&state, argc, argv);
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
	return (0);
}
