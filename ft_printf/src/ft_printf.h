/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacamilalunalopez <anacamilalunalopez@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:23:59 by diegofranci       #+#    #+#             */
/*   Updated: 2022/08/22 19:54:42 by anacamilalu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Test
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "../libft/libft.h"

//char	str[1000];
typedef struct s_printf
{
	char	str[1000];
	char	strold[1000];
	char	convers[255];
	char	flags[255];
	char	result[1000];
	int		position;
	int		str_end;
	int		i_result;
	int		i_str;
}	t_printf;

// main
int		ft_printf(const char *str, ...);
int		ft_convert(va_list arg, t_printf *ob_print);
int		ft_check_params(va_list arg, t_printf *ob_print);
//int		ft_check_params(va_list arg, t_printf *ob_print, const char *str);

// ft_result_
void	ft_result_sign(t_printf *ob_print, int counter);
void	ft_flags(t_printf *ob_print, char *str, int counter);
void	ft_result_c(int arg, t_printf *ob_print, int counter);
void	ft_result_di(int arg, t_printf *ob_print, int counter);
void	ft_result_s(char	*arg, t_printf *ob_print, int counter);
void	ft_update_result(t_printf *ob_print, char *str, int counter);
void	ft_result_p(unsigned long p, t_printf *ob_print, int counter);
void	ft_result_u(unsigned int arg, t_printf *ob_print, int counter);
void	ft_result_x(int arg, t_printf *ob_print, char *val, \
	int counter);
// void	ft_result_x(unsigned int arg, t_printf *ob_print, char *val,
// 	int counter);

// flags -> ft_check_params
void	ft_add_flags(t_printf *ob_print, char c);
void	ft_str_flags(const char *s, int i, t_printf *ob_print);

// flags
void	ft_flag_cat(t_printf *ob_print, char *str);
void	ft_flag_plus(t_printf *ob_print, char *str);
void	ft_flag_space(t_printf *ob_print, char *str);
void	ft_flag_number(t_printf *ob_print, char *flags, char *str);
void	ft_control(t_printf *ob_print, char *flags, char *str);

// str
int		ft_check(char s);
void	ft_str_invest(char *str);
void	ft_write(int n, char *str);
void	ft_inttostr(int nb, char *str);
int		ft_strfin(const char *str, char c);
void	ft_inttostrn(unsigned int nb, char *str);
void	ft_strtostr(char *str1, const char *str2);
void	ft_fill(char *str, char fill, int number);
void	ft_inttostrx(int nb, char *str, char *val);
// int		ft_strfind(const char *str, int start, char c);
int		ft_strfind(const char *str, int start, char c, char c_2);
int		ft_findc(const char *str, int start, char c);
int		ft_findc_next_same(const char *str, int start, char c);
int		ft_strfin_end(const char *str, char c, int end);
void	ft_strtostrnf(char *str1, const char *str2, int n);
void	ft_strtostrn(char *str1, const char *str2, int start);
void	ft_strtostr_rango(char *str1, char *str2, int start2, int end2);
void	ft_strtostrnn(char *str1, const char *str2, int start1, int start2 );

// test
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	ft_putstr_fd(char *s, int fd);

#endif
