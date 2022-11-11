/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_father.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:04:07 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/10 18:24:13 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

void	ft_father(char **argv, char **envp, v_pipe *state, int *file)
{
	char	inbuf[16];

	read(state->com_n[0], inbuf, 16);
	write(state->com_n[1], ft_itoa((int)ft_atoi(inbuf) + 1), 16);
	dup2(state->state[0], STDIN_FILENO);
	dup2(*file, STDOUT_FILENO);
	close(state->state[1]);
	close(state->com_n[0]);
	close(state->com_n[1]);
	ft_run_comand(argv[ft_atoi(inbuf)], envp);
}
