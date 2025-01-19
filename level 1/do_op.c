#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	if (ac == 4)
	{
		int n1 = atoi(av[1]);
		int n2 = atoi(av[3]);
		char op = av[2][0];

		if (op == '+')
			printf("%d", n1 + n2);
		else if (op == '-')
			printf("%d", n1 - n2);
		else if (op == '*')
			printf("%d", n1 * n2);
		else if (op == '/')
			printf("%d", n1 / n2);
		else if (op == '%')
			printf("%d", n1 % n2);
	}
	printf("\n");
}
