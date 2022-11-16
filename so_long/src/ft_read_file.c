/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:30:28 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/16 17:52:54 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_valid_info(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P' || c == '\n')
	{
		return (1);
	}
	return (0);
}

void	ft_check_arguments(char **str, int num_arg)
{
	int	fd;

	if (num_arg != 2)
	{
		ft_error_message("Error so_long", 1);
	}
	fd = open(str[1], O_RDONLY);
	if (fd == -1)
  {
		ft_error_message("Error so_long : file no found ", 1);
	}
	close(fd);
}

void ft_save_content(t_game *game, char **str)
{
	int fd;
	int i;
	int ii;

	i = 0;
	ii = 0;
	fd = open(str[1], O_RDONLY);
	while (get_next_line(fd) != NULL)
		i++;
	close(fd);
	printf("\n tamano de i{%d}", i);
	game->t_game = ft_calloc(sizeof(char *), i);
	if (!game->t_game)
		ft_error_message("Error so_long : Error malloc ", 1);
	fd = open(str[1], O_RDONLY);
	while (ii < i)
	{
		game->t_game[ii] = get_next_line(fd);
		ii++;
	}
	game->t_game[ii] = 0;
	game->heith = ii;
	close(fd);
}

void ft_check_map(t_game *game, t_e_map *error)
{
	int i;
	int ii;

	i = 0;
	ii = 0;
	while(game->t_game[i])
	{
		ii = 0;
		if ((error->wiht != (int)ft_strlen(game->t_game[i]) && i < game->heith - 1) || ((error->wiht - 1) != (int)ft_strlen(game->t_game[i]) && i == game->heith - 1))
			ft_error_message("Error no es un rectagunlof", 1);
		while (game->t_game[i][ii])
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
				game->p_x=ii;
				game->p_y=i;
			}
			ii++;
		}
		i++;
	}
}


void	ft_read_file(t_game *game, char **str, int num_arg)
{
	t_e_map error;

	ft_check_arguments(str, num_arg);
	ft_save_content(game, str);
	error.n_colec = 0;
	error.n_exit= 0;
	error.n_position = 0;
	error.wiht = (int)ft_strlen(game->t_game[0]);
	game->with = error.wiht;
	ft_check_map(game, &error);
	if (game->heith > error.wiht)
		ft_error_message("Error no es un rectagunlo", 1);
	if (error.n_colec == 0 || error.n_exit > 1 || error.n_exit == 0 || error.n_position > 1 || error.n_position == 0)
		ft_error_message("Error no valida format", 1);
	game->with--;
	game->with *= H_MAX;
	game->heith *= H_MAX;
	game->n_collec = error.n_colec;
}
