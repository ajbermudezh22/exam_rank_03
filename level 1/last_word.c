#include <unistd.h>

int main(int ac, char **av)
{
	int i = 0;
	int start;
	int end;

	if (ac == 2)
	{
		while (av[1][i])
			i++;
		while (i >= 0 && (av[1][i] == '\0' || av[1][i] == '\t' || av[1][i] == ' '))
			i--;
		end = i;
		while (i >= 0 && av[1][i] != ' ' && av[1][i] != '\t')
			i--;
		start = i +1;
		while (start <= end)
			write(1, &av[1][start++], 1);
	}
	write(1, "\n", 1);
}
