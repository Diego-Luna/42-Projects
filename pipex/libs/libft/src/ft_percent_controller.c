/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_controller.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:37:58 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/08 10:52:47 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_percent_controller(va_list arg, char *str)
{
	if (str[1] == 'c')
		return (ft_result_c(va_arg(arg, int)));
	if (str[1] == 's')
		return (ft_result_s(va_arg(arg, char *)));
	if (str[1] == 'p')
		return (ft_result_p(va_arg(arg, unsigned long)));
	if (str[1] == 'd' || str[1] == 'i')
		return (ft_result_di(va_arg(arg, int)));
	if (str[1] == 'u')
		return (ft_result_u(va_arg(arg, unsigned int)));
	if (str[1] == 'x')
		return (ft_result_x(va_arg(arg, int), "0123456789abcdef"));
	if (str[1] == 'X')
		return (ft_result_x(va_arg(arg, int), "0123456789ABCDEF"));
	if (str[1] == '%')
		return (ft_result_sign());
	return (0);
}
