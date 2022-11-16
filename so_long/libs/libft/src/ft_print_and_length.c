/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_and_length.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:37:52 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/08 10:52:24 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_check(char s)
{
	if (s == 'c' || s == 's' || s == 'p' || s == 'd' || s == 'i' || s == 'u'
		|| s == 'x' || s == 'X' || s == '%')
	{
		return (1);
	}
	return (0);
}

int	ft_print_and_length(va_list arg, char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	(void)arg;
	while (str[i])
	{
		if (str[i] == '%' && ft_check(str[i + 1]) == 1)
		{
			num += ft_percent_controller(arg, str + i);
			i++;
		}
		else
			ft_putchar_fd(str[i], 1);
		i++;
		num++;
	}
	return (num);
}
