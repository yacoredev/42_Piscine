#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	nbr;
	int	sign;

	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;

	sign = 1;
	while (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}

	nbr = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nbr = nbr * 10 + (*nptr - 48);
		nptr++;
	}
	return ((int)nbr * sign);
}
