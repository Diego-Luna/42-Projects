/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_paht.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:13:49 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/11 11:42:02 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libs/pipex_bonus.h"

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
			if (!envp_path)
				ft_error_message("Error ./pipex path:envp", 0);
			break ;
		}
		i++;
	}
	if (!envp_path)
		ft_error_message("Error ./pipex: Env_path not found", 0);
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
		check_path = ft_strjoin(path[i], cmd);
		if (access(check_path, F_OK | X_OK) == 0)
			break ;
		free(check_path);
	}
	i = -1;
	while (path[++i])
		free(path[i]);
	free(path[i]);
	return (check_path);
}

char	*ft_get_comand_p2(char **paths, char *cmd)
{
	char *tem;
	char *new_c;
	int i;

	i = 0;
	while (paths[i])
	{
		tem = ft_strjoin(*paths, "/");
		new_c = ft_strjoin(tem, cmd);
		free(tem);
		if (access(tem, F_OK | X_OK) == 0)
			return (new_c);
		free(new_c);
		i++;
	}
	return (NULL);
}
