/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:00:42 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/01 13:07:05 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		str_len;
	int		i;
	char	*buffer;

	str_len = 0;
	i = 0;
	if (s1)
		while (s1[str_len])
			str_len++;
	else
		str_len = 0;
	buffer = (char *)malloc(sizeof(*buffer) * (str_len + 1));
	if (!buffer)
		return (0);
	while (i < str_len)
	{
		buffer[i] = s1[i];
		i++;
	}
	buffer[i] = 0;
	return (buffer);
}
