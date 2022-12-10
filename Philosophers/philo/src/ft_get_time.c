/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 18:20:06 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/09 18:20:49 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	ft_get_time(t_state *state)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	if (state->time_start == 0)
	{
		return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
	}
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000)
		- state->time_start);
}

void	ft_sleep(t_state *state, int wait_time)
{
	long long	start;

	start = ft_get_time(state);
	while ((ft_get_time(state) - start) < wait_time)
		usleep(10);
	return ;
}
