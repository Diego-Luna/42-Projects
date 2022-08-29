/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:43:30 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/06 12:27:02 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	length_dst;
	unsigned int	length_src;

	i = 0;
	length_dst = 0;
	length_src = 0;
	while (dst[length_dst] != '\0')
		length_dst++;
	while (src[length_src] != '\0')
		length_src++;
	if (dstsize <= length_dst)
	{
		return (length_src + dstsize);
	}
	while (src[i] != '\0' && (length_dst + i) < (dstsize - 1))
	{
		dst[length_dst + i] = src[i];
		i++;
	}
	dst[length_dst + i] = '\0';
	return (length_dst + length_src);
}
