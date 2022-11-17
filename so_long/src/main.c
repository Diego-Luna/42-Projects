/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:31:47 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/17 15:39:25 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_caracter_up(t_game *game)
{
	if (game->t_game[game->p_y - 1][game->p_x] == 'C')
		game->n_collec--;
	if (game->t_game[game->p_y - 1][game->p_x] == 'E' && game->n_collec == 0)
		ft_exit_x(game);
	if (game->t_game[game->p_y - 1][game->p_x] == '0' ||
		game->t_game[game->p_y - 1][game->p_x] == 'C')
	{
		game->t_game[game->p_y][game->p_x] = '0';
		game->p_y -= 1;
		game->t_game[game->p_y][game->p_x] = 'P';
		ft_create_map(game);
	}
}
void	ft_move_caracter_dow(t_game *game)
{
	if (game->t_game[game->p_y + 1][game->p_x] == 'C')
		game->n_collec--;
	if (game->t_game[game->p_y + 1][game->p_x] == 'E' && game->n_collec == 0)
		ft_exit_x(game);
	if (game->t_game[game->p_y + 1][game->p_x] == '0' ||
		game->t_game[game->p_y + 1][game->p_x] == 'C')
	{
		game->t_game[game->p_y][game->p_x] = '0';
		game->p_y += 1;
		game->t_game[game->p_y][game->p_x] = 'P';
		ft_create_map(game);
	}
}
void	ft_move_caracter_righ(t_game *game)
{
	if (game->t_game[game->p_y][game->p_x + 1] == 'C')
		game->n_collec--;
	if (game->t_game[game->p_y][game->p_x + 1] == 'E' && game->n_collec == 0)
		ft_exit_x(game);
	if (game->t_game[game->p_y][game->p_x + 1] == '0' ||
		game->t_game[game->p_y][game->p_x + 1] == 'C')
	{
		game->t_game[game->p_y][game->p_x] = '0';
		game->p_x += 1;
		game->t_game[game->p_y][game->p_x] = 'P';
		ft_create_map(game);
	}
}
void	ft_move_caracter_left(t_game *game)
{
	if (game->t_game[game->p_y][game->p_x - 1] == 'C')
		game->n_collec--;
	if (game->t_game[game->p_y][game->p_x - 1] == 'E' && game->n_collec == 0)
		ft_exit_x(game);
	if (game->t_game[game->p_y][game->p_x - 1] == '0' ||
		game->t_game[game->p_y][game->p_x + 1] == 'C')
	{
		game->t_game[game->p_y][game->p_x] = '0';
		game->p_x -= 1;
		game->t_game[game->p_y][game->p_x] = 'P';
		ft_create_map(game);
	}
}

void	ft_move_caracter(t_game *game, int direction)
{
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
}

int	deal_key(int key, t_game *game)
{
	if (key == 53)
	{
		free(game->t_game);
		mlx_destroy_window(game->mlx, game->win);
		exit (0);
	}
	if (key == 13)
	{
		game->n_keys++;
		ft_move_caracter(game, 1);
		ft_printf("\n press: %i", game->n_keys);
	}
	if (key == 1)
	{
		game->n_keys++;
		ft_move_caracter(game, 2);
		ft_printf("\n press: %i", game->n_keys);
	}
	if (key == 2)
	{
		game->n_keys++;
		ft_move_caracter(game, 3);
		ft_printf("\n press: %i", game->n_keys);
	}
	if (key == 0)
	{
		game->n_keys++;
		ft_move_caracter(game, 4);
		ft_printf("\n press: %i", game->n_keys);
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
	ft_free_table(&game);
	return (0);
}
