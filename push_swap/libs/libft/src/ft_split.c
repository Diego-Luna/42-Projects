/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:32:38 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/08 10:47:37 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_add_strs(const char *s, char c, int *start)
{
	int		i;
	char	*str;
	int		ii;

	i = 0;
	ii = *start;
	while (s[ii] == c)
	{
		ii++;
	}
	while (s[ii] && s[ii] != c)
	{
		ii++;
		i++;
	}
	str = ft_substr(s, ii - i, i);
	*start = ii;
	return (str);
}

static int	ft_number_words(const char *s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		ii;
	int		words;
	char	**strs;

	if (!s)
		return (NULL);
	i = 0;
	words = ft_number_words(s, c);
	strs = ft_calloc(sizeof(char *), words + 1);
	if (!strs)
		return (NULL);
	ii = 0;
	while (i < words)
	{
		strs[i] = ft_add_strs(s, c, &ii);
		i++;
	}
	return (strs);
}
