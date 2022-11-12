/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parameters_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:49:12 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/12 17:57:10 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

void	ft_check_parameters(int argc, char *argv[], char *envp[], t_state *s)
{
	int	i;

	i = 2;
	if (argc < 5 || envp[0][0] == '\n')
		ft_error_message("Error ./pipex", 1);
	if (!ft_strncmp("here_doc", argv[1], 9))
		s->here_doc = 1;
	else
		s->here_doc = 0;
	if (access(argv[1], F_OK) == -1 && s->here_doc != 1)
		ft_error_message("Error ./pipex", 1);
	while (i < argc - 1)
	{
		if ((ft_strlen(argv[i]) < 2 || (access(argv[i], F_OK) != -1 && \
			access(argv[i], F_OK) != 0)) && s->here_doc != 1)
			ft_error_message("Error ./pipex", 0);
		i++;
	}
}
