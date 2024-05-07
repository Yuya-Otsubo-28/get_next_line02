/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:49:41 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/07 16:49:41 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join_store(char *store)
{
	char	*res;

	res = NULL;
	if (store && !store[0])
	{
		store = map_and_free(NULL, store);
		return (NULL);
	}
	if (store)
	{
		res = ft_strjoin(res, store);
		store = map_and_free(NULL, store);
		if (!res)
			return (NULL);
	}
	return (res);
}

static char	*read_fd(int fd, char *store)
{
	char	*res;
	char	tmp[BUFFER_SIZE + 1];
	int		read_res;

	res = join_store(store);
	read_res = 1;
	while (ft_strclen(res, '\n') < 0)
	{
		read_res = read(fd, tmp, BUFFER_SIZE);
		if (!read_res)
			break ;
		if (read_res < 0)
		{
			res = map_and_free(NULL, res);
			store = map_and_free(NULL, store);
			return (NULL);
		}
		tmp[read_res] = '\0';
		res = map_and_free(ft_strjoin(res, tmp), res);
		if (!res)
			return (NULL);
	}
	return (res);
}

static char	*make_line(char *read_str)
{
	ssize_t	len;
	char	*line;

	len = ft_strclen(read_str, '\n');
	if (len < 0)
		len = ft_strclen(read_str, '\0');
	else
		len++;
	line = ft_substr(read_str, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

static char	*make_store(char *read_str)
{
	char	*endl;
	char	*store;
	size_t	len;
	ssize_t	index_n;

	index_n = ft_strclen(read_str, '\n');
	if (index_n < 0)
		return (ft_strdup(""));
	endl = read_str + index_n + 1;
	len = 0;
	while (endl[len])
		len++;
	store = ft_substr(endl, 0, len);
	if (!store)
		return (NULL);
	return (store);
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
		read_str = map_and_free(NULL, read_str);
		return (NULL);
	}
	store = make_store(read_str);
	read_str = map_and_free(NULL, read_str);
	if (!store)
	{
		line = map_and_free(NULL, line);
		return (NULL);
	}
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*res;

// 	fd = open("test.txt", O_RDONLY);
// 	res = get_next_line(fd);
// 	printf("res: %s\n", res);
// 	if (res)
// 		free(res);
// 	res = get_next_line(fd);
// 	printf("res: %s\n", res);
// 	if (res)
// 		free(res);
// 	res = get_next_line(fd);
// 	printf("res: %s\n", res);
// 	if (res)
// 		free(res);
// 	res = get_next_line(fd);
// 	printf("res: %s\n", res);
// 	if (res)
// 		free(res);
// 	close(fd);
// 	return (0);
// }