/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuotsubo <yuotsubo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 21:09:12 by yuotsubo          #+#    #+#             */
/*   Updated: 2024/05/07 21:09:12 by yuotsubo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);

char	*ft_strjoin(char const *s1, char const *s2);

char	*map_and_free(char *res, char *for_free);

ssize_t	ft_strclen(const char *s, char c);

char	*ft_strdup(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

#endif