/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:33:45 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/14 19:59:32 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_dead_procees(t_philo *philo, char *str)
{
	philo->death = 1;
	ft_mutex_message(philo, str, O_NORMAL);
}

void	ft_sleep_and_think(t_philo *philo)
{
	t_state *state;

	state = philo->state;
	pthread_mutex_lock(&state->m_check_dead);
	philo->death = state->death_occured;
	pthread_mutex_unlock(&state->m_check_dead);
	if (philo->death == 0 && state->ntp_must_eat != 0)
	{
		ft_mutex_message(philo, M_SLEE, O_NORMAL);
		ft_sleep(philo->state, philo->time_sleep);
		ft_mutex_message(philo, M_THIN, O_NORMAL);
	}
}

int	ft_get_index_philo_dead(t_state *state)
{
	int i = 0;

	i = 0;
	while (i < state->n_philos)
	{
		if (state->philos[i].death == 1)
		{
			return (i);
		}
		i++;
	}
	return (0);
}

void	*thread_check(void *arg)
{
	t_state	*state;

	state = arg;
	while (state->death_occured == 0 && state->ntp_must_eat != 0)
	{
		pthread_mutex_lock(&state->m_check_dead);
		state->death_occured = ft_check_dead(state);
		// state->death_occured = 1;
		pthread_mutex_unlock(&state->m_check_dead);
		// state->death_occured = 0;
		if (state->death_occured == 1)
		{
			ft_mutex_message(&state->philos[ft_get_index_philo_dead(state)], M_DIED, O_NORMAL);
		}
		if (ft_check_finish_eat(state) == 1 && state->ntp_must_eat != 0)
		{
			ft_mutex_message(&state->philos[0], M_ALL, O_FULL);
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
	philo->time_start = ft_get_time(state);
	pthread_mutex_lock(&state->m_check_dead);
	philo->death = state->death_occured;
	pthread_mutex_unlock(&state->m_check_dead);
	// while (state->death_occured == 0 && state->ntp_must_eat != 0
	while (philo->death == 0 && state->ntp_must_eat != 0
		&& (philo->n_of_meal > 0 || philo->n_of_meal == -1))
	{
		ft_taken_fork(philo);
		ft_eating(philo);
		if (philo->n_of_meal > 0 || philo->n_of_meal == -1)
			ft_sleep_and_think(philo);
		pthread_mutex_lock(&state->m_check_dead);
		philo->death = state->death_occured;
		pthread_mutex_unlock(&state->m_check_dead);
	}
	return (0);
}

void	ft_pthreads_join(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->n_philos)
	{
		pthread_join(state->philos[i].thid, NULL);
		i++;
	}
	pthread_join(state->check_dead, NULL);
}

void	ft_create_threads(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->n_philos)
	{
		pthread_create(&state->philos[i].thid, NULL, thread,
				(void *)&state->philos[i]);
		i++;
	}
	pthread_create(&state->check_dead, NULL, thread_check, (void *)state);
	ft_pthreads_join(state);
}

int	main(int argc, char const **argv)
{
	t_state	state;

	if (argc >= 5 && argc <= 6 && ft_check_parameters(argv) == 1)
	{
		ft_init_state(&state, argc, argv);
		ft_create_mutex(&state);
		ft_create_philos(&state);
		// ft_print_state(&state);
		ft_create_threads(&state);
		ft_free(&state);
	}
	return (0);
}
