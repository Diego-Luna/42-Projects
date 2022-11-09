/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_father.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:04:07 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/09 11:55:41 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex.h"

void	ft_father(char **argv, char **envp, int *state)
{
	int		file;

	file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 644);
	if (file == -1)
		ft_error_message("Error father open : parent:outfile", 0);
	dup2(state[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(state[1]);
	ft_run_comand(argv[3], envp);
	close(file);
}
