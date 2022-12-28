/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:48:05 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/27 19:25:00 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free_philos(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->n_philos)
	{
		pthread_detach(state->philos[i].thid);
		pthread_mutex_destroy(&state->forks[i]);
		pthread_mutex_destroy(&state->philos[i].m_time);
		pthread_mutex_destroy(&state->philos[i].m_eat);
		i++;
	}
}

void	ft_free(t_state *state)
{
	ft_free_philos(state);
	pthread_mutex_destroy(&state->message);
	pthread_mutex_destroy(&state->m_dead);
	if (state->n_philos > 1)
	{
		pthread_detach(state->check_dead);
	}
	if (state->ntp_must_eat > 0)
	{
		pthread_detach(state->check_eats);
	}
	if (state->philos != NULL)
	{
		free(state->philos);
		state->philos = NULL;
	}
	if (state->forks != NULL)
	{
		free(state->forks);
		state->forks = NULL;
	}
}

void	ft_mutex_message_dead(t_state *state, int i)
{
	pthread_mutex_lock(&state->message);
	printf("%lld %d %s\n", ft_get_time(state), i, M_DIED);
	pthread_mutex_unlock(&state->message);
}

void	ft_mutex_message_eat_all(t_state *state)
{
	pthread_mutex_lock(&state->message);
	printf("%lld %s\n", ft_get_time(state), M_ALL);
	pthread_mutex_unlock(&state->message);
}

int	ft_mutex_message(t_philo *philo, char *str)
{
	t_state	*state;

	state = philo->state;
	pthread_mutex_lock(&state->message);
	if (ft_state_dead(state) == 1)
	{
		pthread_mutex_unlock(&state->message);
		return (0);
	}
	printf("%lld %d %s\n", ft_get_time(philo->state), philo->id, str);
	pthread_mutex_unlock(&state->message);
	return (1);
}
