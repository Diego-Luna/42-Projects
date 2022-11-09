/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:50:01 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/09 11:35:35 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex.h"

void	ft_run_comand(char *comds, char **envp)
{
	char	*path;
	char	*cmd;
	char	**args;
	int		i;

	args = ft_split(comds, ' ');
	cmd = ft_strjoin("/", args[0]);
	path = ft_get_comand_p(envp, cmd);
	// printf("\n Path: {%s}", path);
	// printf("\n cmd: {%s}", cmd);
	// printf("\n args: {%s}", args[0]);
	// printf("\n envp: {%s}", envp[0]);
	// printf("\n");
	if (!path | !cmd | !args)
	{
		i = -1;
		while (args[++i])
			free(args[i]);
		free(args);
		free(path);
		ft_error_message("f_r_c Error: command:path");
	}
	i = execve(path, args, envp);
	if (i == -1)
		ft_error_message("error en execve");
}

int	main(int argc, char *argv[], char *envp[])
{
	int		state[2];
	pid_t	id_procees;

	ft_check_parameters(argc, argv, envp);
	if (pipe(state) < 0)
		ft_error_message("main pipe");
	id_procees = fork();
	if (id_procees == 0)
		ft_childs(argv, envp, state);
	else
	{
		wait(NULL);
		ft_father(argv, envp, state);
	}
	return (0);
}
