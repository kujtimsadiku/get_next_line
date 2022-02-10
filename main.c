#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <time.h>

/*
**	Main was not made by me. All the credit goes to altikka
*/

int	main(void)
{
	char		*line;
	int			fd;
	int			res;

	clock_t		start;
	clock_t		end;
	double		time;

	fd = open("bible.txt", O_RDONLY);
	start = clock();
	while (1)
	{
		res = get_next_line(fd, &line);
		printf("%d, %s\n", res, line);
		free(line);
		if (res <= 0)
			break ;
	}
	end = clock();
	time = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime: %f\n", time);

	//uncomment this if you want to test from stdin
	//printf("-------\nTesting stdin:\n");
	//while (1)
	//{
	//	get_next_line(1, &line);
	//	printf("%s\n", line);
	//}
	close(fd);
	return (0);
}
