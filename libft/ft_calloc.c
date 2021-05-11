#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = (void *)malloc(count * size);
	if (str)
		ft_bzero(str, count * size);
	return (str);
}
