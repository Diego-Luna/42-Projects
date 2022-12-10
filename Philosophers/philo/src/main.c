/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:33:45 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/09 18:35:12 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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

void *thread(void *arg) {

	t_philo *philo = arg;

	philo->time_start = ft_get_time(philo->state);
	while ((philo->n_of_meal > 0 || philo->n_of_meal == -1 ) && philo->death == 0)
	{
		if (philo->death == 0 && (ft_get_time(philo->state) - philo->t_last_eat) >= philo->time_dead)
		{
			philo->death = 1;
			ft_mutex_message(philo, M_DIED, O_NORMAL);
		}
		else
		{
			ft_taken_fork(philo);
			ft_eating(philo);
			if (philo->n_of_meal > 0 || philo->n_of_meal == -1)
			{
				ft_mutex_message(philo, M_SLEE, O_NORMAL);
				ft_sleep(philo->state, philo->time_sleep);
				ft_mutex_message(philo, M_THIN, O_NORMAL);
			}
		}
	}
	return (0);
}

void	ft_create_threads(t_state *state)
{
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
		ft_create_threads(&state);
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