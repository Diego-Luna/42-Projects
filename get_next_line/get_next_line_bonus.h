/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:48:44 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/03 16:23:40 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// Header
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// configuracion de
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

// main
char	*get_next_line(int fd);

// utils
char	*ft_strdup(const char *str_1);
int		ft_contains_newline(const char *str);
void	*ft_malloc_zero(size_t count, size_t size);
char	*ft_join_strs(const char *str_1, const char *str_2);
void	ft_strs_cleans(char **str_1, char **str_2, char **str_3);

#endif