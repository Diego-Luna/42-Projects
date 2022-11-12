/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:37:43 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/08 10:52:11 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_printf(const char *str, ...)
{
	int		lenght;
	va_list	arg;

	va_start(arg, str);
	lenght = ft_print_and_length(arg, (char *)str);
	va_end(arg);
	return (lenght);
}
