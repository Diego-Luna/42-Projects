/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 13:12:36 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/17 16:03:15 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_control_imgs(t_game *game, int x, int y, char c)
{
	if (c == '0')
		ft_put_img(game, x, y, "./img/cellule/20x20.xpm");
	else if (c == '1')
		ft_put_img(game, x, y, "./img/obstacle/20x20.xpm");
	else if (c == 'C')
		ft_put_img(game, x, y, "./img/points/20x20.xpm");
	else if (c == 'E')
		ft_put_img(game, x, y, "./img/exit/20x20.xpm");
	else if (c == 'P')
		ft_put_img(game, x, y, "./img/dog/20x20.xpm");
}

void	ft_add_imgs(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->t_game[y])
	{
		x = 0;
		while (game->t_game[y][x])
		{
			ft_control_imgs(game, x, y, game->t_game[y][x]);
			x++;
		}
		y++;
	}
}

void	ft_create_map(t_game *game)
{
	ft_background_color(game);
	ft_add_imgs(game);
}
