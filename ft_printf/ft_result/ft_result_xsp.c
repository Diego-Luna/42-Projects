/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_xsp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:38:08 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/01 10:12:24 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_result_x(unsigned int arg, char *base)
{
	return (ft_putnbr_base(arg, base) - 1);
}

int	ft_result_sign(void)
{
	ft_putchar_fd('%', 1);
	return (0);
}

int	ft_result_p(unsigned long p)
{
	ft_putstr_fd("0x", 1);
	return (ft_putnbr_base(p, "0123456789abcdef") + 1);
}
