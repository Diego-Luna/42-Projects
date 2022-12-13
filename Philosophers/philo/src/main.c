/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:33:45 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/13 12:01:00 by dluna-lo         ###   ########.fr       */
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
	ft_mutex_message(philo, M_SLEE, O_NORMAL);
	ft_sleep(philo->state, philo->time_sleep);
	ft_mutex_message(philo, M_THIN, O_NORMAL);
}

// philo->time_start = ft_get_time(philo->state);
void	*thread(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if ((ft_get_time(philo->state) - philo->time_start) < philo->time_dead)
	{
		while ((philo->n_of_meal > 0 || philo->n_of_meal == -1)
			&& philo->death == 0 && ft_check_dead(philo->state) == 0)
		{
			if (philo->death == 0 && (ft_get_time(philo->state)
					- philo->t_last_eat) >= philo->time_dead)
				ft_dead_procees(philo, M_DIED);
			else
			{
				ft_taken_fork(philo);
				ft_eating(philo);
				if (philo->n_of_meal > 0 || philo->n_of_meal == -1)
					ft_sleep_and_think(philo);
			}
		}
	}
	else
		ft_dead_procees(philo, M_FULL);
	return (0);
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
	i = 0;
	while (i < state->n_philos)
	{
		pthread_join(state->philos[i].thid, NULL);
		i++;
	}
	i = 0;
	while (i < state->n_philos)
	{
		pthread_detach(state->philos[i].thid);
		i++;
	}
}

int	main(int argc, char const **argv)
{
	t_state	state;

	if (argc >= 5 && argc <= 6 && ft_check_parameters(argv) == 1)
	{
		ft_init_state(&state, argc, argv);
		ft_create_mutex(&state);
		ft_create_philos(&state);
		ft_print_state(&state);
		ft_create_threads(&state);
		ft_free(&state);
	}
	return (0);
}
