/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:33:12 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/10/17 14:52:15 by dluna-lo         ###   ########.fr       */
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
