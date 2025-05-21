/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   powerset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 23:08:08 by dgomez-a          #+#    #+#             */
/*   Updated: 2025/03/13 23:08:21 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
int set_sum(int *set, int set_size)
{
	int sum = 0;
	int i = 0;
	while(i < set_size)
	{
		sum = sum + set[i];
		i++;
	}
	return(sum);
}
void print_set(int *set, int set_size)
{
	int i = 0;
	while(i < set_size)
	{
		printf("%d", set[i]);
		i++;
	}
}
void	powerset(int n,int *set, int set_size, char **argv, int start)
{
	int i = start;
	if(set_sum(set, set_size) == n) // sums all the elements of the array
	{
		print_set(set, set_size);
		printf("\n");
	}
	while(argv[i])
	{
		int curr = atoi(argv[i]);
		set[set_size] = curr;
		powerset(n, set, set_size + 1, argv, i + 1); //
		i++;
	}
}
int main(int argc, char ** argv)
{
	if(argc > 2)
	{
		int n = atoi(argv[1]);
		int set[argc - 2];
		powerset(n, set, 0, argv, 2);
	}
	return(0);
}
