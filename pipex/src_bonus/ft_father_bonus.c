/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_father_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:04:07 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/12 17:56:52 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

void	ft_father_clean(t_state *state)
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
