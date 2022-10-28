#include "ft_printf.h"

void	ft_percent_controller(va_list arg, t_printf *ob_print, char *str, int start)
{
	start++;
	if (str[start] == 's')
		ft_result_s(va_arg(arg, char *), ob_print);
	if (str[start] == 'c')
		ft_result_c(va_arg(arg, int), ob_print);
	if (str[start] == 'd' || str[start]  == 'i')
		ft_result_di(va_arg(arg, int), ob_print);
	if (str[start] == 'u')
		ft_result_u(va_arg(arg, unsigned int), ob_print);
	if (str[start] == 'x')
		ft_result_x(va_arg(arg, int), ob_print, "0123456789abcdef");
	if (str[start] == 'X')
		ft_result_x(va_arg(arg, int), ob_print, "0123456789ABCDEF");
	if (str[start] == '%')
		ft_result_sign(ob_print);
	if (str[start] == 'p')
			ft_result_p((unsigned long)va_arg(arg, void *), ob_print);
}