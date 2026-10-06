#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buff;
	size_t	size;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return (ft_strdup(s2));
	if (s1 && !s2)
		return (ft_strdup(s1));
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	buff = malloc(size);
	if (!buff)
		return (NULL);
	// initialize and copy to buff, or do *buff = '\0'
	ft_strlcpy(buff, s1, size);
	// concatenate to buff
	ft_strlcat(buff, s2, size);
	return (buff);
}
