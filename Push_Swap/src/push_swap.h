
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

int	ft_isdigit(int i);
int	ft_atoi(const char *str);
int	ft_strlen(const char *str);
int	ft_str_equal(char *str_1, char *str_2);

// verifcacion
int ft_verification(int argc, char **argv);

int		main(int argc, char **argv);

#endif
