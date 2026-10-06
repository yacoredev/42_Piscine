#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if((unsigned char)*s == (unsigned char)c)
			/* (char *) Treat this pointer as a non-const */
			return ((char *)s);
		s++;
	}
	/* 7ta null dakhl f search */
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (0);
}
