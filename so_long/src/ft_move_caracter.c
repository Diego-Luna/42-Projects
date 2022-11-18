/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_caracter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:44:07 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/18 13:02:34 by dluna-lo         ###   ########.fr       */
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
		ft_control_imgs(game, game->p_x, game->p_y, '0');
		game->p_y -= 1;
		game->t_game[game->p_y][game->p_x] = 'P';
		ft_control_imgs(game, game->p_x, game->p_y, 'P');
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
		ft_control_imgs(game, game->p_x, game->p_y, '0');
		game->p_y += 1;
		game->t_game[game->p_y][game->p_x] = 'P';
		ft_control_imgs(game, game->p_x, game->p_y, 'P');
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
		ft_control_imgs(game, game->p_x, game->p_y, '0');
		game->p_x += 1;
		game->t_game[game->p_y][game->p_x] = 'P';
		ft_control_imgs(game, game->p_x, game->p_y, 'P');
	}
}

void	ft_move_caracter_left(t_game *game)
{
	if (game->t_game[game->p_y][game->p_x - 1] == 'C')
		game->n_collec--;
	if (game->t_game[game->p_y][game->p_x - 1] == 'E' && game->n_collec == 0)
		ft_exit_x(game);
	if (game->t_game[game->p_y][game->p_x - 1] == '0' ||
		game->t_game[game->p_y][game->p_x - 1] == 'C')
	{
		game->t_game[game->p_y][game->p_x] = '0';
		ft_control_imgs(game, game->p_x, game->p_y, '0');
		game->p_x -= 1;
		game->t_game[game->p_y][game->p_x] = 'P';
		ft_control_imgs(game, game->p_x, game->p_y, 'P');
	}
}
