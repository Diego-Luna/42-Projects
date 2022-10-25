/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_di_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:06:25 by diegofranci       #+#    #+#             */
/*   Updated: 2022/05/10 14:40:12 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_result_di(int arg, t_printf *ob_print, int counter)
{
	char	str[12];

	str[0] = '\0';
	ft_inttostr(arg, str);
	ft_flags(ob_print, str, counter);
	ft_update_result(ob_print, str, counter);
}

void	ft_result_u(unsigned int arg, t_printf *ob_print, int counter)
{
	char	str[12];

	str[0] = '\0';
	ft_inttostrn(arg, str);
	ft_flags(ob_print, str, counter);
	ft_update_result(ob_print, str, counter);
}
