#include <stdio.h>
#include "./src/push_swap.h"


int ft_is_swap(char *str)
{
  printf("\n -> ft_str_equal sa:{%s}{%i}", str, ft_str_equal("sa", str));
  // printf("\n -> ft_str_equal sb:{%s}{%i}", str, ft_str_equal("sb", str));
  // printf("\n -> ft_str_equal ss:{%s}{%i}", str, ft_str_equal("ss", str));
  // printf("\n -> ft_str_equal pa:{%s}{%i}", str, ft_str_equal("pa", str));
  // printf("\n -> ft_str_equal pb:{%s}{%i}", str, ft_str_equal("pb", str));
  // printf("\n -> ft_str_equal ra:{%s}{%i}", str, ft_str_equal("ra", str));
  // printf("\n -> ft_str_equal rb:{%s}{%i}", str, ft_str_equal("rb", str));
  // printf("\n -> ft_str_equal rr:{%s}{%i}", str, ft_str_equal("rr", str));
  // printf("\n -> ft_str_equal rra:{%s}{%i}", str, ft_str_equal("rra", str));
  // printf("\n -> ft_str_equal rrb:{%s}{%i}", str, ft_str_equal("rrb", str));
  // printf("\n -> ft_str_equal rrr:{%s}{%i}", str, ft_str_equal("rrr", str));
  // if (ft_str_equal("sa", str)  == 1 ||  ft_str_equal("sb", str)  == 1 ||  ft_str_equal("ss", str)  == 1 ||  ft_str_equal("pa", str)  == 1 ||  ft_str_equal("pb", str)  == 1 ||  ft_str_equal("ra", str)  == 1 ||  ft_str_equal("rb", str)  == 1 ||  ft_str_equal("rr", str)  == 1 ||  ft_str_equal("rra", str)  == 1 ||  ft_str_equal("rrb", str)  == 1 ||  ft_str_equal("rrr", str)  == 1)
  // {
  //   printf("\n En el es swap");
  //   return (1);
  // }
  // printf("\n No es swap");
  return (-1);
}
int ft_is_number(char *str)
{
  int i;

  i = 0;
  while (str[i])
  {
    if (str[0] != '-' && !(ft_isdigit(str[i])) && i > 0)
    {
      return (-1);
    }
    i++;
  }
  return (1);
}


int ft_verification(int argc, char **argv)
{
  int i;

  i = 1;
  if (argc > 2)
  {
    while (argv[i])
    {
      if (ft_is_number(argv[i]) == -1 )
      {
        if (ft_is_swap(argv[i]) == -1)
        {
          return (-1);
        }
      }
      i++;
    }
  }
  return (1);
}

int main(int argc, char **argv)
{
  printf("\n -> argc:{%i}, argv:{%s}, ft_verification:{%i}", argc, argv[argc - 1], ft_verification(argc, argv));
  return (0);
}
