/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:23:59 by diegofranci       #+#    #+#             */
/*   Updated: 2022/10/28 17:13:56 by dluna-lo         ###   ########.fr       */
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

int	ft_check_params(va_list arg, t_printf *ob_print, char *str);

#endif
