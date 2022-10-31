/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_s_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:38:17 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/10/31 13:07:24 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../ft_printf.h"

int	ft_result_s(char *arg)
{
	ft_putstr_fd(arg, 1);
	return (ft_strlen(arg) - 1);
}

int	ft_result_c(int arg)
{
	write(1, &arg, 1);

	return (0);
}
