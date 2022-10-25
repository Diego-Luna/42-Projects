/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 10:30:18 by diegofranci       #+#    #+#             */
/*   Updated: 2022/10/20 16:02:57 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	int			leng;
	t_printf	ob_print;

	leng = 1;
	(void)leng;
	va_start(arg, str);
	ft_strtostr(ob_print.str, str);
	if (ft_check_params(arg, &ob_print) < 0)
		return (-1);
	return (10);
}
