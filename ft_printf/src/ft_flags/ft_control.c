/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacamilalunalopez <anacamilalunalopez@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 20:20:29 by diegofranci       #+#    #+#             */
/*   Updated: 2022/09/09 17:34:06 by anacamilalu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_control(t_printf *ob_print, char *flags, char *str)
{
	int	i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == '-')
		{
			ft_flag_minus(ob_print, flags, str);
		}
		if ((flags[i] == '0' || flags[i] == '.') && ft_isdigit(flags[i + 1]))
			ft_flag_number(ob_print, flags, str);
		if (flags[i] == ' ' && flags[i - 1] != ' ')
			ft_flag_space(ob_print, str);
		if (flags[i] == '+')
		{
			ft_flag_plus(ob_print, str);
		}
		if (flags[i] == '#')
		{
			ft_flag_cat(ob_print, str);
		}
		i++;
	}
}
