/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:21:55 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/09 18:35:31 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		state->philos[i].state = state;
		state->philos[i].t_last_eat = 0;
		i++;
	}
}

void	ft_taken_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->forks[philo->l_fork]);
	pthread_mutex_lock(&philo->state->forks[philo->r_fork]);

	ft_mutex_message(philo, M_FORK, O_NORMAL);
}

void	ft_eating(t_philo *philo)
{
	int i = 0;
	int finish = 1;

	ft_mutex_message(philo, M_EAT, O_NORMAL);
	philo->t_last_eat = ft_get_time(philo->state);
	ft_sleep(philo->state, philo->time_eat);

	if (philo->n_of_meal > 0)
	{
		philo->n_of_meal--;
	}
	if (philo->n_of_meal == 0)
	{
		philo->death = 1;
		ft_mutex_message(philo, M_FULL, O_NORMAL);
		while (i < philo->state->n_philos)
		{
			if (philo->state->philos[i].death == 0)
			{
				finish = 0;
			}
			i++;
		}
		if (finish == 1)
		{
			ft_mutex_message(philo, M_ALL, O_FULL);
		}
	}
	pthread_mutex_unlock(&philo->state->forks[philo->r_fork]);
	pthread_mutex_unlock(&philo->state->forks[philo->l_fork]);
}