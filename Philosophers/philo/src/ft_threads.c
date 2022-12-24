/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:16:56 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/24 15:46:59 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_philo_sleep(t_philo *philo)
{
	t_state	*state;

	state = philo->state;
	if (ft_mutex_message(philo, M_SLEE, O_NORMAL) == 0)
	{
		return (0);
	}
	ft_sleep(state, philo->time_sleep);
	return (1);
}
int	ft_think(t_philo *philo)
{
	t_state	*state;

	state = philo->state;
	if (ft_mutex_message(philo, M_THIN, O_NORMAL) == 0)
	{
		return (0);
	}
	return (1);
}

void	*thread_check(void *arg)
{
	t_state	*state;
	int i;

	i = 0;
	state = arg;
	while (ft_state_dead(state) == 0)
	{
		pthread_mutex_lock(&state->m_time);
		if ((ft_get_time(state) - state->philos[i].t_last_eat) > state->philos[i].time_dead)
		{
			pthread_mutex_lock(&state->m_dead);
			state->death_occured = 1;
			pthread_mutex_unlock(&state->m_dead);
			pthread_mutex_unlock(&state->m_time);
			ft_mutex_message_dead(state, i + 1);
			return (0);
		}
		pthread_mutex_unlock(&state->m_time);
		i = (i + 1) % state->n_philos;
	}
	return (0);
}
// void	*thread_check(void *arg)
// {
// 	t_state	*state;
// 	int		ntp_must_eat;

// 	ntp_must_eat = 0;
// 	state = arg;
// 	pthread_mutex_lock(&state->m_dead);
// 	state->death_occured = ft_check_dead(state);
// 	ntp_must_eat = state->ntp_must_eat;
// 	pthread_mutex_unlock(&state->m_dead);
// 	while (state->death_occured == 0 && ntp_must_eat != 0)
// 	{
// 		pthread_mutex_lock(&state->m_dead);
// 		state->death_occured = ft_check_dead(state);
// 		ntp_must_eat = state->ntp_must_eat;
// 		pthread_mutex_unlock(&state->m_dead);
// 		if (state->death_occured > 0)
// 		{
// 			break ;
// 		}
// 	}
// 	return (0);
// }

int	ft_state_dead(t_state *state)
{
	pthread_mutex_lock(&state->m_dead);
	if (state->death_occured == 1)
	{
		pthread_mutex_unlock(&state->m_dead);
		return (1);
	}
	pthread_mutex_unlock(&state->m_dead);
	return (0);
}

void	*thread(void *arg)
{
	t_philo	*philo;
	t_state	*state;

	philo = arg;
	state = philo->state;
	while (ft_state_dead(state) == 0 && (philo->n_of_meal > 0 || philo->n_of_meal < 0))
	{
		if (ft_taken_fork(philo) == 0)
		{
			break;
		}
		if (ft_eating(philo) == 0)
		{
			break;
		}
		if (ft_philo_sleep(philo) == 0)
		{
			break;
		}
		if (ft_think(philo) == 0)
		{
			break;
		}
	}
	return (0);
}
// void	*thread(void *arg)
// {
// 	t_philo	*philo;
// 	t_state	*state;

// 	philo = arg;
// 	state = philo->state;
// 	pthread_mutex_lock(&state->m_dead);
// 	philo->time_start = ft_get_time(state);
// 	philo->death = state->death_occured;
// 	pthread_mutex_unlock(&state->m_dead);
// 	while (philo->death == 0 && (philo->n_of_meal > 0 || philo->n_of_meal < 0))
// 	{
// 		pthread_mutex_lock(&state->m_dead);
// 		philo->death = state->death_occured;
// 		pthread_mutex_unlock(&state->m_dead);
// 		ft_taken_fork(philo);
// 		ft_eating(philo);
// 		ft_sleep_and_think(philo);
// 	}
// 	pthread_mutex_lock(&state->m_dead);
// 	philo->death = 1;
// 	pthread_mutex_unlock(&state->m_dead);
// 	return (0);
// }
