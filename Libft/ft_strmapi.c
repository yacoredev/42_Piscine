#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	unsigned int	i;

	if (!s)
		return (ft_strdup(""));
	str = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!str)
		return (NULL);

	i = 0;
	while (s[i])
	{
		// (*f)(i, s[i]) same
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
