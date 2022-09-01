#include "get_next_line.h"

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

char	*get_next_line(int fd)
{
	char		*line;
	char		*temporary;
	static char	*save = NULL;

	line = NULL;
	temporary = NULL;
	if (fd < 0 && BUFFER_SIZE <= 0)
		return (NULL);
	ft_read_line(fd, &save, &temporary);
	return (line);
}
