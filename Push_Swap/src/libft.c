
#include "./push_swap.h"


int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isdigit(int i)
{
	while ('0' <= i && i <= '9')
		return (1);
	return (0);
}

int	ft_str_equal(char *str_1, char *str_2)
{
	int i;

	i = 0;
	printf("\n{%s}", str_1);
	printf("\n{%s}", str_2);
	if (ft_strlen(str_1) != ft_strlen(str_2))
	{
		return (-1);
	}
	printf("\n -> Paso el if numero 1");
	while (str_1[i] == str_2[i])
	{
		i++;
	}
	printf("\n -> Paso el if numero 2 {%s}{%s}", str_1[i], str_2[i]);
	if (str_1[i] == str_2[i])
	{
		return (1);
	}
	printf("\n -> Paso el if numero 3");
	return (-1);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	neg;
	int	res;

	i = 0;
	neg = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (str[i] - '0') + (res * 10);
		i++;
	}
	return (res * neg);
}