/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anacamilalunalopez <anacamilalunalopez@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 19:36:13 by anacamilalu       #+#    #+#             */
/*   Updated: 2022/09/01 14:25:06 by anacamilalu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define FT_PRINTF_H

// Test
# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// main
char	*get_next_line(int fd);

// utils
char	*ft_strdup(const char *str_1);
int		ft_contains_newline(const char *str);
void	*ft_malloc_zero(size_t count, size_t size);
char	*ft_join_strs(const char *str_1, const char *str_2);
void	ft_strs_cleans(char **str_1, char **str_2, char **str_3);

#endif