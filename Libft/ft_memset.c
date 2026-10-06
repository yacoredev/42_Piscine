#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr_byte;
	size_t			i;

	ptr_byte = (unsigned char *)s;
	i = 0;
	while (i < n)
		ptr_byte[i++] = (unsigned char)c;
	return (s);
}

/*
#include <stdio.h>
int main()
{
    char s[] = "hello";
    char *ns = ft_memset(s, '*', 5);

    printf("%s", ns);
}
*/