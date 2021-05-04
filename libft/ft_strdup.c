#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (0);
	else
	{
		while (*src != '\0')
			dest[i++] = *src++;
		dest[i] = '\0';
	}
	return (dest);
}
