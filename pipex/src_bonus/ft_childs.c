/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:51:16 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/11 18:18:30 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

// dup2(zero, 0);
// dup2(one, 1);
static void	ft_on_dup2(int zero, int one)
{
	dup2(one, STDOUT_FILENO);
	dup2(zero, STDIN_FILENO);
}

void	ft_childs(t_state state, char **envp, char **argv)
{
	state.pid = fork();
	if (!state.pid)
	{
		if (state.index == 0)
			ft_on_dup2(state.infile, state.pipe[1]);
		else if (state.index == state.cmd_nmbs - 1)
			ft_on_dup2(state.pipe[2 * state.index - 2], state.outfile);
		else
			ft_on_dup2(state.pipe[2 * state.index - 2], \
				state.pipe[2 * state.index + 1]);
		ft_pipe_close(&state);
		state.cmd_args = ft_split(argv[2 + state.here_doc + state.index], ' ');
		state.cmd = ft_get_comand_p(state.cmd_paths, state.cmd_args[0]);
		if (!state.cmd)
		{
			ft_error_message(state.cmd_args[0], 1);
			ft_childs_clean(&state);
			exit(1);
		}
		execve(state.cmd, state.cmd_args, envp);
	}
}
// {
// 	char	inbuf[16];

// 	read(state->com_n[0], inbuf, 16);
// 	write(state->com_n[1], ft_itoa((int)ft_atoi(inbuf) + 1), 16);
// 	dup2(state->state[1], STDOUT_FILENO);
// 	dup2(*file, STDIN_FILENO);
// 	close(state->state[0]);
// 	close(state->com_n[0]);
// 	close(state->com_n[1]);
// 	ft_run_comand(argv[ft_atoi(inbuf)], envp);
// }
