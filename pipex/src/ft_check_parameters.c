/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parameters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:49:12 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/10 09:30:25 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex.h"

void	ft_check_parameters(int argc, char *argv[], char *envp[])
{
	int	i;

	i = 2;
	if (argc != 5 || envp[0][0] == '\n')
		ft_error_message("Error ./pipex - 1", 1);
	if (access(argv[1], F_OK) == -1)
		ft_error_message("Error ./pipex - 2.1", 1);
	while (i < argc - 1)
	{
		if (ft_strlen(argv[i]) < 2 || access(argv[i], F_OK) != -1)
			ft_error_message("Error ./pipex - 3", 0);
		i++;
	}
}
