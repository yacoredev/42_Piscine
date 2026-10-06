#include "libft.h"
#include <stdlib.h>

static int	count_words(char const *s, char sep)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s && *s != sep)
		{
			count++;
			while (*s && *s != sep)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static int	put_str(char const **s, char **arr, size_t *i, char sep)
{
	char const	*start;
	char const	*end;

	while (**s && **s == sep)
		(*s)++;
	if (**s != '\0')
	{
		start = *s;
		while (**s && **s != sep)
			(*s)++;

		end = *s;
		arr[*i] = ft_substr(start, 0, end - start);
		if (!arr[*i])
			return (0);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	size;
	size_t  i;

	size = count_words(s, c) + 1;
	arr = malloc(size * sizeof(char *));
	if (!arr)
		return (NULL);

	i = 0;
	while (i < size - 1)
	{
		if (!put_str(&s, arr, &i, c))
		{
			while (i > 0)
				free(arr[--i]);
			free(arr);
			return (NULL);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
