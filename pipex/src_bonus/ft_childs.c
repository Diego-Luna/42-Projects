/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:51:16 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/10 18:28:02 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

void	ft_childs(char **argv, char **envp, v_pipe *state, int	*file)
{
	char	inbuf[16];

	read(state->com_n[0], inbuf, 16);
	write(state->com_n[1], ft_itoa((int)ft_atoi(inbuf) + 1), 16);
	dup2(state->state[1], STDOUT_FILENO);
	dup2(*file, STDIN_FILENO);
	close(state->state[0]);
	close(state->com_n[0]);
	close(state->com_n[1]);
	ft_run_comand(argv[ft_atoi(inbuf)], envp);
}
