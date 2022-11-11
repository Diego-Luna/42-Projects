/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 10:42:51 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/10 17:55:23 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

# define E_PIPE "Error: ./pipex : Error using pipe"

void	ft_error_message(char *str, int error);
char	*ft_get_comand_p(char **envp, char *cmd);
void	ft_run_comand(char *comds, char **envp);
void	ft_childs(char **argv, char **envp, int *state, int	*file);
void	ft_father(char **argv, char **envp, int *state, int *file);
void	ft_check_parameters(int argc, char *argv[], char *envp[]);

#endif