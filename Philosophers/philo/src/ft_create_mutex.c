/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_mutex.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:05:52 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/08 20:11:25 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_create_mutex(t_state *state)
{
	int	i;

	i = 0;
	state->forks = malloc(sizeof(pthread_mutex_t) * state->n_philos);
	while (i < state->n_philos)
	{
		pthread_mutex_init(state->forks, NULL);
		i++;
	}
	pthread_mutex_init(&state->message, NULL);
}
