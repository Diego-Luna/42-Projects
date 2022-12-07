/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:32:26 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/07 17:19:08 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "libft/libft.h"
// # include <stdlib.h>
// # include <string.h>
# include <unistd.h>
# include <sys/time.h>
// # include <stdio.h>
// # include <errno.h>

typedef struct s_state
{
	int		n_philo;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		ntp_must_eat;
	int		error;
	int		death_occured;
	long long	time_start;
	long long	time_working;
	struct s_philo	*philos;
	pthread_mutex_t *forks;
}			t_state;

typedef struct s_philo
{
	int		id;
	int		death;
	int		l_fork;
	int		r_fork;
	int		nb_of_meal;
}			t_philo;

#endif