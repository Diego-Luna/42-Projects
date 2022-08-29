/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 12:48:06 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/07 13:29:38 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*str;
	size_t		i;

	i = 0;
	str = malloc(count * size);
	if (str == NULL)
		return (0);
	while (i < count * size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
