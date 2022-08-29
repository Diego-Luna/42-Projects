/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacamilalunalopez <anacamilalunalopez@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 20:17:36 by diegofranci       #+#    #+#             */
/*   Updated: 2022/08/24 15:11:56 by anacamilalu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_findc(const char *str, int start, char c)
{
	while (str[start])
	{
		if (str[start] == c)
		{
			return (start);
		}
		start++;
	}
	return (-1);
}

int	ft_findc_next_same(const char *str, int start, char c)
{
	int	i;

	i = 0;
	while (str[start])
	{
		if (str[start] == c)
		{
			start++;
			i++;
		}
		else
		{
			return (i);
		}
	}
	return (-1);
}

int	ft_strfind(const char *str, int start, char c, char c_2)
{
	while (str[start])
	{
		if (str[start] == c && str[start + 1] == c_2)
		{
			return (start);
		}
		start++;
	}
	return (-1);
}

int	ft_strfin(const char *str, char c)
{
	int	i;
	int	ii;

	i = 0;
	ii = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			ii++;
		}
		i++;
	}
	return (ii);
}

int	ft_strfin_end(const char *str, char c, int end)
{
	int	i;
	int	ii;

	i = 0;
	ii = 0;
	while (str[i] && i <= end)
	{
		if (str[i] == c)
		{
			ii++;
		}
		i++;
	}
	return (ii);
}
