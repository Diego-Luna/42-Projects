/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:03:25 by diegofranci       #+#    #+#             */
/*   Updated: 2022/10/20 15:57:20 by dluna-lo         ###   ########.fr       */
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
		i++;
	}
	return (num);
}

//int	ft_check_params(va_list arg, t_printf *ob_print, const char *str)
int	ft_check_params(va_list arg, t_printf *ob_print)
{
	int	num;

	// ob_print->more_return = 0;
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
