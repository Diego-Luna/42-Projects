/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:33:45 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/26 13:55:42 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_pthreads_join(t_state *state)
{
	int	i;
	int	dead;

	dead = 0;
	i = 0;
	while (i < state->n_philos)
	{
		pthread_join(state->philos[i].thid, NULL);
		i++;
	}
	pthread_join(state->check_dead, NULL);
	if (state->ntp_must_eat >= 0)
	{
		pthread_join(state->check_eats, NULL);
	}
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
		usleep(100);
	}
	pthread_create(&state->check_dead, NULL, thread_check, (void *)state);
	if (state->ntp_must_eat > 0)
	{
		pthread_create(&state->check_eats, NULL, thread_eat, (void *)state);
	}
	ft_pthreads_join(state);
}

void	*thread_one_philos(void *arg)
{
	t_philo	*philo;
	t_state	*state;

	philo = arg;
	state = philo->state;
	pthread_mutex_lock(&state->forks[philo->l_fork]);
	ft_mutex_message(philo, M_FORK, O_NORMAL);
	ft_sleep(state, philo->time_dead);
	ft_mutex_message_dead(state, 1);
	pthread_mutex_unlock(&state->forks[philo->l_fork]);
	return (0);
}

int	main(int argc, char const **argv)
{
	t_state	state;

	if (argc >= 5 && argc <= 6 && ft_check_parameters(argv) == 1)
	{
		ft_init_state(&state, argc, argv);
		ft_create_philos(&state);
		ft_create_mutex(&state);
		if (state.n_philos > 1)
		{
			ft_create_threads(&state);
		}
		else
		{
			pthread_create(&state.philos[0].thid, NULL, thread_one_philos,
				(void *)&state.philos[0]);
			pthread_join(state.philos[0].thid, NULL);
		}
		ft_free(&state);
	}
	return (0);
}
