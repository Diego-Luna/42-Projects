/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:33:35 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/10/17 14:48:36 by dluna-lo         ###   ########.fr       */
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
