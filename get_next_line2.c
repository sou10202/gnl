#include "get_next_line.h"

char    *get_line(int fd, char *leftover)
{
    ssize_t bytes_read;
    char    *buffer;
    char    *unite;
    char    *tmp;

    unite = leftover;
    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (buffer == NULL)
        return (NULL);
    bytes_read = 1;
    while (!ft_strchr(unite, '\n'))
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        buffer[bytes_read] = '\0';
        if (bytes_read <= 0)
        {
            free(buffer);
            return (unite);
        }
        tmp = ft_strjoin(unite, buffer);
        free(unite);
        unite = tmp;
    }
    free(buffer);
    return (unite);
}

int div_by_n(char *unite)
{
    int n;

    n = 0;
    while (unite[n] != '\n' && unite[n] != '\0')
        n++;
    return (n);
}

char    *make_line(char *unite)
{
    char    *line;
    int     len;
    int     n;
    int     i;

    len = ft_strlen(unite);
    n = div_by_n(unite);
    i = 0;
    line = (char *)malloc((n + 2) * sizeof(char));
    if (line == NULL)
        return (NULL);
    while (i < n + 1)
    {
        line[i] = unite[i];
        i++;
    }
    line[i] = '\0';
    return (line);
}

char    *make_leftover(int n, int len, char *unite)
{
    char    *leftover;
    int     i;

    leftover = (char *)malloc((len-n)* sizeof(char));
    if (leftover == NULL)
        return (NULL);
    i = 0;
    while (i < len - n - 1)
    {
        leftover[i] = unite[n + 1 + i];
        i++;
    }
    leftover[i] = '\0';
    return (leftover);
}

char    *get_next_line(int fd)
{
    char    *line;
    static char *leftover;
    char    *unite;
    int     n;
    int     len;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    unite = get_line(fd, leftover);
    if (unite == NULL)
        return (NULL);
    len = ft_strlen(unite);
    n = div_by_n(unite);
    line = make_line(unite);
    if (n == len)
    {
        leftover = (char *)malloc(1);
        leftover = NULL;
        free(unite);
        return (line);
    }
    leftover = make_leftover(n, len, unite);
    free(unite);
    return (line);
}

#include <fcntl.h>
int main(int argc, char **argv)
{
    if (argc != 2)
        return (0);
    int fd;
    char    *line;
    fd = open(argv[1], O_RDONLY);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        printf("%s", line);
        free(line);
    }
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);    
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    // line = get_next_line(fd);
    // printf("line:%s", line);
    // free(line);
    close(fd);
    return (0);
}
