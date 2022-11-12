/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:49:00 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/12 17:57:31 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_gnl_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

int	ft_gnl_find_new_line(char *str)
{
	if (str)
	{
		while (*str)
		{
			if (*str == '\n')
				return (1);
			str++;
		}
	}
	return (0);
}

char	*ft_gnl_str_join(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	str = (char *)malloc(ft_gnl_strlen(s1) + ft_gnl_strlen(s2) + 1);
	if (!str)
		return (NULL);
	if (s1)
		while (s1[++i])
			str[i] = s1[i];
	else
		i = 0;
	if (s2)
		while (s2[++j])
			str[i + j] = s2[j];
	else
		j = 0;
	str[i + j] = '\0';
	if (s1)
		free(s1);
	return (str);
}

char	*ft_gnl_str_trim(char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	i++;
	while (str[i + j])
	{
		str[j] = str[i + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_gnl_get_line(char *str)
{
	size_t	i;
	size_t	j;
	char	*new_line;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	new_line = (char *)malloc(i + 1);
	if (!new_line)
		return (NULL);
	while (str[j] != '\n' && str[j] != '\0')
	{
		new_line[j] = str[j];
		j++;
	}
	new_line[j] = '\0';
	return (new_line);
}
