/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:50:01 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/11 17:40:46 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

int	main(int argc, char *argv[], char *envp[])
{
	v_state state;

	ft_check_parameters(argc, argv, envp, &state);
	ft_create_here_bonus(argv, &state);
	ft_use_here_bonus(argv[argc - 1], &state);
	state.cmd_nmbs = argc - 3 - state.here_doc;
	state.pipe_nmbs = 2 * (state.cmd_nmbs - 1);
	state.pipe = (int *)malloc(sizeof(int) * state.pipe_nmbs);
	if (!state.pipe)
		ft_error_message("Error Pipe", 2);
	state.env_path = ft_find_path(envp);
	state.cmd_paths = ft_split(state.env_path, ':');
	if (!state.cmd_paths)
		ft_pipe_error(&state);
	ft_create_pipes(&state);
	state.index = -1;
	while ((++state.index) < state.cmd_nmbs)
	{
		ft_childs(state, envp, argv);
	}
	ft_pipe_close(&state);
	waitpid(-1, NULL, 0);
	ft_father_clean(&state);
	return (0);
}
