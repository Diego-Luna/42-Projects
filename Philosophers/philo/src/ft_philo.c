/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:21:55 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/24 18:00:47 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// int	ft_check_dead(t_state *state)
// {
// 	int			i;
// 	t_philo		*philo;

// 	i = 0;
// 	while (i < state->n_philos)
// 	{
// 		philo = &state->philos[i];
// 		if (philo->t_last_eat == -1)
// 		{
// 			if (philo->death == 0 && (ft_get_time(state)
// 					- philo->time_start) >= philo->time_dead)
// 			{
// 				ft_mutex_message_dead(state, i + 1);
// 				return (i + 1);
// 			}
// 		}
// 		else if (philo->death == 0 && philo->t_last_eat > 0
// 			&& (ft_get_time(state) - philo->t_last_eat) >= philo->time_dead)
// 		{
// 			ft_mutex_message_dead(state, i + 1);
// 			return (i + 1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int	ft_taken_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->forks[philo->l_fork]);
	if (ft_mutex_message(philo, M_FORK, O_NORMAL) == 0)
	{
		pthread_mutex_unlock(&philo->state->forks[philo->l_fork]);
		return (0);
	}
	pthread_mutex_lock(&philo->state->forks[philo->r_fork]);
	if (ft_mutex_message(philo, M_FORK, O_NORMAL) == 0)
	{
		pthread_mutex_unlock(&philo->state->forks[philo->r_fork]);
		pthread_mutex_unlock(&philo->state->forks[philo->l_fork]);
		return (0);
	}
	return (1);
}

int	ft_check_finish_eat(t_state *state)
{
	int	i;
	// int	number;

	i = 0;
	// number = 0;
	while (i < state->n_philos)
	{
		pthread_mutex_lock(&state->philos[i].m_eat);
		// number = state->philos[i].n_of_meal;
		// if (number < 0 || number > 0)
		if (state->philos[i].n_of_meal < 0 || state->philos[i].n_of_meal > 0)
		{
			pthread_mutex_unlock(&state->philos[i].m_eat);
			return (0);
		}
		pthread_mutex_unlock(&state->philos[i].m_eat);
		i++;
	}
	return (1);
}

int	ft_eating(t_philo *philo)
{
	t_state	*state;

	state = philo->state;
	pthread_mutex_lock(&philo->m_time);
	philo->t_last_eat = ft_get_time(state);
	pthread_mutex_unlock(&philo->m_time);
	// pthread_mutex_lock(&state->m_time);
	// philo->t_last_eat = ft_get_time(state);
	// pthread_mutex_unlock(&state->m_time);
	if (ft_mutex_message(philo, M_EAT, O_NORMAL) == 0)
	{
		pthread_mutex_unlock(&state->forks[philo->r_fork]);
		pthread_mutex_unlock(&state->forks[philo->l_fork]);
		return (0);
	}
	ft_sleep(philo->state, philo->time_eat);
	pthread_mutex_lock(&philo->m_eat);
	philo->n_of_meal--; // o ++
	if (philo->n_of_meal == 0){
		pthread_mutex_unlock(&philo->m_eat);
		pthread_mutex_unlock(&philo->state->forks[philo->r_fork]);
		pthread_mutex_unlock(&philo->state->forks[philo->l_fork]);
		return (0);
	}
	pthread_mutex_unlock(&philo->m_eat);
	pthread_mutex_unlock(&philo->state->forks[philo->r_fork]);
	pthread_mutex_unlock(&philo->state->forks[philo->l_fork]);
	return (1);
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
		state->philos[i].stop = 0;
		state->philos[i].l_fork = i;
		state->philos[i].r_fork = (i + 1) % state->n_philos;
		state->philos[i].n_of_meal = state->ntp_must_eat;
		state->philos[i].time_eat = state->t_eat;
		state->philos[i].time_dead = state->t_die;
		state->philos[i].time_sleep = state->t_sleep;
		state->philos[i].time_working = -1;
		state->philos[i].state = state;
		state->philos[i].t_last_eat = -1;
		i++;
	}
}
