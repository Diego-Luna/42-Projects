/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:33:45 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/09 13:28:42 by dluna-lo         ###   ########.fr       */
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


void	ft_create_philos(t_state *state)
{
	int	i;

	i = 0;
	state->philos = malloc(sizeof(t_philo) * state->n_philos);
	while (i < state->n_philos)
	{
		state->philos[i].id = i + 1;
		state->philos[i].death = 0;
		state->philos[i].l_fork = i;
		state->philos[i].r_fork = (i + 1) % state->n_philos;
		state->philos[i].n_of_meal = state->ntp_must_eat;
		state->philos[i].time_eat = state->t_eat;
		state->philos[i].time_dead = state->t_die;
		state->philos[i].time_sleep = state->t_sleep;
		state->philos[i].time_start = -1;
		state->philos[i].time_working = -1;
		state->philos[i].state = state;
		i++;
	}
}

void	ft_print_state(t_state *state)
{
	int	i;

	i = 0;
	printf("\n state\n");
	printf(" n_philos{%d} t_die{%d} t_eat{%d} t_sleep{%d}", state->n_philos, state->t_die, state->t_eat, state->t_sleep);

	printf("\n Philos\n");
	while (i < state->n_philos)
	{
		printf(" id{%d}", state->philos[i].id);
		printf(" death{%d}", state->philos[i].death);
		printf(" l_fork{%d}", state->philos[i].l_fork);
		printf(" r_fork{%d}", state->philos[i].r_fork);
		printf(" n_of_meal{%d}", state->philos[i].n_of_meal);
		printf(" t_eat{%lld}", state->philos[i].time_eat);
		printf(" t_dead{%lld}", state->philos[i].time_dead);
		printf(" t_sleep{%lld}", state->philos[i].time_sleep);
		printf(" t_start{%lld}", state->philos[i].time_start);
		printf(" t_working{%lld}", state->philos[i].time_working);
		printf("\n");
		i++;
	}
}

void	ft_mutex_message(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->state->message);
	printf("%lld %d %s\n", ft_get_time(philo->state), philo->id, str);
	pthread_mutex_unlock(&philo->state->message);

}

void	ft_taken_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->state->forks[philo->l_fork]);
	pthread_mutex_lock(&philo->state->forks[philo->r_fork]);

	ft_mutex_message(philo, M_FORK);
}

void *thread(void *arg) {

	t_philo *philo = arg;

	ft_taken_fork(philo);

	pthread_mutex_unlock(&philo->state->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->state->forks[philo->r_fork]);
	return (0);
}

void	ft_create_threads(t_state *state)
{
	// pthread_t thid;
	int i = 0 ;

	while (i < state->n_philos)
	{
		pthread_create(&state->philos[i].thid, NULL, thread, (void *)&state->philos[i]);
		i++;
	}
	i = 0;
	while (i < state->n_philos)
	{
		pthread_join(state->philos[i].thid, NULL);
		i++;
	}
  // pthread_create(&thid, NULL, thread, "como estas");
	// pthread_join(thid, NULL);
}

int	main(int argc, char const **argv)
{
	t_state	state;

	if (argc >= 5 && argc <= 6 && ft_check_parans(argv) == 1)
	{
		// start state
		ft_init_state(&state, argc, argv);
		// create mutex
		ft_create_mutex(&state);
		// create philos
		ft_create_philos(&state);
		
		ft_print_state(&state);
		
		// create threads
		// ft_create_threads(&state);
		// 	check eating, think, etc.
		// 	todo print state philo
		// state.time_working = ft_get_time(&state);
		ft_free(&state);
	}
	return (0);
}

// #define _OPEN_THREADS
// #include <pthread.h>
// #include <stdlib.h>
// #include <stdio.h>
// #include <string.h>

// void *thread(void *arg) {
//   char *ret;
//   printf("thread() entered with argument '%s'\n", arg);
//   if ((ret = (char*) malloc(20)) == NULL) {
//     perror("malloc() error");
//     exit(2);
//   }
//   strcpy(ret, "This is a test");
//   pthread_exit(ret);
// }

// int main(void) {
//   pthread_t thid;
//   void *ret;

//   if (pthread_create(&thid, NULL, thread, "como estas") != 0) {
//     perror("pthread_create() error");
//     exit(1);
//   }

//   if (pthread_join(thid, &ret) != 0) {
//     perror("pthread_create() error");
//     exit(3);
//   }

//   printf("thread exited with '%s'\n", ret);
// }