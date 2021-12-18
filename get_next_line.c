#include "get_next_line.h"

int	nl_find(char *save)
{
	char	*ori;

	ori = save;
	while (*save)
	{
		if (*save == '\n')
			return (save - ori);
		save++;
	}
	return (-1);
}

int	nl_split(char **save, char **line, int nl_pos)
{
	char	*tmp;

	(*save)[nl_pos] = '\0';
	*line = ft_strdup(*save);
	tmp = ft_strdup(*save + nl_pos + 1);
	free(*save);
	*save = tmp;
	return (1);
}

int	no_more_read(char **save, char **line)
{
	int	nl_pos;

	if (*save)
		nl_pos = nl_find(*save);
	if (*save && nl_pos >= 0)
		return (nl_split(save, line, nl_pos));
	else if (*save)
	{
		*line = *save;
		*save = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

char	*nullterm_and_join(char *buf, char *save, size_t read_ret)
{
	buf[read_ret] = '\0';
	save = ft_strjoin(save, buf);
	return (save);
}

int	get_next_line(int fd, char **line)
{
	static char	*save[257];
	char		*buf;
	ssize_t		read_ret;

	if ((fd < 0) || (fd > 256) || !line || (BUFFER_SIZE <= 0))
		return (-1);
	buf = (char *)malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	read_ret = read(fd, buf, BUFFER_SIZE);
	while (read_ret > 0)
	{
		save[fd] = nullterm_and_join(buf, save[fd], read_ret);
		if (nl_find(save[fd]) >= 0)
		{
			buf_cleaner(buf);
			return (nl_split(&save[fd], line, nl_find(save[fd])));
		}
		read_ret = read(fd, buf, BUFFER_SIZE);
	}
	buf_cleaner(buf);
	if (read_ret < 0)
		return (-1);
	return (no_more_read(&save[fd], line));
}
