#include "get_next_line.h"

#define BUFFER_SIZE 42

static char	*map_and_free(char *res, char *for_free)
{
	free(for_free);
	return (res);
}

static char	*read_fd(int fd, char *store)
{
	char	*res;
	char	tmp[BUFFER_SIZE + 1];
	int		read_res;

	if (store)
	{
		res = ft_strjoin(res, store);
		if (!res)
			return (NULL);
	}
	read_res = read(fd, res, BUFFER_SIZE);
	while (!ft_strchr(tmp, '\n') && read_res > 0)
	{
		read_res = read(fd, tmp, BUFFER_SIZE);
		if (read_res == -1)
			break ;
		tmp[read_res] = '\0';
		res = map_and_free(ft_strjoin(res, tmp), res);
		if (!res)
			return (NULL);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	char		*read_str;
	char		*line;
	static char	*store;

	read_str = read_fd(fd, store);
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
	return (line);
}
