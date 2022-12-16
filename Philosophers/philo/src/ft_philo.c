/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:21:55 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/16 10:56:29 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_check_dead(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->n_philos)
	{
		if (state->philos[i].t_last_eat == -1)
		{
			if ( state->philos[i].death == 0 && (ft_get_time(state) - state->philos[i].time_start) > state->philos[i].time_dead)
			{
				return (i + 1);
			}
		}
		else if (state->philos[i].death == 0 && state->philos[i].t_last_eat > 0 && (ft_get_time(state) - state->philos[i].t_last_eat) > state->philos[i].time_dead)
		{
			return (i + 1);
		}
		i++;
	}
	return (0);
}

void	ft_taken_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->forks[philo->l_fork]);
	if (philo->l_fork != philo->r_fork)
	{
		pthread_mutex_lock(&philo->state->forks[philo->r_fork]);
	}
	ft_mutex_message(philo, M_FORK, O_NORMAL);
}

int	ft_check_finish_eat(t_state *state)
{
	int	i;
	int	number;

	i = 0;
	number = 0;

	while (i < state->n_philos)
	{
		pthread_mutex_lock(&state->m_check_dead);
		number = state->philos[i].n_of_meal;
		pthread_mutex_unlock(&state->m_check_dead);
		if ( number < 0 || number > 0)
		{
			return 0;
		}
		i++;
	}
	return (1);
}

void	ft_eating(t_philo *philo)
{
	t_state *state;

	state = philo->state;
	ft_mutex_message(philo, M_EAT, O_NORMAL);
	pthread_mutex_lock(&state->m_check_dead);
	philo->t_last_eat = ft_get_time(philo->state);
	pthread_mutex_unlock(&state->m_check_dead);
	ft_sleep(philo->state, philo->time_eat);
	if (philo->n_of_meal > 0)
	{
		philo->n_of_meal--;
	}
	pthread_mutex_unlock(&philo->state->forks[philo->l_fork]);
	if (philo->l_fork != philo->r_fork)
	{
		pthread_mutex_unlock(&philo->state->forks[philo->r_fork]);
	}
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
		state->philos[i].time_start = -1;
		state->philos[i].time_working = -1;
		state->philos[i].state = state;
		state->philos[i].t_last_eat = -1;
		i++;
	}
}
