#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}
/*
#include <stdio.h>
int main()
{
    char s[] = "abcDfG";

    for(int i = 0; s[i]; i++)
        printf("%c", ft_toupper(s[i]));
}
*/
