/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:48:51 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/03 16:15:30 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_before_newline(const char *str)
{
	int		i;
	char	*res;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] != '\0' && str[i] == '\n')
		i++;
	res = ft_malloc_zero(i + 1, sizeof * res);
	if (!res)
	{
		return (NULL);
	}
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		res[i] = str[i];
	}
	return (res);
}

char	*get_after_newline(const char *str)
{
	char	*res;
	int		ii;
	int		i;

	i = 0;
	ii = 0;
	while (str && str[ii])
		ii++;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] != '\0' && str[i] == '\n')
		i++;
	res = ft_malloc_zero((ii - i) + 1, sizeof * res);
	if (!res)
	{
		return (NULL);
	}
	ii = 0;
	while (str[i + ii])
	{
		res[ii] = str[i + ii];
		ii++;
	}
	return (res);
}

void	ft_read_line(int fd, char **save, char **temporary)
{
	char	*buf;
	int		status;

	buf = malloc(sizeof * buf * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	status = 1;
	while (status > 0)
	{
		status = read(fd, buf, BUFFER_SIZE);
		if (status == -1)
		{
			ft_strs_cleans(&buf, save, temporary);
			return ;
		}
		buf[status] = '\0';
		*temporary = ft_strdup(*save);
		ft_strs_cleans(save, 0, 0);
		*save = ft_join_strs(*temporary, buf);
		ft_strs_cleans(temporary, 0, 0);
		if (ft_contains_newline(*save))
			break ;
	}
	ft_strs_cleans(&buf, 0, 0);
}

char	*ft_parse_line(char **save, char **temporary)
{
	char	*line;

	*temporary = ft_strdup(*save);
	ft_strs_cleans(save, 0, 0);
	*save = get_after_newline(*temporary);
	line = get_before_newline(*temporary);
	ft_strs_cleans(temporary, 0, 0);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*temporary;
	static char	*save[OPEN_MAX];

	line = NULL;
	temporary = NULL;
	if (fd > OPEN_MAX || fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_line(fd, &save[fd], &temporary);
	if (save[fd] && *save[fd] != '\0')
	{
		line = ft_parse_line(&save[fd], &temporary);
	}
	if (!line || *line == '\0')
	{
		ft_strs_cleans(&save[fd], &line, &temporary);
		return (NULL);
	}
	return (line);
}
