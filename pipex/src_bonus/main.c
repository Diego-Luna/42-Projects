/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:50:01 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/11 08:09:23 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	v_state state;

	ft_check_parameters(argc, argv, envp);
	ft_create_here_bonus(argv, &state);
	ft_use_here_bonus(argv[argc - 1], &state);
	state.cmd_nmbs = argc - 3 - state.here_doc;
	state.pipe_nmbs = 2 * (state.cmd_nmbs - 1);
	state.pipe = (int *)malloc(sizeof(int) * state.pipe_nmbs);
	if (!state.pipe)
		msg_error("Error Pipe");
	state.env_path = find_path(envp);
	state.cmd_paths = ft_split(state.env_path, ':');
	if (!state.cmd_paths)
		pipe_free(&pipex);
	return (0);
}
