/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:13:13 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/01 13:10:26 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*str_dst;
	unsigned char	*str_src;

	i = 0;
	str_dst = ((unsigned char *)dst);
	str_src = ((unsigned char *)src);
	if (dst > src)
	{
		while (i < len)
		{
			str_dst[len - 1 - i] = str_src[len - 1 - i];
			i++;
		}
	}
	else
	{
		while (i < len)
		{
			str_dst[i] = str_src[i];
			i++;
		}
	}
	return (dst);
}
