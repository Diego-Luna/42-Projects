/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacamilalunalopez <anacamilalunalopez@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:46:45 by diegofranci       #+#    #+#             */
/*   Updated: 2022/09/03 15:47:28 by anacamilalu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_flag_space(t_printf *ob_print, char *str)
{
	if (ft_is_negative_number(str) != 1)
	{
		ft_strtostr(ob_print->strold, str);
		ft_strtostr(str, " ");
		ft_strtostrn(str, ob_print->strold, 1);
	}
}
