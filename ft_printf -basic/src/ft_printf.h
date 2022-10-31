/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 11:37:10 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/10/31 14:44:39 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Test
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
// # include "../../libft/libft.h"

//char	str[1000];
typedef struct s_printf
{
	char	*str;
	int		leng;
}			t_printf;

// main
int			ft_printf(const char *str, ...);

// controller
int			ft_print_and_length(va_list arg, char *str);
int			ft_percent_controller(va_list arg, char *str);

// utils
char		*ft_itoa(int n);
size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);
void		ft_putchar_fd(char c, int fd);
int			ft_putnbr_base(unsigned long nbr, char *base);

// caracteres
int			ft_result_sign(void);
int			ft_result_c(int arg);
int			ft_result_di(int arg);
int			ft_result_s(char *arg);
int			ft_result_p(unsigned long p);
int			ft_result_u(unsigned int arg);
int			ft_result_x(unsigned int arg, char *base);


#endif
