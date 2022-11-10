/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_father.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:04:07 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/10 11:12:54 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

void	ft_father(char **argv, char **envp, int *state, int		*file)
{
	// dup2(state[0], STDIN_FILENO);
	// dup2(*file, STDOUT_FILENO);
	(void)file;
	close(state[1]);
	ft_run_comand(argv[3], envp);
}
