/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:37:03 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/08 10:53:38 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_number_repit(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	ft_base_check(char *base)
{
	int	i;

	i = 0;
	if (base[0] == '\0')
	{
		return (1);
	}
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
		{
			return (1);
		}
		i++;
	}
	if (i == 1)
	{
		return (1);
	}
	if (ft_number_repit(base))
	{
		return (1);
	}
	return (0);
}

static void	ft_write(unsigned long n, char *base)
{
	write(1, &base[n], 1);
}

static void	ft_putnbr(unsigned long nb, char *base, unsigned long length,
		int *l_str)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(-nb, base, length, l_str);
	}
	else
	{
		if (nb >= (length + 1))
		{
			ft_putnbr(nb / length, base, length, l_str);
		}
		if (nb == ft_strlen(base))
		{
			ft_write(1, base);
			ft_write(0, base);
			*l_str += 1;
		}
		else
			ft_write(nb % length, base);
	}
	*l_str += 1;
}

int	ft_putnbr_base(unsigned long nbr, char *base)
{
	unsigned long		i;
	int					leng;

	leng = 0;
	if (ft_base_check(base))
		return (0);
	i = 0;
	while (base[i] != '\0')
		i++;
	ft_putnbr(nbr, base, (i), &leng);
	return (leng);
}
