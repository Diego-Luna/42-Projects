#include <stdio.h>
#include "./src/push_swap.h"

// int ft_leng_of_numbers(char *argv)
// {
//   int i;
//   int leng;

//   i = 0;
//   leng = 0;
//   while (argv[i] && (ft_is_number(argv[i]) == 1 || ft_is_negative_number(argv[i]) == 1))
//   {
//     leng += ft_strlen(argv[i]);
//     i++;
//   }
//   return (leng);
// }

// int ft_number_of_numbers(char *argv)
// {
//   int i;

//   i = 0;
//   while (argv[i] && (ft_is_number(argv[i]) == 1 || ft_is_negative_number(argv[i]) == 1))
//   {
//     i++;
//   }
//   return (i);
// }


// void ft_data_organizer(char *argv, char *buf)
// {
//   int i;
//   int ii;

//   i = 0;
//   ii = 0;
//   while (argv[i])
//   {
//     buf[ii] = ' ';
//     buf[ii] = ' ';
//     i++;
//   }
  
// }

// int ft_order_information(int argc, char *argv)
// {
//   // int leng_numbers;
//   char *buf;

//   // leng_numbers = ft_leng_of_numbers(argv);
//   buf = malloc(sizeof *buf * (ft_leng_of_numbers(argv) + ft_number_of_numbers(argv) + 1));
//   // ft_data_organizer(argv, buf);
// }

int main(int argc, char **argv)
{
  printf("\n -> argc:{%i}, argv:{%s}, ft_verification:{%i}", argc, argv[argc - 1], ft_verification(argc, argv));
  if (ft_verification(argc, argv))
  {
  }
  return (0);
}
