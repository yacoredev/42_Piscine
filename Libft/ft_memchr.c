#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*byte;
	size_t		i;

	byte = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*byte == (unsigned char)c)
			return ((void *)byte);
		byte++;
		i++;
	}
	return (0);
}
