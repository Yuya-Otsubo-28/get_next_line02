#include "get_next_line.h"

#define BUFFER_SIZE 42

char	*get_next_line(int fd)
{
	char		*read_str;
	char		*line;
	static char	*store;

	read_str = read_fd(fd);
	if (!read_str)
		return (NULL);
	line = make_line(read_str);
	if (!line)
	{
		free(read_str);
		return (NULL);
	}
	store = make_store(read_str);
	free(read_str);
	if (!store)
	{
		free(line);
		return (NULL);
	}
	return (res);
}
