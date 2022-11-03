/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 15:48:44 by dluna-lo          #+#    #+#             */
/*   Updated: 2022/11/03 16:22:55 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define FT_PRINTF_H

// Header
# include <unistd.h>
# include <stdlib.h>

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