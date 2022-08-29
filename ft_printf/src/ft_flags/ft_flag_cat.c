/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_cat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:03:10 by diegofranci       #+#    #+#             */
/*   Updated: 2022/05/13 10:41:59 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_flag_cat(t_printf *ob_print, char *str)
{
	ft_strtostr(ob_print->strold, str);
	ft_strtostr(str, "0x");
	ft_strtostrn(str, ob_print->strold, 2);
}
