#include "libft.h"

int	 ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*byte_s1;
	const unsigned char	*byte_s2;
	size_t	i;

	if (n == 0)
		return (0);
	byte_s1 = (const unsigned char *)s1;
	byte_s2 = (const unsigned char *)s2;

	i = 1;
	/*
	 * exp: if n = 3
	 * 	i = 1, i = 2, i = 3 stop but by increment
	 * 	the pointer we return diff bitween bytes 3
	 * 	so start with i = 1 < n or i = 0 < n - 1
	 */
	while (i < n && *byte_s1 == *byte_s2)
	{
		byte_s1++;
		byte_s2++;
		i++;
	}
	return (*byte_s1 - *byte_s2);
}
