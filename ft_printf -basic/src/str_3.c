/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacamilalunalopez <anacamilalunalopez@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 13:51:29 by anacamilalu       #+#    #+#             */
/*   Updated: 2022/08/24 13:51:37 by anacamilalu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strtostr_rango(char *str1, char *str2, int start2, int end2)
{
	int	i;

	i = 0;
	while (str2[start2] && end2 > start2)
	{
		str1[i] = str2[start2];
		start2++;
		i++;
	}
	str1[i] = '\0';
}

void	ft_fill(char *str, char fill, int number)
{
	int		i;
	int		leng_str;
	char	copy_str[40];

	leng_str = ft_strlen(str);
	copy_str[0] = '\0';
	ft_strtostr(copy_str, str);
	i = 0;
	while (i < (number - leng_str))
	{
		str[i] = fill;
		i++;
	}
	ft_strtostrn(str, copy_str, i);
}
