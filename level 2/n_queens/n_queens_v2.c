/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:08:49 by dgomez-a          #+#    #+#             */
/*   Updated: 2025/03/13 20:28:22 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	return (num);
}

int	no_danger(int *board, int row, int col)
{
	int	i;

	i = -1;
	while (++i < row)
		if (board[i] == col || (ft_abs(board[i] - col) == ft_abs(i - row)))
			return (0);
	return (1);
}

void	solve_game(int *board, int row, int n_queens)
{
	int	col;
	int	i;

	if (row == n_queens)
	{
		i = -1;
		while (++i < n_queens)
			printf("%d ", board[i]);
		printf("\n");
		return ;
	}
	col = -1;
	while (++col < n_queens)
	{
		if (no_danger(board, row, col))
		{
			board[row] = col;
			solve_game(board, row + 1, n_queens);
		}
	}
}

void	init_game(int n_queens)
{
	int	board[n_queens];
	int	i;

	i = -1;
	while (++i < n_queens)
		board[i] = -1;
	solve_game(board, 0, n_queens);
}

int	main(int argc, char **argv)
{
	int	n_queens;
	if (argc != 2)
		return (1);
	n_queens = atoi(argv[1]);
	if (n_queens == 1)
		printf("0\n");
	else if (n_queens > 1 && n_queens < 4)
		return (1);
	else
		init_game(n_queens);
	return (0);
}
