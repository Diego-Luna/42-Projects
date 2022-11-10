/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_father.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:04:07 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/10 09:06:07 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex.h"

void	ft_father(char **argv, char **envp, int *state, int		*file)
{
	dup2(state[0], STDIN_FILENO);
	dup2(*file, STDOUT_FILENO);
	close(state[1]);
	ft_run_comand(argv[3], envp);
}
