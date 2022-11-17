/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_result_di_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:38:25 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/08 12:50:16 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_num_of_char(unsigned int n)
{
	unsigned int	i;
	unsigned int	num;

	i = 1;
	num = n;
	if (n < 0)
	{
		i = 2;
		num = -n;
	}
	while (num > 9)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa_unsigned(unsigned int n)
{
	unsigned int	i;
	unsigned int	num;
	char			*buffer;

	buffer = (char *)malloc(ft_num_of_char(n) + 1);
	if (buffer == NULL)
		return (0);
	i = ft_num_of_char(n);
	num = n;
	if (n < 0)
	{
		num = -n;
		buffer[0] = '-';
	}
	buffer[i] = 0;
	buffer[i - 1] = '0';
	while (num > 0)
	{
		i--;
		buffer[i] = num % 10 + 48;
		num /= 10;
	}
	return (buffer);
}

int	ft_result_di(int arg)
{
	char	*str;
	size_t	leng;

	str = ft_itoa(arg);
	leng = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (leng - 1);
}

int	ft_result_u(unsigned int arg)
{
	char	*str;
	size_t	leng;

	str = ft_itoa_unsigned(arg);
	leng = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (leng - 1);
}
