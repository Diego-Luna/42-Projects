/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacamilalunalopez <anacamilalunalopez@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:47:49 by anacamilalu       #+#    #+#             */
/*   Updated: 2022/08/31 16:26:08 by anacamilalu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_malloc_zero(size_t count, size_t size)
{
	void			*r;
	size_t			total;
	unsigned char	*p;

	total = count * size;
	r = malloc(total);
	if (!r)
	{
		return (NULL);
	}
	p = (unsigned char *)r;
	while (total != 0)
	{
		*p = '\0';
		p++;
		total--;
	}
	return (r);
}

char	*ft_strdup(const char *str_1)
{
	int		i;
	char	*str_2;

	if (!str_1)
	{
		return (ft_strdup(""));
	}
	i = 0;
	while (str_1[i])
		i++;
	str_2 = ft_malloc_zero(i + 1, sizeof * str_2);
	if (!str_2)
	{
		return (NULL);
	}
	i = 0;
	while (str_1[i])
	{
		str_2[i] = str_1[i];
		i++;
	}
	return (str_2);
}

void	ft_strs_cleans(char **str_1, char **str_2, char **str_3)
{
	if (str_1 && *str_1)
	{
		free(*str_1);
		*str_1 = NULL;
	}
	if (str_2 && *str_2)
	{
		free(*str_2);
		*str_2 = NULL;
	}
	if (str_3 && *str_3)
	{
		free(*str_3);
		*str_3 = NULL;
	}
}

int	contains_newline(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*join_strs(const char *s1, const char *s2)
{
	char	*s;
	int		len;
	int		i;

	len = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s1 && s1[len])
		len++;
	i = 0;
	while (s2 && s2[i])
		i++;
	s = ft_malloc_zero(len + i + 1, sizeof * s);
	if (!s)
		return (NULL);
	len = -1;
	while (s1 && s1[++len])
		s[len] = s1[len];
	i = -1;
	while (s2 && s2[++i])
		s[len + i] = s2[i];
	return (s);
}
