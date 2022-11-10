/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:50:01 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/10 18:33:03 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

void	ft_run_comand(char *comds, char **envp)
{
	char	*path;
	char	*cmd;
	char	**args;
	int		i;

	args = ft_split(comds, ' ');
	cmd = ft_strjoin("/", args[0]);
	path = ft_get_comand_p(envp, cmd);
	if (!path | !cmd | !args)
	{
		i = -1;
		while (args[++i])
			free(args[i]);
		free(args);
		free(path);
		ft_error_message("f_r_c Error: command:path", 0);
	}
	i = execve(path, args, envp);
	if (i == -1)
		ft_error_message("error en execve", 1);
}

void	ft_close_all(v_pipe *state, int *file1, int *file2)
{
	close(state->state[0]);
	close(state->state[1]);
	close(*file1);
	close(*file2);
}

void	ft_process_control(char **argv, char **envp, v_pipe *state, int *files)
{
	pid_t	pid[100];
	int i;
	int limit;

	i = 0;
	limit = files[2] - 3 - 1;
	write(state->com_n[1], ft_itoa(2), 16);
	while (i < limit)
	{
		pid[i] = fork();
		if (pid[i] == 0 )
			ft_childs(argv, envp, state, &files[0]);
		else
		{
			wait(NULL);
			pid[i] = fork();
			if (pid[i] == 0)
			{
				ft_father(argv, envp, state, &files[1]);
			}
			else
			{
				ft_close_all(state, &files[1], &files[0]);
			}
		}
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	// int		state[2];
	v_pipe state;
	pid_t	id_procees;
	int		files[3];

	ft_check_parameters(argc, argv, envp);
	files[0] = open(argv[1], O_RDONLY, 0644);
	files[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	files[2] = argc;
	if (files[1] == -1 || files[0] == -1)
		ft_error_message("Error ./pipex : no read file in child", 0);
	if (pipe(state.state) < 0 || pipe(state.com_n) < 0)
		ft_error_message("Error ./pipe: use pipe", 1);
	id_procees = fork();
	if (id_procees == 0)
		ft_process_control(argv, envp, &state, files);
	else
	{
		wait(NULL);
		ft_close_all(&state, &files[1], &files[0]);
	}
	return (0);
}
