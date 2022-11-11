/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:51:01 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/11 17:35:46 by diegofranci      ###   ########.fr       */
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

void ft_pipe_error(v_state *state)
{
	close(state->infile);
	close(state->outfile);
	if (state->here_doc == 1)
		unlink(".heredoc_tmp");
	free(state->pipe);
	ft_error_message("Error Environment", 1);
	// ft_putstr_fd("Error Environment", 2);;
	// exit(1);
}
void ft_cmd_error(v_state *state)
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
	// ft_error_message("Error", 1);
	// ft_putstr_fd("Error", 2);;
	// exit(1);
}

void ft_childs_clean(v_state *state)
{
	int i;

	i = 0;
	while (state->cmd_args[i])
	{
		free(state->cmd_args[i]);
		i++;
	}
	free(state->cmd_args);
	free(state->cmd);
}
