/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:51:16 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/11 15:10:54 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

void ft_on_dup2(int zero, int one)
{
	// dup2(one, STDOUT_FILENO);
	// dup2(zero, STDIN_FILENO);
	dup2(zero, 0);
	dup2(one, 1);
}

void	ft_childs(v_state state, char **envp, char **argv)
{
	state.pid = fork();
	if (!state.pid)
	{
		if (state.index == 0)
			ft_on_dup2(state.infile, state.pipe[1]);
		else if (state.index == state.cmd_nmbs - 1)
			ft_on_dup2(state.pipe[2 * state.index - 2], state.outfile);
		else
			ft_on_dup2(state.pipe[2 * state.index - 2], state.pipe[2 * state.index + 1]);
		ft_pipe_close(&state);
		state.cmd_args = ft_split(argv[2 + state.here_doc + state.index], ' ');
		state.cmd = ft_get_comand_p2(state.cmd_paths, state.cmd_args[0]);
		if(!(state.cmd))
		{
			ft_childs_clean(&state);
			ft_error_message("Error en el comando", 1);
		}
		execve(state.cmd, state.cmd_args, envp);
		exit(0);
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
