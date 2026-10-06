#include "libft.h"

void	*ft_memcpy(void  *dest, const void *src, size_t n)
{
	const unsigned char	*byte_src;
	unsigned char	*byte_dst;
	size_t			i;

	byte_src = (const unsigned char *)src;
	byte_dst = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		*byte_dst++ =  *byte_src++;
		i++;
	}
	return (dest);
}

/*
#include <stdio.h>
int main()
{
    char s[] = "hello";
	char d[20];
    char *ret_meme = ft_memcpy(d, s, 3);

	*//* Overlap (copy in the same memory allocation) *//*
	// char *ret_meme = ft_memcpy(s + 2, s, 3);

    printf("%s", ret_meme);
}*/
