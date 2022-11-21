/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:49:07 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/18 12:56:31 by dluna-lo         ###   ########.fr       */
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
	int			fd;
	const char	*ber;
	char		*check;

	ber = ".ber\0";
	if (num_arg != 2)
	{
		ft_error_message(E_ARGUMENTS, 1);
	}
	fd = open(str[1], O_RDONLY);
	if (fd == -1)
	{
		ft_error_message(E_FILE, 1);
	}
	check = ft_strtrim(str[1], ber);
	if (ft_strlen(check) == ft_strlen(str[1]) - 1)
	{
		free(check);
		ft_error_message(E_FORMAT, 1);
	}
	free(check);
	close(fd);
}

void	ft_save_content_in_malloc(t_game *game, char **str, int i, int ii)
{
	int	fd;

	game->t_game = ft_calloc(sizeof(char *), i);
	if (!game->t_game)
		ft_error_message(E_MALLOC, 1);
	fd = open(str[1], O_RDONLY);
	while (ii < i)
	{
		game->t_game[ii] = get_next_line(fd);
		ii++;
	}
	game->heith = ii - 1;
	close(fd);
}

void	ft_save_content(t_game *game, char **str)
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
	if (i == 1)
		ft_error_message(E_F_CLEAN, 1);
	close(fd);
	ft_save_content_in_malloc(game, str, i, ii);
}
