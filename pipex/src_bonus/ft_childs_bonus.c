/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:51:16 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/12 17:36:17 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

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
