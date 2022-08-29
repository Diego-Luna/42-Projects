/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_s_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacamilalunalopez <anacamilalunalopez@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:05:24 by diegofranci       #+#    #+#             */
/*   Updated: 2022/08/24 13:58:11 by anacamilalu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_result_s(char *arg, t_printf *ob_print, int counter)
{
	if (arg == NULL)
	{
		arg = "(null)";
	}
	ft_flags(ob_print, arg, counter);
	ft_update_result(ob_print, arg, counter);
}

void	ft_check_end(t_printf *ob_print)
{
	if (ob_print->str_end == 0)
	{
		ob_print->str_end = 1;
	}
}

void	ft_result_c(int arg, t_printf *ob_print, int counter)
{
	char	str[2];

	if (ob_print->str_end == 0)
	{
		str[1] = '\0';
		if (arg >= 31)
		{
			str[0] = arg;
		}
		else if (arg >= 0)
		{
			str[0] = '\0';
			ft_check_end(ob_print);
		}
		else
		{
			str[0] = '0';
			ft_check_end(ob_print);
		}
		ft_flags(ob_print, str, counter);
		ft_update_result(ob_print, str, counter);
	}
}
