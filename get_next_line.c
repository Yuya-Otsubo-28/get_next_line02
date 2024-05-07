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

// #define BUFFER_SIZE 1

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
	if (store && !store[0])
	{
		free(store);
		store = NULL;
	}
	if (store)
	{
		res = ft_strjoin(res, store);
		free(store);
		store = NULL;
		if (!res)
			return (NULL);
	}
	read_res = 1;
	while (1)
	{
		if (ft_strchr(res, '\n'))
			break ;
		read_res = read(fd, tmp, BUFFER_SIZE);
		if (!read_res)
			break ;
		if (read_res < 0)
		{
			if (res)
				free(res);
			if (store)
				free(store);
			return (NULL);
		}
		tmp[read_res] = '\0';
		res = map_and_free(ft_strjoin(res, tmp), res);
		if (!res)
			return (NULL);
	}
	return (res);
}

static	char *make_line(char *read_str)
{
	size_t	len;
	char	*line;

	len = ft_strclen(read_str, '\n');
	if (ft_strchr(read_str, '\n'))
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

	endl = ft_strchr(read_str, '\n');
	if (!endl)
		return (ft_strdup(""));
	endl++;
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