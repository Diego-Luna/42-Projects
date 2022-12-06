/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 17:32:26 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/12/06 17:43:14 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "libft/libft.h"
// # include <stdlib.h>
// # include <string.h>
# include <unistd.h>
// # include <stdio.h>
// # include <errno.h>

typedef struct s_state
{
	int n_philo;
	int t_die;
	int t_eat;
	int t_sleep;
	int ntp_must_eat;
} t_state;


#endif