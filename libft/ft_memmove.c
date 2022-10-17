/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:31:38 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/10/17 14:48:04 by dluna-lo         ###   ########.fr       */
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
