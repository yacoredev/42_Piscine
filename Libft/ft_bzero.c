#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr_byte;
	size_t			i;

	ptr_byte = (unsigned char *)s;
	i = 0;
	while (i < n)
		ptr_byte[i++] = 0;
}

/*
#include <stdio.h>
int main()
{
    char s[] = "hello";
    ft_bzero(s + 2, 2);

    printf("%s", s);
}
*/