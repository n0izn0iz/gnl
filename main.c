#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		ret;

	if (argc == 1)
		fd = 0;
	else
		fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		perror(NULL);
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		printf("%d|||%s|||\n", ret, line);
		if (line)
		{
			free(line);
			line = NULL;
		}
	}
	if (line)
	{
		printf("%d|||%s|||\n", ret, line);
		free(line);
	}
	if (ret < 0)
		printf("ERROR\n");
	else if (ret == 0)
		printf("No more lines\n");
	return (0);
}