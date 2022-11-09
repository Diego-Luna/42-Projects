/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:51:16 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/09 12:53:42 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex.h"

void	ft_childs(char **argv, char **envp, int *state)
{
	int	file;

	file = open(argv[1], O_RDONLY);
	if (file == -1)
		ft_error_message("Error ./pipex : no read file in child", 0);
	dup2(state[1], STDOUT_FILENO);
	dup2(file, STDIN_FILENO);
	close(state[0]);
	ft_run_comand(argv[2], envp);
	close(file);
	exit(1);
}
