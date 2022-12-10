/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:32:26 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/09 18:25:00 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>
// # include <stdio.h>
// # include <errno.h>

# define M_FORK "has taken a fork"
# define M_EAT "is eating"
# define M_FULL "This philosopher is full"
# define M_SLEE "is sleeping"
# define M_THIN "is thinking"
# define M_ALL "The philosophers have finished eating"
# define M_DIED "died"

# define O_NORMAL 1
# define O_FINIS 2
# define O_FULL 3

typedef struct s_philo
{
	pthread_t		thid;
	int				id;
	int				death;
	int				l_fork;
	int				r_fork;
	int				n_of_meal;
	long long		time_eat;
	long long		time_dead;
	long long		time_sleep;
	long long		t_last_eat;
	long long		time_start;
	long long		time_working;
	struct s_state	*state;
}					t_philo;

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
	t_philo			*philos;
}					t_state;

int					ft_check_parans(char const **argv);

void				ft_init_state(t_state *state, int argc, char const **argv);
void				ft_create_mutex(t_state *state);
long long			ft_get_time(t_state *state);

void				ft_free(t_state *state);
void				ft_mutex_message(t_philo *philo, char *str, int opcion);

long long			ft_get_time(t_state *state);
void				ft_sleep(t_state *state, int wait_time);

void				ft_create_philos(t_state *state);
void				ft_taken_fork(t_philo *philo);
void				ft_eating(t_philo *philo);

#endif