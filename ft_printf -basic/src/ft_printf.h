/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:37:10 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/10/31 13:05:56 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Test
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../../libft/libft.h"

//char	str[1000];
typedef struct s_printf
{
	char	*str;
	int	leng;
}	t_printf;

// main
int		ft_printf(const char *str, ...);

// controller
int	ft_print_and_length(va_list arg, char *str);
int	ft_percent_controller(va_list arg, char *str);

// utils
int	ft_putnbr_base(unsigned long nbr, char *base);

// caracteres
int	ft_result_sign();
int	ft_result_c(int arg);
int	ft_result_di(int arg);
int	ft_result_s(char *arg);
int	ft_result_p(unsigned long p);
int	ft_result_u(unsigned int arg);
int	ft_result_x(int arg, char *base);

#endif
