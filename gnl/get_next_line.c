#include "get_next_line.h"

char	*str_trim(char *s)
{
	char	*buff;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	buff = malloc(sizeof(char) * (i + 1));
	if (!buff)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		buff[i] = s[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

char	*get_remainder(char *s)
{
	char	*buff;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	buff = malloc(sizeof(char) * (ft_strlen(s) - i));
	if (!buff)
		return (NULL);
	i++;
	j = 0;
	while (s[i])
		buff[j++] = s[i++];
	buff[j] = '\0';
	free(s);
	return (buff);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	char		*buff;
	int			ret;

	ret = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !buff)
		return (-1);
	while (!ft_strchr(str, '\n') && ret != 0)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buff);
			return (-1);
		}
		buff[ret] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	*line = str_trim(str);
	str = get_remainder(str);
	if (ret == 0)
		return (0);
	return (1);
}
