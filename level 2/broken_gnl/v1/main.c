#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Include the get_next_line function
char *get_next_line(int fd);

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2) {
        printf("Usage: %s <file_path>\n", argv[0]);
        return 1;
    }

    // Open the file specified in the command line arguments
    fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    // Read and print lines using get_next_line
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }

    // Close the file descriptor
    close(fd);
    return 0;
}

