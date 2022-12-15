/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:48:05 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/15 18:33:22 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->n_philos)
	{
		pthread_detach(state->philos[i].thid);
		pthread_mutex_destroy(&state->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&state->message);
	pthread_mutex_destroy(&state->m_check_dead);
	pthread_detach(state->check_dead);
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

void ft_mutex_message_dead(t_state	*state, int i)
{
	pthread_mutex_lock(&state->message);
	pthread_mutex_lock(&state->m_check_dead);
	printf("%lld %d %s\n", ft_get_time(state), i + 1, M_DIED);
	state->death_occured = 2;
	pthread_mutex_unlock(&state->m_check_dead);
	pthread_mutex_unlock(&state->message);
}

void ft_mutex_message_eat_all(t_state	*state)
{
	pthread_mutex_lock(&state->message);
	pthread_mutex_lock(&state->m_check_dead);
	printf("%lld %s\n", ft_get_time(state), M_ALL);
	state->ntp_must_eat = 0;
	pthread_mutex_unlock(&state->m_check_dead);
	pthread_mutex_unlock(&state->message);
}

void	ft_mutex_message(t_philo *philo, char *str, int opcion)
{
	t_state	*state;
	int		dead;
	int		ntp_must_eat;

	state = philo->state;

	pthread_mutex_lock(&state->m_check_dead);
	dead = state->death_occured;
	ntp_must_eat = state->ntp_must_eat;
	// pthread_mutex_unlock(&state->m_check_dead);

	pthread_mutex_lock(&philo->state->message);
	if (opcion == O_NORMAL && dead == 0 && ntp_must_eat != 0)
	{
		printf("%lld %d %s\n", ft_get_time(philo->state), philo->id, str);
	}
	else if (opcion == O_FINIS && dead == 0 && ntp_must_eat != 0)
	{
		printf("%s\n", str);
	}

	pthread_mutex_unlock(&philo->state->message);
	pthread_mutex_unlock(&state->m_check_dead);
}
