/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:42:51 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/11 08:05:24 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# define E_PIPE "Error: ./pipex : Error using pipe"

typedef struct va_states
{
	int		infile;
	int		outfile;
	char	*env_path;
	char	**cmd_paths;
	char	*cmd;
	char	**cmd_args;
	int		here_doc;
	pid_t	pid;
	int		cmd_nmbs;
	int		pipe_nmbs;
	int		*pipe;
	int		index;
}	v_state;

void	ft_error_message(char *str, int error);
void	ft_run_comand(char *comds, char **envp);
char	*ft_get_comand_p(char **envp, char *cmd);
void	ft_check_parameters(int argc, char *argv[], char *envp[]);
void	ft_father(char **argv, char **envp, v_state *state, int *file);
void	ft_childs(char **argv, char **envp, v_state *state, int	*file);

void	ft_use_here_bonus(char *argv, v_state *state);
void	ft_get_here_bonus(char **argv, v_state *pipex);

#endif