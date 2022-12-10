/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:48:05 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/09 18:34:57 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_free(t_state *state)
{
	// int i = 0;

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
	pthread_mutex_lock(&philo->state->message);

	if (opcion == O_NORMAL)
	{
		printf("%lld %d %s\n", ft_get_time(philo->state), philo->id, str);
	}
	if(opcion == O_FINIS)
	{
		printf("%s\n", str);
	}
	if(opcion == O_FULL)
	{
		printf("%lld %d %s\n", ft_get_time(philo->state), philo->id, str);
	}
	pthread_mutex_unlock(&philo->state->message);
}
