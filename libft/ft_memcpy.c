#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*p_dst;
	unsigned char	*p_src;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	if (!n || p_dst == p_src)
		return (dst);
	while (n--)
		*(p_dst++) = *(p_src++);
	return (dst);
}
