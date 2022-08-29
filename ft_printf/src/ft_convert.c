/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacamilalunalopez <anacamilalunalopez@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:37:50 by diegofranci       #+#    #+#             */
/*   Updated: 2022/08/24 13:41:15 by anacamilalu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_update_result(t_printf *ob_print, char *str, int counter)
{
	ob_print->i_result = ft_strfind(ob_print->result, ob_print->i_result, '%',
			ob_print->convers[counter]);
	if (ob_print->str_end == 0 || ob_print->str_end == 1)
	{
		ft_strtostrn(ob_print->result, str, ob_print->i_result);
		ob_print->i_str = ft_strfind(ob_print->str, ob_print->i_str, '%',
				ob_print->convers[counter]);
		if (ob_print->str_end == 0)
		{
			ob_print->i_result += 1;
			ob_print->i_str += 2;
			ft_strtostrnn(ob_print->result, ob_print->str,
				ft_strlen(ob_print->result), ob_print->i_str);
		}
	}
	if (ob_print->str_end == 1)
	{
		ob_print->str_end = 2;
	}
}
// version original
// void	ft_update_result(t_printf *ob_print, char *str, int counter)
// {
// 	int	i;
// 	int	i_old;
// 	int	ii;

// 	i = 0;
// 	i_old = 0;
// 	ii = 1;
// 	i = ft_strfind(ob_print->result, i, '%', ob_print->convers[counter]);
// 	ft_strtostrn(ob_print->result, str, i);
// 	if (ob_print->str_end == 0)
// 	{
// 		i = ft_strfind(ob_print->str, 0, '%', ob_print->convers[counter]);
// 		i_old = i;
// 		while (i <= ob_print->position)
// 		{
// 			i = ft_strfind(ob_print->str, i_old + ii,
// 				'%', ob_print->convers[counter]);
// 			ii++;
// 		}
// 		ob_print->position = i;
// 		ft_strtostrnn(ob_print->result, ob_print->str,
// 			ft_strlen(ob_print->result), i + 2);
// 	}
// }

int	ft_convert(va_list arg, t_printf *ob_print)
{
	int	i;

	i = 0;
	while (ob_print->convers[i])
	{
		if (ob_print->convers[i] == 's')
			ft_result_s(va_arg(arg, char *), ob_print, i);
		if (ob_print->convers[i] == 'c')
			ft_result_c(va_arg(arg, int), ob_print, i);
		if (ob_print->convers[i] == 'd' || ob_print->convers[i] == 'i')
			ft_result_di(va_arg(arg, int), ob_print, i);
		if (ob_print->convers[i] == 'u')
			ft_result_u(va_arg(arg, unsigned int), ob_print, i);
		if (ob_print->convers[i] == 'x')
			ft_result_x(va_arg(arg, int), ob_print, "0123456789abcdef", i);
		if (ob_print->convers[i] == 'X')
			ft_result_x(va_arg(arg, int), ob_print, "0123456789ABCDEF", i);
		if (ob_print->convers[i] == '%')
			ft_result_sign(ob_print, i);
		if (ob_print->convers[i] == 'p')
			ft_result_p((unsigned long)va_arg(arg, void *), ob_print, i);
		i++;
	}
	return (1);
}
