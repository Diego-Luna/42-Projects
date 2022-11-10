/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:50:01 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/10 11:20:21 by dluna-lo         ###   ########.fr       */
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

void	ft_close_all(int *state, int *file1, int *file2)
{
	close(state[0]);
	close(state[1]);
	close(*file1);
	close(*file2);
}

void	ft_process_control(char **argv, char **envp, int *state, int *files)
{
	pid_t	pid[3];
	pid_t	cpid;

	int i, stat;
	i = 0;
	while (i < 3)
	{
		pid[i] = fork();
		if (pid[i] == 0)
			exit(100 + i);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		cpid = waitpid(pid[i], &stat, 0);
		if (i == 0)
		{
			write(1, "\n Diego value 1\n", ft_strlen("\n Diego value 1\n"));
			ft_childs(argv, envp, state, &files[0]);
		}
		if (i == 1)
		{
			write(1, "\n Diego value 2\n", ft_strlen("\n Diego value 1\n"));
			ft_father(argv, envp, state, &files[1]);
		}
		// if (WIFEXITED(stat))
		// {
		// 	printf("Child %d pid status: %d\n",
		// 			cpid,
		// 			pid[i]);
		// }
		i++;
	}
	(void) argv;
	(void) envp;
	(void) state;
	(void) files;
	// pid_t	id_procees;
	// id_procees = fork();
	// if (id_procees == 0)
	// 	ft_childs(argv, envp, state, &files[0]);
	// else
	// {
	// 	wait(NULL);
	// 	id_procees = fork();
	// 	if (id_procees == 0)
	// 		ft_father(argv, envp, state, &files[1]);
	// 	else
	// 	{
	// 		wait(0);
	// 		ft_error_message("Diego", 0);
	// 	}
	// }
}

int	main(int argc, char *argv[], char *envp[])
{
	int		state[2];
	pid_t	id_procees;
	int		files[2];

	// int		file_c; files[1]
	// int		file_r; files[0]
	ft_check_parameters(argc, argv, envp);
	files[0] = open(argv[1], O_RDONLY, 0644);
	files[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (files[1] == -1 || files[0] == -1)
		ft_error_message("Error ./pipex : no read file in child", 0);
	if (pipe(state) < 0)
		ft_error_message("Error ./pipe: use pipe", 1);
	id_procees = fork();
	if (id_procees == 0)
		ft_process_control(argv, envp, state, files);
	else
	{
		wait(NULL);
		// id_procees = fork();
		// if (id_procees == 0)
		// ft_father(argv, envp, state, &files[1]);
		ft_close_all(state, &files[1], &files[0]);
	}
	return (0);
}
