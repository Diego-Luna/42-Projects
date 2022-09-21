#include <stdio.h>
#include "./src/push_swap.h"

int main(int argc, char **argv)
{
  printf("\n -> argc:{%i}, argv:{%s}, ft_verification:{%i}", argc, argv[argc - 1], ft_verification(argc, argv));
  return (0);
}
