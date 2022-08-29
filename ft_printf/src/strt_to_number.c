/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strt_to_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacamilalunalopez <anacamilalunalopez@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 18:59:44 by diegofranci       #+#    #+#             */
/*   Updated: 2022/08/24 13:52:27 by anacamilalu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_write(int n, char *str)
{
	int	leng;

	n += 48;
	leng = ft_strlen(str);
	str[leng] = n;
	str[leng + 1] = '\0';
}

void	ft_inttostr(int nb, char *str)
{
	if (nb <= -2147483648)
	{
		ft_inttostr(nb / 10, str);
		ft_write(8, str);
	}
	else if (nb < 0)
	{
		ft_write(-3, str);
		ft_inttostr(-nb, str);
	}
	else
	{
		if (nb > 9)
		{
			ft_inttostr(nb / 10, str);
		}
		ft_write(nb % 10, str);
	}
}

void	ft_inttostrx(int nb, char *str, char *val)
{
	int	leng;
	int	leng_val;

	leng_val = ft_strlen(val) - 1;
	if (nb > leng_val)
	{
		ft_inttostrx(nb / ft_strlen(val), str, val);
	}
	leng = ft_strlen(str);
	str[leng] = val[nb % ft_strlen(val)];
	str[leng + 1] = '\0';
}

void	ft_inttostrn(unsigned int nb, char *str)
{
	if (nb > 9)
	{
		ft_inttostrn(nb / 10, str);
	}
	ft_write(nb % 10, str);
}
