#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#define BUFFER_SIZE 1024

void filter(char *str_in, char *str_arg);
int ft_check(char *str_in, char *str_arg, int i);

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *input_buf = NULL;
		char tmp_buf[BUFFER_SIZE];
		size_t total = 0;
		ssize_t bytes_read;
		while ((bytes_read = read(0, tmp_buf, sizeof(tmp_buf))) > 0)
		{
			char *new_buf = realloc(input_buf, total + bytes_read + 1);
			if (!new_buf)
			{
				fprintf(stderr, "Error\n");
				free(new_buf);
				return 1;
			}
			input_buf = new_buf;
			memcpy(input_buf + total, tmp_buf, bytes_read);
			total += bytes_read;
		}
		if (bytes_read < 0)
		{
			fprintf(stderr, "Error\n");
			free(input_buf);
			return 1;
		}
		input_buf[total] = '\0';
		filter(input_buf, argv[1]);
		free(input_buf);
	}
	return 0;
}
void filter(char *str_in, char *str_arg)
{
	int i = 0;
	int len = strlen(str_arg);
	while (str_in[i])
	{
		len = strlen(str_arg);
		if (str_in[i] == str_arg[0] && ft_check(str_in, str_arg, i) == 1)
		{
			while (len > 0)
			{
				write(1, "*", 1);
				len--;
			}
			i = i + strlen(str_arg);
		}
		else
		{
			write(1, &str_in[i], 1);
			i++;
		}
	}
}
int ft_check(char *str_in, char *str_arg, int i)
{
	int j = 0;
	while (str_in[i] && str_arg[j])
	{
		if (str_in[i] == str_arg[j])
		{
			i++;
			j++;
		}
		else
			break ;
	}
	if (str_arg[j] == '\0')
		return (1);
	return (0);
}
