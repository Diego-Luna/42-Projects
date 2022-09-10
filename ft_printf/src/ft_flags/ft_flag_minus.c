#include "../ft_printf.h"

void ft_flag_minus(t_printf *ob_print, char *flags, char *str)
{
	int		leng_flag;
	int		leng_str;
	int		max;

	leng_flag = ft_strlen(flags);
	leng_str = ft_strlen(str);
	max = 0;
	ft_strtostr(str, str);
	if (leng_flag >= 2)
	{
		max = ft_atoi(flags + 1);
		if (max > leng_str)
		{
			// printf("\n start str:{%s}", str);
			while (leng_str < max)
			{
				str[leng_str] = ' ';
				leng_str++;
			}
			str[leng_str] = '\0';
			// printf("\n end str:{%s}", str);
		}
	}
	// printf("\n data leng_str:{%d}, leng_flag{%d}, max:{%d}, str:{%s}", \
	// 	leng_str, leng_flag, max, str);
	ft_strtostr(ob_print->strold, str);
	ft_strtostrn(str, ob_print->strold, 0);
}
