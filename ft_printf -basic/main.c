/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 13:06:55 by diegofranci       #+#    #+#             */
/*   Updated: 2022/10/28 17:09:27 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <stdio.h>

#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int	main(void)
{
	int pointer = 1234567890;
	int ii = ft_printf("\nf : c{%c} s{%s} p{%p} d{%d} i{%i} u{%u} x{%x} X{%X} {%%}", 'd', "diego", &pointer, 42, 42, -42, 42, 42 );
	int	i = printf("\np : c{%c} s{%s} p{%p} d{%d} i{%i} u{%u} x{%x} X{%X} {%%}", 'd', "diego", &pointer, 42, 42, -42, 42, 42 );

	printf("\nValor de p :{%i}", i);
	printf("\nValor de f :{%i}", ii);
	return (0);
}

	// int i = printf("\n12");
	// int ii = ft_printf("\n12");
	// ft_printf("1:%c\n", '0');

	// printf("01) print PRINTF : |%c|\n", 'a');
	// ft_printf("01) ft_ PRINTF  : |%c|\n", 'a'); -> ready
	// printf("02) print PRINTF : |%-c|\n", 'z');
	// ft_printf("02) ft_ PRINTF  : |%-c|\n", 'z'); -> ready
	// printf("03) print PRINTF : |%-----c|\n", '!');
	// ft_printf("03) ft_ PRINTF  : |%-----c|\n", '!'); -> ready
	// printf("04) print PRINTF : |%5c|\n", 'R');
	// ft_printf("04) ft_ PRINTF  : |%5c|\n", 'R');
	// printf("05) print PRINTF : |%-5c|\n", 'R');
	// ft_printf("05) ft_ PRINTF  : |%-5c|\n", 'R');
	// printf("06) print PRINTF : |%1c|\n", '3');
	// ft_printf("06) ft_ PRINTF  : |%1c|\n", '3');
	// printf("07) print PRINTF : |%c|\n", '\0');
	// ft_printf("07) ft_ PRINTF  : |%c|\n", '\0');
	// printf("08) print PRINTF : |%5c|\n", '\0');
	// ft_printf("08) ft_ PRINTF  : |%5c|\n", '\0');
	// printf("09) print PRINTF : |%-5c|\n", '\0');
	// ft_printf("09) ft_ PRINTF  : |%-5c|\n", '\0');
	// printf("10) print PRINTF : |%1c|\n", '\0');
	// ft_printf("10} ft_ PRINTF  : |%1c|\n", '\0');
	// ft_printf("--------------------%%s--------------------\n");			//Perfect