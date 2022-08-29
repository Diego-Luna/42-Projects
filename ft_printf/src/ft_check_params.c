/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:03:25 by diegofranci       #+#    #+#             */
/*   Updated: 2022/05/24 08:24:54 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_convers(t_printf *ob_print, char c)
{
	size_t	i;

	i = ft_strlen(ob_print->convers);
	ob_print->convers[i] = c;
	ob_print->convers[i + 1] = '\0';
}

int	ft_check(char s)
{
	if (s == 'c' || s == 's' || s == 'p' || s == 'd' || s == 'i' || s == 'u'
		|| s == 'x' || s == 'X' || s == '%')
	{
		return (1);
	}
	return (0);
}

int	ft_strchrall(const char *s, char c, t_printf *ob_print)
{
	int	i;
	int	i_old;
	int	num;

	i = 0;
	num = 0;
	i_old = 0;
	while (s[i])
	{
		if (s[i] == c && ft_check(s[i + 1]) && (i == 0 || i > (i_old)))
		{
			num++;
			i_old = i + 1;
			ft_add_convers(ob_print, s[i + 1]);
		}
		else if (s[i] == c && s[i - 1] != '%')
		{
			ft_str_flags(s, i, ob_print);
			i--;
		}
		i++;
	}
	return (num);
}

//int	ft_check_params(va_list arg, t_printf *ob_print, const char *str)
int	ft_check_params(va_list arg, t_printf *ob_print)
{
	int	num;

	if (!arg)
	{
		return (-1);
	}
	num = ft_strchrall(ob_print->str, '%', ob_print);
	if (num < 0)
	{
		return (-1);
	}
	return (1);
}
