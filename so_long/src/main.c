/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:31:47 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/18 11:50:19 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_caracter(t_game *game, int direction)
{
	game->n_keys++;
	if (direction == 1)
	{
		ft_move_caracter_up(game);
	}
	if (direction == 2)
	{
		ft_move_caracter_dow(game);
	}
	if (direction == 3)
	{
		ft_move_caracter_righ(game);
	}
	if (direction == 4)
	{
		ft_move_caracter_left(game);
	}
	ft_printf("\n press: %i", game->n_keys);
}

int	deal_key(int key, t_game *game)
{
	if (key == 53)
	{
		mlx_destroy_window(game->mlx, game->win);
		exit (0);
	}
	if (key == 13)
	{
		ft_move_caracter(game, 1);
	}
	if (key == 1)
	{
		ft_move_caracter(game, 2);
	}
	if (key == 2)
	{
		ft_move_caracter(game, 3);
	}
	if (key == 0)
	{
		ft_move_caracter(game, 4);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_read_file(&game, argv, argc);
	game.n_keys = 0;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.with, game.heith, "so_long");
	ft_create_map(&game);
	mlx_key_hook(game.win, deal_key, &game);
	mlx_hook(game.win, 17, 0, ft_exit_x, &game);
	mlx_loop(game.mlx);
	return (0);
}
