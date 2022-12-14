/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:04:09 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/12 17:55:36 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

void	ft_pipe_close(t_state *state)
{
	int	i;

	i = 0;
	while (i < state->pipe_nmbs)
	{
		close(state->pipe[i]);
		i++;
	}
}
