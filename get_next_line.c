#include "get_next_line.h"

#define BUFFER_SIZE 3

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

	res = NULL;
	if (store)
	{
		res = ft_strjoin(res, store);
		if (!res)
			return (NULL);
	}
	read_res = 1;
	while (1)
	{
		if (ft_strchr(res, '\n') || read_res <= 0)
			break ;
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

// char	*get_next_line(int fd)
// {
// 	char		*read_str;
// 	char		*line;
// 	static char	*store;

// 	read_str = read_fd(fd, store);
// 	if (!read_str)
// 		return (NULL);
// 	line = make_line(read_str);
// 	if (!line)
// 	{
// 		free(read_str);
// 		return (NULL);
// 	}
// 	store = make_store(read_str);
// 	free(read_str);
// 	if (!store)
// 	{
// 		free(line);
// 		return (NULL);
// 	}
// 	return (line);
// }

// int	main(void)
// {
// 	int		fd;
// 	char	*res;
// 	// char	*store = ft_strdup("yes!!\n");
// 	char	*store = NULL;

// 	fd = open("test.txt", O_RDONLY);
// 	res = read_fd(fd, store);
// 	printf("res: %s\n", res);
// 	free(res);
// 	// free(store);
// 	close(fd);
// 	return (0);
// }