/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:36:52 by diegofranci       #+#    #+#             */
/*   Updated: 2022/05/15 20:57:21 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_str_flags(const char *s, int i, t_printf *ob_print)
{
	int	num;
	int	start;
	int	end;

	i++;
	start = i;
	num = ft_strfin_end(s, '%', i);
	ft_add_flags(ob_print, (num + 48));
	ft_add_flags(ob_print, '(');
	while (!ft_check(s[i]))
	{
		ft_add_flags(ob_print, s[i]);
		i++;
	}
	end = i;
	ft_add_flags(ob_print, ')');
	ft_strtostr(ob_print->strold, ob_print->str);
	ft_strtostrnn(ob_print->str, ob_print->strold, start, end);
}
