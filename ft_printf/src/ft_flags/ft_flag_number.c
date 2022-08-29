/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacamilalunalopez <anacamilalunalopez@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:45:23 by diegofranci       #+#    #+#             */
/*   Updated: 2022/08/25 20:27:19 by anacamilalu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_negative_number(char *str, t_printf *ob_print)
{
	char	str_old;

	ft_strtostrn(&str_old, str, 0);
	str[0] = '-';
	ft_strtostrn(str, &str_old, 1);
	ft_strtostrn(str, ob_print->strold, 1 + (int)ft_strlen(&str_old));
}

// void	ft_positivo_or_negative(char *str, t_printf *ob_print, int i)
int	ft_is_negative_number(char *str)
{
	if (str[0] == '-' && ft_isdigit(str[1]) == 1)
	{
		return (1);
	}
	return (-1);
}

void	ft_flag_number(t_printf *ob_print, char *flags, char *str)
{
	char	ceros[200];
	int		leng_numbes;
	int		leng_string;
	int		full;
	int		i;

	leng_string = ft_strlen(str);
	leng_numbes = ft_atoi(flags);
	if (leng_numbes > leng_string)
	{
		full = leng_numbes - leng_string;
		i = 0;
		while (full > 0)
		{
			ceros[i] = '0';
			i++;
			full--;
		}
		ceros[i] = '\0';
		ft_strtostr(ob_print->strold, str);
		ft_strtostr(str, ceros);
		if (ft_is_negative_number(ob_print->strold) == 1)
		{
			ft_negative_number(str, ob_print);
			ft_strtostrn(str, ob_print->strold + 1, (int)ft_strlen(str));
		}
		else
		{
			ft_strtostrn(str, ob_print->strold, i);
		}
	}
}
