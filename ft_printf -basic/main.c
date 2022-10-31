/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 14:48:41 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/10/31 14:50:23 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <stdio.h>

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	main(void)
{
	// int pointer = 1234567890;
	// int ii = ft_printf("\nf : c{%c} s{%s} p{%p} d{%d} i{%i} u{%u} x{%x} X{%X} {%%}", 'd', "diego", &pointer, 42, 42, -42, 42, 42 );
	// int	i = printf("\np : c{%c} s{%s} p{%p} d{%d} i{%i} u{%u} x{%x} X{%X} {%%}", 'd', "diego", &pointer, 42, 42, -42, 42, 42 );
	int ii = ft_printf("\nf :x{%x}1, x{%x}2", 16, 32);
	int	i = printf("\np :x{%x}1, x{%x}2", 16, 32);

	printf("\nValor de p :{%i}", i);
	printf("\nValor de f :{%i}", ii);
	return (0);
}