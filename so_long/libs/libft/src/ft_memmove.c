/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:31:38 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/08 10:47:37 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*str_dst;
	unsigned char	*str_src;

	i = -1;
	str_dst = ((unsigned char *)dst);
	str_src = ((unsigned char *)src);
	if (!dst && !src)
		return (NULL);
	if (dst > src)
	{
		while (++i < len)
		{
			str_dst[len - 1 - i] = str_src[len - 1 - i];
		}
	}
	else
	{
		while (++i < len)
		{
			str_dst[i] = str_src[i];
		}
	}
	return (dst);
}
