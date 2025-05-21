/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:54:57 by dgomez-a          #+#    #+#             */
/*   Updated: 2025/03/13 22:57:22 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

int	find_balance(char *str)
{
	int	l_parent;
	int	r_parent;

	l_parent = 0;
	r_parent = 0;
	while (*str)
	{
		if (*str == '(')
			l_parent++;
		if (*str == ')')
		{
			l_parent--;
			if (l_parent < 0)
			{
				r_parent++;
				l_parent = 0;
			}
		}
		str++;
	}
	return (l_parent + r_parent);
}

int	count_spaces(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == ' ')
			count++;
		str++;
	}
	return (count);
}

void	rip(char *str, int position, int len, int balance)
{
	char	temp;

	if (find_balance(str) == 0)
	{
		if (count_spaces(str) == balance)
			puts(str);
	}
	while (position < len)
	{
		temp = str[position];
		str[position] = ' ';
		rip (str, position + 1, len, balance);
		str[position] = temp;
		position++;
	}
}

int	main(int argc, char **argv)
{
	int	balance;

	if (argc != 2)
		return (1);
	balance = find_balance(argv[1]);
	if (balance == 0)
	{
		puts(argv[1]);
		return (0);
	}
	rip(argv[1], 0, ft_strlen(argv[1]), balance);
	return (0);
}
