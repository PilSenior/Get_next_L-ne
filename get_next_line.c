#include "get_next_line.h"
#include <stdio.h>
static char	*line_after_new_line(char *s, char c)
{
	char	*str;
	int		i;
	int		j;
	i = 0;
	j = 0;

	while (s[i] && s[i] != c)
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen(s) - i) + 1);
	if (!str)
		return (NULL);
	i++;
	while (s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	free(s);
	return (str);
}

static char	*line_before_new_line(char *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	if (s[i] == c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*find_next_line(int fd, char *s)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (NULL);
	i = 1;
	while (!ft_strchr(s, '\n') && i != 0)
	{
		i = read(fd, str, BUFFER_SIZE);
		if (i == -1)
		{
			free(str);
			return (NULL);
		}
		str[i] = '\0';
		s = ft_strjoin(s, str);
	}
	free(str);
	return (s);
}

char	*get_find_next_line(int fd)
{
	char		*str;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = find_next_line(fd, line);
	if (line)
	{
		str = line_before_new_line(line, '\n');
		line = line_after_new_line(line, '\n');
		return (str);
	}
	return (NULL);
}
#include <fcntl.h>
#include <stdio.h>

int main()
{
    int fd = open("asd.text", O_RDONLY);
    char *line;

    if (fd < 0)
        return (1); // Dosya açılamadıysa çıkış yapıyoruz.

    while ((line = get_find_next_line(fd)) != NULL)
    {
        printf("%s", line); // Satırı yazdırıyoruz.
        free(line);         // Hafızayı serbest bırakıyoruz.
    }

    close(fd);
    return (0);
}