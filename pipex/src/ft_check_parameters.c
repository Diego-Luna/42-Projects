/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parameters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:49:12 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/07 17:36:20 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	ft_check_parameters(int argc, char const *argv[])
{
	int	i;

	i = 2;
	if (argc < 5)
		ft_error_message();
	if (access(argv[1], F_OK) == -1 || access(argv[argc - 1], F_OK) == -1)
		ft_error_message();
	while (i < argc - 1)
	{
		if (ft_strlen(argv[i]) < 2 || access(argv[i], F_OK) != -1)
			ft_error_message();
		i++;
	}
}
