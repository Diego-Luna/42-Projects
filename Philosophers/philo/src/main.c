/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:33:45 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/16 12:30:25 by dluna-lo         ###   ########.fr       */
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
	pthread_mutex_lock(&state->m_check_dead);
	dead = state->death_occured;
	pthread_mutex_unlock(&state->m_check_dead);
	if (ft_check_finish_eat(state) == 1 && dead == 0
		&& state->ntp_must_eat != -1)
	{
		ft_mutex_message_eat_all(state);
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
		ft_create_threads(&state);
		ft_free(&state);
	}
	return (0);
}
