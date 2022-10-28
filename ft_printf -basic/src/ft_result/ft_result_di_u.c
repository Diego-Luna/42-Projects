/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_di_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:06:25 by diegofranci       #+#    #+#             */
/*   Updated: 2022/10/28 17:34:40 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_result_di(int arg, t_printf *ob_print)
{
	(void) arg;
	(void) ob_print;
	// char	str[12];

	// str[0] = '\0';
	// ft_inttostr(arg, str);
	// ft_flags(ob_print, str, counter);
	// ft_update_result(ob_print, str, counter);
}

void	ft_result_u(unsigned int arg, t_printf *ob_print, int counter)
{
	char	str[12];

	str[0] = '\0';
	ft_inttostrn(arg, str);
	ft_flags(ob_print, str, counter);
	ft_update_result(ob_print, str, counter);
}
