#include <stdio.h>

int ft_strlen(char *str)
{
    int len = 0;
    while (str[len])
        len++;
    return (len);
}

void ft_swap(char *a, char *b)
{
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void ft_sort(char *str, int len)
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

void ft_reverse(char *str, int len)
{
    int i = 0, j = len - 1;
    while (i < j)
        ft_swap(&str[i++], &str[j--]);
}

int ft_next_permutation(char *str, int len)
{
    int k = len - 2;
	int l = len - 1;
    while (k >= 0 && str[k] >= str[k + 1])
        k--;
    if (k < 0)
        return (0);
    while (str[l] <= str[k])
        l--;
    ft_swap(&str[k], &str[l]);
    ft_reverse(str + k + 1, len - (k + 1));
    return (1);
}

int main(int argc, char **argv)
{
	if (argc < 2)
        return (1);
    int first = 1;
    int len = ft_strlen(argv[1]);
    ft_sort(argv[1], len);
	puts(argv[1]);
	while (ft_next_permutation(argv[1], len))
        puts(argv[1]);
    return (0);
}

