/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 12:50:01 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/10 09:34:30 by dluna-lo         ###   ########.fr       */
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

void	ft_close_all(int *state, int	*file1, int	*file2)
{
	close(state[0]);
	close(state[1]);
	close(*file1);
	close(*file2);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		state[2];
	pid_t	id_procees;
	int		file_c;
	int		file_r;

	ft_check_parameters(argc, argv, envp);
	file_r = open(argv[1], O_RDONLY, 0644);
	file_c = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file_c == -1 || file_r == -1)
		ft_error_message("Error ./pipex : no read file in child", 0);
	if (pipe(state) < 0)
		ft_error_message("Error ./pipe: use pipe", 1);
	id_procees = fork();
	if (id_procees == 0)
		ft_childs(argv, envp, state, &file_r);
	else
	{
		wait(NULL);
		id_procees = fork();
		if (id_procees == 0)
			ft_father(argv, envp, state, &file_c);
		ft_close_all(state, &file_c, &file_r);
	}
	return (0);
}
