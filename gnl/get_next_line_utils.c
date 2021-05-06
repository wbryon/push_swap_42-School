#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (dstsize == 0)
		return (ft_strlen(src));
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((void *)s);
		s++;
	}
	if (*s == (char)c)
		return ((void *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buff;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 && !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	buff = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (buff != NULL)
	{
		ft_strlcpy(buff, s1, len_s1 + 1);
		ft_strlcpy(buff + len_s1, s2, len_s2 + 1);
		buff[len_s1 + len_s2] = '\0';
		free((char *)s1);
		return (buff);
	}
	return (NULL);
}