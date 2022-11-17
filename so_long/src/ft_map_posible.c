/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_posible.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:57:44 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/17 17:45:41 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_checkrecursive(t_recursive *info, int x, int y)
{
	if (x > info->x_max || y > info->y_max || x < 0 || y < 0
		|| !(info->table[y][x] == '0' || info->table[y][x] == 'P'
		|| info->table[y][x] == 'C'))
	{
		return (1);
	}
	return (0);
}

void	ft_recursive_table(t_recursive *info, int x, int y)
{
	if (info->table[y][x] == 'E')
	{
		info->is_path_exit = 1;
		return ;
	}
	if (info->table[y][x] == 'C')
	{
		info->n_collec--;
	}
	if (ft_checkrecursive(info, x, y) == 1)
	{
		return ;
	}
	info->table[y][x] = 'X';
	ft_recursive_table(info, x, y - 1);
	ft_recursive_table(info, x, y + 1);
	ft_recursive_table(info, x + 1, y);
	ft_recursive_table(info, x - 1, y);
}

int	ft_map_posible(t_game *game)
{
	t_recursive	info;

	info.x_max = game->with;
	info.y_max = game->heith;
	info.table = game->t_game;
	info.is_posible = 0;
	info.n_collec = game->n_collec;
	ft_recursive_table(&info, game->p_x, game->p_y);
	if (info.is_path_exit == 1 && info.n_collec == 0)
	{
		return (1);
	}
	return (0);
}
