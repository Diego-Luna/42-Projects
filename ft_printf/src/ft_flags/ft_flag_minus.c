#include "../ft_printf.h"

void	ft_chec(t_printf *ob_print, char *flags, char *str )
{
	int		leng_flag;

	leng_flag = ft_strlen(flags);
	if (leng_flag > 1 && ft_strlen(str) == 0 && ft_atoi(flags + 1) != 0)
	{
		ob_print->more_return = ft_atoi(flags + 1);
	}
}

void ft_flag_minus(t_printf *ob_print, char *flags, char *str)
{
	int		leng_flag;
	int		leng_str;
	int		max;

	leng_flag = ft_strlen(flags);
	leng_str = ft_strlen(str);
	max = 0;
	ft_strtostr(str, str);
	if (leng_flag >= 2 && ft_strlen(str) > 0)
	{
		max = ft_atoi(flags + 1);
		if (max > leng_str)
		{
			while (leng_str < max)
			{
				str[leng_str] = ' ';
				leng_str++;
			}
			str[leng_str] = '\0';
		}
	}
	ft_chec(ob_print, flags, str);
	printf("\n > data leng_str:{%d}, leng_flag{%d}, max:{%d}, ob_print->more_return:{%i}", \
		leng_str, leng_flag, max, ob_print->more_return);
	ft_strtostr(ob_print->strold, str);
	ft_strtostrn(str, ob_print->strold, 0);
}
