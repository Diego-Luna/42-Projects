/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:16:56 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/28 13:22:34 by dluna-lo         ###   ########.fr       */
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
	t_state		*state;
	int			i;
	long long	tmp;

	i = 0;
	state = arg;
	while (ft_state_dead(state) == 0)
	{
		pthread_mutex_lock(&state->philos[i].m_time);
		tmp = state->philos[i].t_last_eat;
		if ((ft_get_time(state) - tmp) > state->t_die)
		{
			pthread_mutex_lock(&state->m_dead);
			state->death_occured = 1;
			ft_mutex_message_dead(state, i + 1);
			pthread_mutex_unlock(&state->m_dead);
			pthread_mutex_unlock(&state->philos[i].m_time);
			return (0);
		}
		pthread_mutex_unlock(&state->philos[i].m_time);
		i = (i + 1) % state->n_philos;
	}
	return (0);
}
// void	*thread_check(void *arg)
// {
// 	t_state		*state;
// 	int			i;
// 	long long	tmp;

// 	i = 0;
// 	state = arg;
// 	while (ft_state_dead(state) == 0)
// 	{
// 		pthread_mutex_lock(&state->philos[i].m_time);
// 		tmp = state->philos[i].t_last_eat;
// 		pthread_mutex_unlock(&state->philos[i].m_time);
// 		if ((ft_get_time(state) - tmp) > state->t_die)
// 		{
// 			pthread_mutex_lock(&state->m_dead);
// 			state->death_occured = 1;
// 			ft_mutex_message_dead(state, i + 1);
// 			pthread_mutex_unlock(&state->m_dead);
// 			return (0);
// 		}
// 	}
// 	return (0);
// }

void	*thread_eat(void *arg)
{
	t_state	*state;
	int		i;

	i = 0;
	state = arg;
	while (ft_state_dead(state) == 0)
	{
		if (ft_check_finish_eat(state) == 1)
		{
			pthread_mutex_lock(&state->m_dead);
			state->death_occured = 1;
			ft_mutex_message_eat_all(state);
			pthread_mutex_unlock(&state->m_dead);
			return (0);
		}
	}
	return (0);
}
// void	*thread_eat(void *arg)
// {
// 	t_state	*state;
// 	int		i;

// 	i = 0;
// 	state = arg;
// 	while (ft_state_dead(state) == 0)
// 	{
// 		if (ft_check_finish_eat(state) == 1)
// 		{
// 			pthread_mutex_lock(&state->m_dead);
// 			state->death_occured = 1;
// 			pthread_mutex_unlock(&state->m_dead);
// 			ft_mutex_message_eat_all(state);
// 			return (0);
// 		}
// 		i = (i + 1) % state->n_philos;
// 	}
// 	return (0);
// }

void	*thread(void *arg)
{
	t_philo	*philo;
	t_state	*state;

	philo = arg;
	state = philo->state;
	if (philo->id % 2 == 0)
	{
		// ft_sleep(state, philo->time_eat / 10 );
		// ft_sleep(state, philo->time_eat / 100 );
		ft_sleep(state, philo->time_eat / state->n_philos );
	}
	while (ft_state_dead(state) == 0)
	{
		if (ft_taken_fork(philo) == 0)
		{
			break ;
		}
		if (ft_eating(philo) == 0)
		{
			break ;
		}
		if (ft_philo_sleep(philo) == 0)
		{
			break ;
		}
		if (ft_think(philo) == 0)
		{
			break ;
		}
	}
	return (0);
}
