#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		len;
	char	*cpy;
	int		i;

	i = 0;
	len = ft_strlen(s);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	while (s[i])
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	*strjoin_end(char *s1, char *s2, char*cpy)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		cpy[j++] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		cpy[j++] = s2[i];
		i++;
	}
	cpy[j] = '\0';
	free(s1);
	s1 = NULL;
	return (cpy);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	one;
	size_t	two;
	char	*cpy;

	if (!s1 || !s2)
	{
		if (!s1 && !s2)
			return (NULL);
		if (!s1)
			return (ft_strdup(s2));
		if (!s2)
			return (ft_strdup(s1));
	}
	one = ft_strlen(s1);
	two = ft_strlen(s2);
	cpy = (char *)malloc(sizeof(char) * (one + two + 1));
	if (!cpy)
		return (NULL);
	return (strjoin_end(s1, s2, cpy));
}

void	buf_cleaner(char *buf)
{
	if (buf)
	{
		free(buf);
		buf = NULL;
	}
}
