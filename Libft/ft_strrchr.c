#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*find;

	find = 0;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			find = (char *)s;
		s++;
	}
	if ((unsigned char)*s == (unsigned char)c)
		return ((char *)s);
	return (find);
}
