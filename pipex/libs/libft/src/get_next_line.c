/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:48:51 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/11 18:23:40 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_gnl_error(char *str)
{
	if (str)
		free(str);
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	int			rd;
	static char	*rem;

	if (fd < 0 || BUFFER_SIZE < 1 || !line)
		return (-1);
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (ft_gnl_error(rem));
	rd = 1;
	while (!ft_gnl_find_new_line(rem) && rd > 0)
	{
		rd = read(fd, buf, BUFFER_SIZE);
		if (rd < 0)
			return (ft_gnl_error(buf));
		buf[rd] = '\0';
		rem = ft_gnl_str_join(rem, buf);
	}
	free(buf);
	*line = ft_gnl_get_line(rem);
	rem = ft_gnl_str_trim(rem);
	if (rd == 0 && !rem)
		return (0);
	return (1);
}
