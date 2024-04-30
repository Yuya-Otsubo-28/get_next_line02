#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

char	*get_next_line(int fd);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strchr(const char *s, int c);

size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif