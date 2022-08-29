/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 08:52:29 by diegofranci       #+#    #+#             */
/*   Updated: 2022/04/05 09:02:51 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	num_of_char(int n)
{
	int				i;
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

void	ft_putnbr_fd(int n, int fd)
{
	int				i;
	unsigned int	num;
	char			buffer[42];

	i = num_of_char(n);
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
	i = 0;
	while (buffer[i])
		i++;
	write(fd, buffer, i);
}
