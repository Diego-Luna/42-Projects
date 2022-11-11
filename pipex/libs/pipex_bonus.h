/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:42:51 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/11 18:17:52 by dluna-lo         ###   ########.fr       */
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
	int		i;
}			t_state;

void		ft_error_message(char *str, int error);
void		ft_run_comand(char *comds, char **envp);
void		ft_check_parameters(int argc, char *argv[], char *envp[],
				t_state *state);
void		ft_father(char **argv, char **envp, t_state *state, int *file);

char		*ft_find_path(char **envp);
void		ft_pipe_close(t_state *state);
void		ft_cmd_error(t_state *state);
void		ft_pipe_error(t_state *state);
void		ft_childs_clean(t_state *state);
void		ft_create_pipes(t_state *state);
void		ft_father_clean(t_state *state);
char		*ft_get_comand_p(char **paths, char *cmd);
void		ft_use_here_bonus(char *argv, t_state *state);
void		ft_get_here_bonus(char **argv, t_state *pipex);
void		ft_create_here_bonus(char **argv, t_state *state);
void		ft_childs(t_state state, char **envp, char **argv);

#endif