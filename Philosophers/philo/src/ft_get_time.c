/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:20:06 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/29 17:20:06 by dluna-lo         ###   ########.fr       */
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

void	ft_sleep(t_state *state, int wait_time)
{
	long long	start;
	int			dead;

	dead = 0;
	pthread_mutex_lock(&state->m_dead);
	dead = state->death_occured;
	pthread_mutex_unlock(&state->m_dead);
	start = ft_get_time(state);
	while (dead == 0 && (ft_get_time(state) - start) < wait_time)
	{
		usleep(500);
		// usleep(10);
	}
	return ;
}

void	ft_print_state(t_state *state)
{
	int	i;

	i = 0;
	printf("\n state\n");
	printf(" n_philos{%d} t_die{%d} t_eat{%d} t_sleep{%d}", state->n_philos,
		state->t_die, state->t_eat, state->t_sleep);
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
