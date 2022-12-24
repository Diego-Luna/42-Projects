/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_mutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:05:52 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/23 18:03:13 by dluna-lo         ###   ########.fr       */
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
}
