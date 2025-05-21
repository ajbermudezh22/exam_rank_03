#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char *ft_strjoin(char *s1, char *s2, int len)
{
    int i = 0, j = 0;
    char *new_str;
    while (s1 && s1[i]) i++;
    new_str = malloc(i + len + 1);
    if (!new_str) return NULL;
    for (int k = 0; k < i; k++) new_str[k] = s1[k];
    while (j < len) new_str[i++] = s2[j++];
    new_str[i] = '\0';
    free(s1);
    return new_str;
}

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE];
    static int buf_size = 0, buf_pos = 0;
    char *line = NULL;
    int i = 0;

    if (fd < 0 || BUFFER_SIZE <= 0) return NULL;
    while (1) {
        if (buf_pos >= buf_size) {
            buf_size = read(fd, buffer, BUFFER_SIZE);
            buf_pos = 0;
            if (buf_size <= 0) return line; // End of file or error
        }
        i = buf_pos; // Reset the starting position for this loop
        while (buf_pos < buf_size) {
            if (buffer[buf_pos] == '\n') {
                line = ft_strjoin(line, buffer + i, buf_pos - i + 1);
                buf_pos++;
                return line;
            }
            buf_pos++;
        }
        line = ft_strjoin(line, buffer + i, buf_pos - i);
    }
}

