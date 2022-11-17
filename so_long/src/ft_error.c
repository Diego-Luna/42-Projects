/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:58:34 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/17 10:16:42 by dluna-lo         ###   ########.fr       */
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
	ft_free_table(game);
	ft_error_message("\nDiego exit", 1);
	exit(0);
	return (0);
}

void ft_free_table(t_game *game)
{
	int i;

	i = 0;
	while (game->t_game[i])
	{
		free(game->t_game[i]);
		i++;
	}
	free(game->t_game);
}
