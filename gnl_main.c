#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	*line;
	int		fd;
	if(ac == 10)
		printf("hi");

	fd = open(av[1],O_RDONLY);
	//line = (char*)calloc(10,sizeof(char));
	// printf("rv %zd\n",read(fd, line, 4));
	// printf("%s \n",line);
	// free(line);
	// line = (char*)calloc(10,sizeof(char));
	// printf("rv %zd\n",read(fd, line, 4));
	// printf("%s \n",line);
	// free(line);
	// line = (char*)calloc(10,sizeof(char));
	// printf("rv %zd\n",read(fd, line, 4));
	// printf("%s \n",line);
	printf("start\n");

	while(get_next_line(fd, &line) == 1)
		printf("line back %s\n", line);

	printf("line back %s\n", line);
    
	//rintf("main line is %s\n",*line);

	// get_next_line(fd, &line);
	// get_next_line(fd, &line);
	// while (get_next_line(fd, &line) == 1)
	// {
	// 	printf("%s\n", line);
	// 	free(line);
	// }
	return (0);
}