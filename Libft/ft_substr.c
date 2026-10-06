#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	allowed_len;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	allowed_len = ft_strlen(s + start);
	if (allowed_len > len)
		allowed_len = len;
	sub = malloc(allowed_len + 1);
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, s + start, allowed_len + 1);
	return (sub);
}
