/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:51:01 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/12 17:56:47 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

void	ft_error_message(char *str, int error)
{
	if (!str)
		perror("Error: ./pipex");
	else
		perror(str);
	exit(error);
}

void	ft_pipe_error(t_state *state)
{
	close(state->infile);
	close(state->outfile);
	if (state->here_doc == 1)
		unlink(".heredoc_tmp");
	free(state->pipe);
	ft_error_message("Error Environment", 1);
}

void	ft_cmd_error(t_state *state)
{
	int	i;

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

void	ft_childs_clean(t_state *state)
{
	int	i;

	i = 0;
	while (state->cmd_args[i])
	{
		free(state->cmd_args[i]);
		i++;
	}
	free(state->cmd_args);
	free(state->cmd);
}
