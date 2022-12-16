/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:16:56 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/16 11:31:06 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_sleep_and_think(t_philo *philo)
{
	t_state	*state;

	state = philo->state;
	ft_mutex_message(philo, M_SLEE, O_NORMAL);
	ft_sleep(philo->state, philo->time_sleep);
	ft_mutex_message(philo, M_THIN, O_NORMAL);
}

void	*thread_check(void *arg)
{
	t_state	*state;
	int		ntp_must_eat;

	ntp_must_eat = 0;
	state = arg;
	pthread_mutex_lock(&state->m_check_dead);
	state->death_occured = ft_check_dead(state);
	ntp_must_eat = state->ntp_must_eat;
	pthread_mutex_unlock(&state->m_check_dead);
	while (state->death_occured == 0 && ntp_must_eat != 0)
	{
		pthread_mutex_lock(&state->m_check_dead);
		state->death_occured = ft_check_dead(state);
		ntp_must_eat = state->ntp_must_eat;
		pthread_mutex_unlock(&state->m_check_dead);
		if (state->death_occured > 0)
		{
			break ;
		}
	}
	return (0);
}

void	*thread(void *arg)
{
	t_philo	*philo;
	t_state	*state;

	philo = arg;
	state = philo->state;
	pthread_mutex_lock(&state->m_check_dead);
	philo->time_start = ft_get_time(state);
	philo->death = state->death_occured;
	pthread_mutex_unlock(&state->m_check_dead);
	while (philo->death == 0 && (philo->n_of_meal > 0 || philo->n_of_meal < 0))
	{
		pthread_mutex_lock(&state->m_check_dead);
		philo->death = state->death_occured;
		pthread_mutex_unlock(&state->m_check_dead);
		ft_taken_fork(philo);
		ft_eating(philo);
		ft_sleep_and_think(philo);
	}
	pthread_mutex_lock(&state->m_check_dead);
	philo->death = 1;
	pthread_mutex_unlock(&state->m_check_dead);
	return (0);
}
