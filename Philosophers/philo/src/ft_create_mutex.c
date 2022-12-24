/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_mutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:05:52 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/24 17:59:49 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_create_mutex(t_state *state)
{
	int	i;

	i = 0;
	pthread_mutex_init(&state->message, NULL);
	pthread_mutex_init(&state->m_dead, NULL);
	state->forks = malloc(sizeof(pthread_mutex_t) * state->n_philos);
	while (i < state->n_philos)
	{
		pthread_mutex_init(&state->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < state->n_philos)
	{
		pthread_mutex_init(&state->philos[i].m_time, NULL);
		pthread_mutex_init(&state->philos[i].m_eat, NULL);
		i++;
	}
}
