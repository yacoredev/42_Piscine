#include "libft.h"

int		ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*
#include <stdio.h>
int main()
{
	char str[] = "hello07[t";

	for(size_t i = 0; i < sizeof(str) - 1; i++)
	{
		if (!ft_isalnum(str[i]))
		{
			printf("0\n");
			return (0);
		}
	}
	printf("1\n");
}
*/