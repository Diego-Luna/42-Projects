#include "./push_swap.h"

int ft_is_swap(char *str)
{
  if (ft_str_equal("sa", str) == 1 || ft_str_equal("sb", str) == 1 || ft_str_equal("ss", str) == 1 || ft_str_equal("pa", str) == 1 || ft_str_equal("pb", str) == 1 || ft_str_equal("ra", str) == 1 || ft_str_equal("rb", str) == 1 || ft_str_equal("rr", str) == 1 || ft_str_equal("rra", str) == 1 || ft_str_equal("rrb", str) == 1 || ft_str_equal("rrr", str) == 1)
  {
    return (1);
  }
  return (-1);
}

int ft_is_negative_number(char *str)
{
  int i;

  i = 1;
  if (ft_strlen(str) <= 1 || str[0] != '-')
  {
    return (-1);
  }
  while (str[i])
  {
    if (ft_isdigit(str[i]) == -1)
    {
      return (-1);
    }
    i++;
  }
  return (1);
}

int ft_is_number(char *str)
{
  int i;

  i = 0;
  while (str[i])
  {
    if (ft_isdigit(str[i]) == -1)
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
  int is_number;

  i = 1;
  is_number = 1;
  if (argc > 2)
  {
    while (argv[i])
    {
      if (ft_is_number(argv[i]) == -1 && ft_is_negative_number(argv[i]) == -1 && is_number == 1)
      {
        is_number = -1;
      }
      if (ft_is_swap(argv[i]) == -1 && is_number == -1)
      {
        return (-1);
      }
      i++;
    }
  }
  if(ft_is_swap(argv[i -1]) == 1)
    return (1);
  return (-1);
}