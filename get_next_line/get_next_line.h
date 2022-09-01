#ifndef GET_NEXT_LINE_H
# define FT_PRINTF_H

// Test
# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// configuracion de
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# if BUFFER_SIZE > 9223372036854775806
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
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