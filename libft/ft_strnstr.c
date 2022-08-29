/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 10:16:39 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/01 12:01:53 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	ii;

	i = 0;
	while (needle[i])
		i++;
	if (i == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle[0])
		{
			ii = 0;
			while (needle[ii] && needle[ii] == haystack[i + ii] && i + ii < len)
				ii++;
			if (needle[ii] == 0)
				return ((char *)haystack + i);
		}
		if (++i == len)
			return (0);
	}
	return (0);
}
