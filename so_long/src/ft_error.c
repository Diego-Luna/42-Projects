/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:58:34 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/16 17:50:16 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error_message(char *str, int error)
{
	if (!str)
		perror("Error: ./pipex");
	else
		perror(str);
	exit(error);
}

int ft_exit_x(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	free(game->t_game);
	ft_error_message("Diego exit", 1);
	exit(0);
	return (0);
}