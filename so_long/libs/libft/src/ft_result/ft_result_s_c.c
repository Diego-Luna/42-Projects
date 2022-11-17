/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_s_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:38:17 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/08 10:53:10 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_result_s(char *arg)
{
	if (!arg)
	{
		ft_putstr_fd("(null)", 1);
		return (ft_strlen("(null)") - 1);
	}
	else
	{
		ft_putstr_fd(arg, 1);
		return (ft_strlen(arg) - 1);
	}
}

int	ft_result_c(int arg)
{
	write(1, &arg, 1);
	return (0);
}
