/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:04:23 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/13 18:13:33 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	size_t	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] <= 13 && str[i] >= 9))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

void	ft_init_state(t_state *state, int argc, char const **argv)
{
	state->n_philos = ft_atoi(argv[1]);
	state->t_die = ft_atoi(argv[2]);
	state->t_eat = ft_atoi(argv[3]);
	state->t_sleep = ft_atoi(argv[4]);
	state->death_occured = 0;
	state->error = 0;
	state->time_start = 0;
	state->time_start = ft_get_time(state);
	if (argc == 6)
	{
		state->ntp_must_eat = ft_atoi(argv[5]);
	}
	else
	{
		state->ntp_must_eat = -1;
	}
	state->philos = NULL;
	state->forks = NULL;
}
