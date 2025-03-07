#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void filter(const char *input, const char *pattern)
{
	size_t pat_len = strlen(pattern);
	while (*input)
	{
		if (strncmp(input, pattern, pat_len) == 0)
		{
			write(1, "****", pat_len);
			input += pat_len;
		}
		else
		{
			write(1, input, 1);
			input++;
		}
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	char *input = NULL;
	size_t total = 0, bytes_read;
	char tmp_buf[BUFFER_SIZE];

	while ((bytes_read = read(0, tmp_buf, BUFFER_SIZE)) > 0)
	{
		char *new_buf = realloc(input, total + bytes_read + 1);
		if (!new_buf)
		{
			free(input);
			return 1;
		}
		input = new_buf;
		memcpy(input + total, tmp_buf, bytes_read);
		total += bytes_read;
	}
	if (!input)
		return 1;
	input[total] = '\0';
	filter(input, argv[1]);
	free(input);
	return 0;
}



