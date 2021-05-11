#include "libft.h"

int	ft_atoi(const char *str)
{
	int			dig;
	int			sign;
	long int	num;

	num = 0;
	sign = 1;
	dig = 0;
	while (*str && (*str == '\f' || *str == '\t' || *str == ' ' || \
				*str == '\n' || *str == '\r' || *str == '\v'))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
	{
		num = num * 10 + (*str - '0');
		dig++;
		if (dig > 10 || (num * sign) > MAXINT || (num * sign) < MININT)
			ft_error();
		str++;
	}
	return ((int)(num * sign));
}
