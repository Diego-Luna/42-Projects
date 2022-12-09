/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:32:26 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/08 20:11:27 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
// # include <string.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
// # include <stdio.h>
// # include <errno.h>

typedef struct s_state
{
	int				n_philos;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				ntp_must_eat;
	int				error;
	int				death_occured;
	long long		time_start;
	long long		time_working;
	pthread_mutex_t	*forks;
	pthread_mutex_t	message;
	struct s_philo	*philos;
}					t_state;

typedef struct s_philo
{
	int				id;
	int				death;
	int				l_fork;
	int				r_fork;
	int				n_of_meal;
	long long		time_eat;
	long long		time_dead;
	long long		time_sleep;
	long long		time_start;
	long long		time_working;
}					t_philo;

int	ft_check_parans(char const **argv);


void	ft_init_state(t_state *state, int argc, char const **argv);
void	ft_create_mutex(t_state *state);
long long	ft_get_time(t_state *state);

#endif