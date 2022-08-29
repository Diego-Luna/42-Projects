/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_space.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:46:45 by diegofranci       #+#    #+#             */
/*   Updated: 2022/05/10 14:47:06 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_flag_space(t_printf *ob_print, char *str)
{
	ft_strtostr(ob_print->strold, str);
	ft_strtostr(str, " ");
	ft_strtostrn(str, ob_print->strold, 1);
}
