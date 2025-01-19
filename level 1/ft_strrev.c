char    *ft_strrev(char *str)
{
	int i = 0;
	int len = 0;
	char tmp;

	while (str[len])
		len++;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
		i++;
	}
	return (str);
}



#include <stdio.h>

char *ft_strrev(char *str);

int main(void)
{
    char str1[] = "Hello, World!";
    char str2[] = "abcd";
    char str3[] = "123456789";
    char str4[] = "";           // Empty string
    char str5[] = "A";          // Single character

    printf("Original: '%s', Reversed: '%s'\n", str1, ft_strrev(str1));
    printf("Original: '%s', Reversed: '%s'\n", str2, ft_strrev(str2));
    printf("Original: '%s', Reversed: '%s'\n", str3, ft_strrev(str3));
    printf("Original: '%s', Reversed: '%s'\n", str4, ft_strrev(str4));
    printf("Original: '%s', Reversed: '%s'\n", str5, ft_strrev(str5));

    return 0;
}

