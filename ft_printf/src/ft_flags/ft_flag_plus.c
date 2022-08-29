/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:47:49 by diegofranci       #+#    #+#             */
/*   Updated: 2022/05/10 14:48:09 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_flag_plus(t_printf *ob_print, char *str)
{
	int	number;

	if (str[0] != '+')
	{
		number = ft_atoi(str);
		ft_strtostr(ob_print->strold, str);
		if (number < 0)
		{
			ft_strtostrn(str, ob_print->strold, 0);
		}
		else
		{
			ft_strtostr(str, "+");
			ft_strtostrn(str, ob_print->strold, 1);
		}
	}
}
