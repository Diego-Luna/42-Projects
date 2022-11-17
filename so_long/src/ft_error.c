/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:58:34 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/17 16:39:31 by dluna-lo         ###   ########.fr       */
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

int	ft_exit_x(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	ft_free_table(game->t_game);
	ft_error_message("\nDiego exit", 1);
	exit(0);
	return (0);
}

void	ft_free_table(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_error_check_table(t_game *game, t_e_map *error, int i)
{
	if ((error->wiht != (int)ft_strlen(game->t_game[i]) && i < game->heith - 1)
		|| ((error->wiht - 1) != (int)ft_strlen(game->t_game[i])
			&& i == game->heith - 1))
		ft_error_message("Error no es un rectagunlof", 1);
}
