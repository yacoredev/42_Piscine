#include "libft.h"

static int	ft_isupper(int c)
{
	return (c >= 65 && c <= 90);
}

static int	ft_islower(int c)
{
	return (c >= 97 && c <= 122);
}

int		ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}