#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
void	buf_cleaner(char *buf);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif
