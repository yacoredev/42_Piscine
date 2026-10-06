#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*byte_dst;
	const unsigned char	*byte_src;
	size_t		i;

	byte_dst = (unsigned char *)dest;
	byte_src = (const unsigned char *)src;
	if ((dest > src) && n)
	{
		byte_dst += n - 1;
		byte_src += n - 1;
		i = 0;
		while (i < n)
		{
			*byte_dst-- = *byte_src--;
			i++;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/*
#include <stdio.h>
int main()
{
    char s[] = "ABCDE";
    char d[20];
    // char *ret_meme = ft_memmove(d, s, 3);

    *//* Overlap (copy in the same memory allocation) *//*
    char *ret_meme = ft_memmove(s + 1, s, 4);
    // char *ret_meme = memmove(s + 1, s, 4);

    printf("source:\t\t\t%s\n", s);
    printf("destination:\t%s\n", ret_meme);
}
*/
