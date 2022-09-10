/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_cat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacamilalunalopez <anacamilalunalopez@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:03:10 by diegofranci       #+#    #+#             */
/*   Updated: 2022/09/09 18:09:31 by anacamilalu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_flag_cat(t_printf *ob_print, char *str)
{
	if (str[0] != '0' && str[1] != '\n')
	{
		ft_strtostr(ob_print->strold, str);
		if (ob_print->is_x == 'X')
		{
			ft_strtostr(str, "0X");
		}
		else
		{
			ft_strtostr(str, "0x");
		}
		ft_strtostrn(str, ob_print->strold, 2);
	}
}
