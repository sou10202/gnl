#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE  3
#endif

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
int ft_strlen(const char *str);
char	*ft_strdup(const char *src);

#endif 