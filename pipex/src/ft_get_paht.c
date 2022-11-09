/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_paht.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:13:49 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/09 11:21:49 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex.h"

char	**ft_get_path(char **envp)
{
	char	*envp_path;
	char	**pacth;
	int		i;

	envp_path = NULL;
	pacth = NULL;
	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])) != 0)
		{
			envp_path = ft_strdup(envp[i]);
			// printf("\n 2**> envp_path:{%s} envp[i]:{%s}", envp_path, envp[i]);
			if (!envp_path)
				ft_error_message("f_g_p envp_path Error ./pipex path:envp");
			break ;
		}
		i++;
	}
	if (!envp_path)
		ft_error_message("f_g_p Error envp_path 2 ft_error_message : Env_path not found");
	// printf("\n 3---> envp_path:{%s}", envp_path);
	pacth = ft_split(envp_path, ':');
	free(envp_path);
	return (pacth);
}

char	*ft_get_comand_p(char **envp, char *cmd)
{
	char	**path;
	char	*check_path;
	int		i;

	i = -1;
	if (access(cmd + 1, F_OK | X_OK) == 0)
		return (cmd + 1);
	path = ft_get_path(envp);
	while (path[++i])
	{
		// printf("\n 1*> path:{%s}", path[i]);
		check_path = ft_strjoin(path[i], cmd);
		if (access(check_path, F_OK | X_OK) == 0)
			break;
		free(check_path);
	}
	i = -1;
	while (path[++i])
		free(path[i]);
	free(path[i]);
	return (check_path);
}