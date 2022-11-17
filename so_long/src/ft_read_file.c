/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:30:28 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/17 17:16:27 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_save_info(t_game *game, char **str, int i)
{
	int	fd;
	int	ii;

	ii = 0;
	game->t_game = ft_calloc(sizeof(char *), i);
	if (!game->t_game)
		ft_error_message("Error so_long : Error malloc ", 1);
	fd = open(str[1], O_RDONLY);
	while (ii < i)
	{
		game->t_game[ii] = get_next_line(fd);
		ii++;
	}
	close(fd);
}

void	ft_save_table(t_game *game, char **str)
{
	int		fd;
	int		i;
	int		ii;
	char	*s1;

	i = 0;
	ii = 0;
	fd = open(str[1], O_RDONLY);
	s1 = NULL;
	while ((i == 0) || (s1 != NULL && i > 0))
	{
		free(s1);
		s1 = get_next_line(fd);
		i++;
	}
	close(fd);
	ft_save_info(game, str, i);
}

void	ft_check_map(t_game *game, t_e_map *error)
{
	int	i;
	int	ii;

	i = -1;
	while (game->t_game[++i])
	{
		ii = -1;
		ft_error_check_table(game, error, i);
		while (game->t_game[i][++ii])
		{
			if (ft_valid_info(game->t_game[i][ii]) == 0)
				ft_error_message("Error file no valid", 1);
			if (game->t_game[i][ii] == 'E')
				error->n_exit++;
			if (game->t_game[i][ii] == 'C')
				error->n_colec++;
			if (game->t_game[i][ii] == 'P')
			{
				error->n_position++;
				game->p_x = ii;
				game->p_y = i;
			}
		}
	}
}

void	ft_ckeck_close_map(t_game *game)
{
	int	i;
	int	ii;

	i = 0;
	ii = 0;
	while (game->t_game[0][i] == '1')
	{
		i++;
	}
	while (game->t_game[game->heith / H_MAX - 1][ii] == '1')
	{
		ii++;
	}
	if (i != ((int)ft_strlen(game->t_game[0]) - 1)
		|| ii != ((int)ft_strlen(game->t_game[game->heith / H_MAX - 1])))
		ft_error_message("1Error map no close", 1);
	ii = 0;
	while (game->t_game[ii])
	{
		if (game->t_game[ii][0] != '1'
			|| game->t_game[ii][(int)ft_strlen(game->t_game[ii]) - 2] != '1')
			ft_error_message("=Error map no close", 1);
		ii++;
	}
}

void	ft_read_file(t_game *game, char **str, int num_arg)
{
	t_e_map	error;

	ft_check_arguments(str, num_arg);
	ft_save_content(game, str);
	error.n_colec = 0;
	error.n_exit = 0;
	error.n_position = 0;
	error.wiht = (int)ft_strlen(game->t_game[0]);
	game->with = error.wiht;
	ft_check_map(game, &error);
	if (game->heith > error.wiht)
		ft_error_message("Error no es un rectagunlo", 1);
	if (error.n_colec == 0 || error.n_exit > 1 || error.n_exit == 0
		|| error.n_position > 1 || error.n_position == 0)
		ft_error_message("Error no valida format", 1);
	game->with--;
	game->with *= H_MAX;
	game->heith *= H_MAX;
	game->n_collec = error.n_colec;
	ft_ckeck_close_map(game);
	if (ft_map_posible(game) == 0)
		ft_error_message("Map no Posible", 1);
	ft_free_table(game->t_game);
	ft_save_table(game, str);
}
