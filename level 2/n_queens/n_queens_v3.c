#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>

void	print_solution(int tablero[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d", tablero[i]);
	printf("\n");
}

int	is_safe(int tablero[], int col, int row)
{
	for (int i = 0; i < col; i++)
	{
		if (tablero[i] == row ||
		tablero[i] - i == row - col ||
		tablero[i] + i == row + col)
			return (0);
	}
	return (1);
}

void	solveNQueens(int tablero[], int col, int n)
{
	if (col == n)
	{
		print_solution(tablero, n);
		return ;
	}
	for (int row = 0; row < n; row++)
	{
		if (is_safe(tablero, col, row))
		{
			tablero[col] = row;
			solveNQueens(tablero, col + 1, n);
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("wrong number of args\n");
		return (1);
	}
	int n = atoi(argv[1]);
	int tablero [n];
	solveNQueens(tablero, 0, n);
	return (0);
}
