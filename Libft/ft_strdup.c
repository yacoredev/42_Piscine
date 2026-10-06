#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*tmp;

	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	tmp = str;
	while (*s)
		*tmp++ = *s++;
	*tmp = '\0';
	return (str);
}
