/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:00:40 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/07 21:00:40 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*map_and_free(char *res, char *for_free)
{
	if (for_free)
		free(for_free);
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	total_size;
	char	*res;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	total_size = ft_strclen(s1, '\0') + ft_strclen(s2, '\0');
	res = (char *)malloc(sizeof(char) * (total_size + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (s1[++i])
		res[i] = s1[i];
	j = 0;
	while (s2[j])
		res [i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

ssize_t	ft_strclen(const char *s, char c)
{
	ssize_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!s[i] && c)
		return (-1);
	return (i);
}

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	len;
	char	*res;

	len = 0;
	while (str[len])
		len++;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (str[i])
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	ssize_t	i;
	size_t	s_len;
	char	*res;

	if (!s)
		return (NULL);
	if (!len)
		return (ft_strdup(""));
	s_len = 0;
	while (s[s_len])
		s_len++;
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = -1;
	while (++i < (ssize_t)len)
		res[i] = s[start + i];
	res[i] = '\0';
	return (res);
}
