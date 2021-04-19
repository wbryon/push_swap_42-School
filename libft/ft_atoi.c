#include "libft.h"

int	sign_checker(const char *str)
{
	int sign;

	sign = 1;
	if (*str == '-')
		sign = -sign;
	return (sign);
}

int	ft_atoi(const char *str)
{
	unsigned long long	res;
	int					sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-' || *str == '+')
	{
		sign = sign_checker(str);
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = (res * 10) + *str - '0';
		str++;
		if (*str < '0' && *str > '9')
			break ;
	}
	if (res >= 9223372036854775807)
		res = (sign == -1) ? 0 : -1;
	return ((int)res * sign);
}

/*#include "libft.h"

int	sign_checker(const char *str)
{
	int	sign;

	sign = 1;
	if (*str == '-')
		sign = -sign;
	return (sign);
}

int	converter(const char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - '0';
		i++;
		if (str[i] < '0' && str[i] > '9')
			return (0);
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	unsigned long long	res;
	int					sign;
	int					i;

	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = sign_checker(str);
		i++;
	}
	res = converter(str);
	if (res >= 9223372036854775807)
	{
		if (sign == -1)
			res = 0;
		else
			res = -1;
	}
	return ((int)res * sign);
}*/
