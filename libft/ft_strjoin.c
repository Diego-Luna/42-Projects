/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 10:44:33 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/04 11:02:54 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	if (s1)
		while (s1[i])
			i++;
	if (s2)
		while (s2[j])
			j++;
	str = (char *)malloc(i + j + 1);
	if (str == NULL)
		return (NULL);
	j = -1;
	while (s1[++j])
		str[j] = s1[j];
	j = -1;
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = 0;
	return (str);
}
