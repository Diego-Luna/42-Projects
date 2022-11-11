/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_paht.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 16:13:49 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/11 18:17:37 by dluna-lo         ###   ########.fr       */
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

char	*ft_get_comand_p(char **paths, char *cmd)
{
	char	*tem;
	char	*new_c;

	while (*paths)
	{
		tem = ft_strjoin(*paths, "/");
		new_c = ft_strjoin(tem, cmd);
		free(tem);
		if (access(new_c, 0) == 0)
			return (new_c);
		free(new_c);
		paths++;
	}
	return (NULL);
}
