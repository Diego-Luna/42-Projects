/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 11:14:13 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/08 12:03:12 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	ft_separator(char c, char *charset)
{
	int		i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static const char
	*ft_next_str(const char **pos_in_str, char *charset, int *next_str_len)
{
	int			i;
	const char	*str_start;

	*next_str_len = 0;
	str_start = 0;
	i = 0;
	while ((*pos_in_str)[i])
	{
		if (ft_separator((*pos_in_str)[i], charset) && str_start != 0)
		{
			*pos_in_str = str_start + *next_str_len;
			return (str_start);
		}
		else if (!ft_separator((*pos_in_str)[i], charset) && str_start == 0)
			str_start = &(*pos_in_str)[i];
		if (!ft_separator((*pos_in_str)[i], charset))
			*next_str_len = *next_str_len + 1;
		i++;
	}
	*pos_in_str = str_start + *next_str_len;
	if (*next_str_len == 0)
		return (0);
	return (str_start);
}

static char	**ft_build_tab(const char *str, char *charset)
{
	int			nb_str;
	char		**strs;
	int			next_str_len;
	const char	*pos_in_str;

	nb_str = 0;
	next_str_len = 0;
	pos_in_str = str;
	while (ft_next_str(&pos_in_str, charset, &next_str_len))
		nb_str++;
	strs = (char **)malloc(sizeof(char *) * (nb_str + 1));
	if (!(strs))
		return (0);
	return (strs);
}

//char	**ft_split(char *str, char *charset)
char	**ft_split(char const *s, char c)
{
	int			i;
	char		**strs;
	int			next_str_len;
	const char	*next_str;
	const char	*pos_in_str;

	strs = ft_build_tab(s, &c);
	if (!(strs))
		return (0);
	i = 0;
	pos_in_str = s;
	next_str = ft_next_str(&pos_in_str, &c, &next_str_len);
	while (next_str)
	{
		strs[i] = (char *)malloc(sizeof(char) * next_str_len + 1);
		if (!(strs[i]))
			return (0);
		ft_strncpy(strs[i], next_str, next_str_len);
		i++;
		next_str = ft_next_str(&pos_in_str, &c, &next_str_len);
	}
	strs[i] = 0;
	return (strs);
}
