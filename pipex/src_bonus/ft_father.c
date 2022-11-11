/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_father.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:04:07 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/11 17:41:51 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

void	ft_father_clean(v_state *state)
{
	int i;

	i = 0;
	close(state->infile);
	close(state->outfile);
	if (state->here_doc == 1)
		unlink(".heredoc_tmp");
	while (state->cmd_paths[i])
	{
		free(state->cmd_paths[i]);
		i++;
	}
	free(state->cmd_paths);
	free(state->pipe);
}

// void	ft_father(char **argv, char **envp, v_state *state, int *file)
// {
// 	char	inbuf[16];

// 	read(state->com_n[0], inbuf, 16);
// 	write(state->com_n[1], ft_itoa((int)ft_atoi(inbuf) + 1), 16);
// 	dup2(state->state[0], STDIN_FILENO);
// 	dup2(*file, STDOUT_FILENO);
// 	close(state->state[1]);
// 	close(state->com_n[0]);
// 	close(state->com_n[1]);
// 	ft_run_comand(argv[ft_atoi(inbuf)], envp);
// }
