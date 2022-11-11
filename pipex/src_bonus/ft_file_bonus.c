/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 07:23:10 by diegofranci       #+#    #+#             */
/*   Updated: 2022/11/11 08:05:15 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

void	ft_use_here_bonus(char *argv, v_state *state)
{
	if (state->here_doc)
		state->outfile = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0000644);
	else
		state->outfile = open(argv, O_CREAT | O_RDWR | O_TRUNC, 0000644);
	if (state->outfile < 0)
		ft_error_message("Error Outfile", 1);
}

void	ft_here_doc(char *argv, v_state *state)
{
	int		file;
	char	*buf;

	file = open(".heredoc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (file < 0)
		ft_error_message("Error Here doc", 1);
	while (1)
	{
		write(1, "heredoc> ", 9);
		if (get_next_line(0, &buf) < 0)
			exit(1);
		if (!ft_strncmp(argv, buf, ft_strlen(argv) + 1))
			break ;
		write(file, buf, ft_strlen(buf));
		write(file, "\n", 1);
		free(buf);
	}
	free(buf);
	close(file);
	state->infile = open(".heredoc_tmp", O_RDONLY);
	if (state->infile < 0)
	{
		unlink(".heredoc_tmp");
		ft_error_message("Error Here doc", 1);
	}
}

void	ft_create_here_bonus(char **argv, v_state *state)
{
	if (!ft_strncmp("here_doc", argv[1], 9))
		ft_here_doc(argv[2], state);
	else
	{
		state->infile = open(argv[1], O_RDONLY);
		if (state->infile < 0)
			ft_error_message("Infile", 1);
	}
}