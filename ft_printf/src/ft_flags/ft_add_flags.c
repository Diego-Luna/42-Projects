/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:32:45 by diegofranci       #+#    #+#             */
/*   Updated: 2022/05/14 20:21:23 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_add_flags(t_printf *ob_print, char c)
{
	size_t	i;

	i = ft_strlen(ob_print->flags);
	ob_print->flags[i] = c;
	ob_print->flags[i + 1] = '\0';
}
