/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:48:05 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/14 19:57:42 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free(t_state *state)
{
	int i = 0;

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

void	ft_mutex_message(t_philo *philo, char *str, int opcion)
{
	t_state *state;

	state = philo->state;

	pthread_mutex_lock(&state->m_check_dead);
	philo->death = state->death_occured;
	pthread_mutex_unlock(&state->m_check_dead);

	pthread_mutex_lock(&philo->state->message);
	// if (opcion == O_NORMAL && state->death_occured == 0 && state->ntp_must_eat !=0)
	if (opcion == O_NORMAL && philo->death == 0 && state->ntp_must_eat !=0)
	{
		printf("%lld %d %s\n", ft_get_time(philo->state), philo->id, str);
	}
	// if (opcion == O_FINIS && state->death_occured == 0  && state->ntp_must_eat !=0)
	if (opcion == O_FINIS && philo->death == 0  && state->ntp_must_eat !=0)
	{
		printf("%s\n", str);
	}
	// if (opcion == O_FULL && state->death_occured == 0  && state->ntp_must_eat !=0)
	if (opcion == O_FULL && philo->death == 0  && state->ntp_must_eat !=0)
	{
		printf("%lld %s\n", ft_get_time(philo->state), str);
		state->ntp_must_eat = 0;
	}
	// if (state->death_occured == 1)
	if (philo->death == 1)
	{
		printf("%lld %d %s\n", ft_get_time(philo->state), philo->id, M_DIED);
		pthread_mutex_lock(&state->m_check_dead);
		state->death_occured = 2;
		pthread_mutex_unlock(&state->m_check_dead);
		// state->death_occured = 2;
	}
	pthread_mutex_unlock(&philo->state->message);
}

// void	ft_mutex_message(t_philo *philo, char *str, int opcion)
// {
// 	pthread_mutex_lock(&philo->state->message);
// 	if (opcion == O_NORMAL)
// 	{
// 		printf("%lld %d %s\n", ft_get_time(philo->state), philo->id, str);
// 	}
// 	if (opcion == O_FINIS)
// 	{
// 		printf("%s\n", str);
// 	}
// 	if (opcion == O_FULL)
// 	{
// 		printf("%lld %s\n", ft_get_time(philo->state), str);
// 	}
// 	pthread_mutex_unlock(&philo->state->message);
// }
