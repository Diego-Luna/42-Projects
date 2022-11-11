/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parameters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:49:12 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/11 14:55:49 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

void	ft_check_parameters(int argc, char *argv[], char *envp[], v_state *state)
{
	int	i;

	i = 2;
	if (argc < 5 || envp[0][0] == '\n')
		ft_error_message("Error ./pipex - 1", 1);
	if (access(argv[1], F_OK) == -1)
		ft_error_message("Error ./pipex - 2.1", 1);
	while (i < argc - 1)
	{
		if (ft_strlen(argv[i]) < 2 || (access(argv[i], F_OK) != -1 && access(argv[i], F_OK) != 0))
			ft_error_message(ft_strjoin("Error ./pipex - 3 : ", ft_itoa(access(argv[i], F_OK))), 0);
		i++;
	}
	if (argv[0] && !ft_strncmp("here_doc", argv[0], 9))
		state->here_doc = 1;
	else
		state->here_doc = 0;
}
