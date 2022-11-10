/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_childs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:51:16 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/10 11:12:51 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

void	ft_childs(char **argv, char **envp, int *state, int	*file)
{
	// dup2(state[1], STDOUT_FILENO);
	// dup2(*file, STDIN_FILENO);
	(void)file;
	close(state[0]);
	ft_run_comand(argv[2], envp);
}
