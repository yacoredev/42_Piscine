#include "libft.h"
#include <stdlib.h>

static int	count_digits(int nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
		count++;

	while (nbr)
	{
			nbr /= 10;
			count++;
	}
	return (count);
}

static char     *convert_tostr(char *str, long nbr, int size)
{
	char	*tmp;
	int	i;

	tmp = str;
	if (nbr < 0)
	{
		*tmp++ = '-';
		nbr = -nbr;
		size--;
	}

	i = size - 1;
	tmp[i--] = '\0';
	while (i >= 0)
	{
		tmp[i] = nbr % 10 + '0';
		nbr /= 10;
		i--;
	}
    return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	if (n == 0)
		return(ft_strdup("0"));
	size = count_digits(n) + 1;
	str = malloc(size * sizeof(char));
	if (!str)
		return (NULL);
	return (convert_tostr(str, n, size));
}
