/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:33:35 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/08 10:47:37 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	i;
	size_t	length_dst;
	size_t	length_src;

	i = 0;
	length_src = ft_strlen(src);
	length_dst = ft_strlen(dst);
	if (length_dst >= dstsize || dstsize <= 0)
	{
		return (length_src + dstsize);
	}
	while (src[i] && (length_dst + i) < (dstsize - 1))
	{
		dst[length_dst + i] = src[i];
		i++;
	}
	dst[length_dst + i] = '\0';
	return (length_dst + length_src);
}
