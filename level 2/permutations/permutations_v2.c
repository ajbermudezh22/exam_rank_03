/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgomez-a <dgomez-a@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 21:22:38 by dgomez-a          #+#    #+#             */
/*   Updated: 2025/03/13 21:39:50 by dgomez-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort(char *str, int len)
{
	int	i;
	int	j;

	i = -1;
	while (++i < len - 1)
	{
		j = -1;
		while (++j < len - i - 1)
		{
			if (str[j] > str[j + 1])
				ft_swap(&str[j], &str[j + 1]);
		}
	}
}

void	find_perm(char *str, int start, int len)
{
	int	i;

	i = start;
	if (i == len - 1)
	{
		puts(str);
		return ;
	}
	while (i < len)
	{
		ft_swap(&str[i], &str[start]);
		ft_sort(str + start + 1, len - start - 1);
		find_perm(str, start + 1, len);
		ft_swap(&str[i], &str[start]);
		ft_sort(str + start + 1, len - start - 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	find_perm(argv[1], 0, ft_strlen(argv[1]));
	return (0);
}
