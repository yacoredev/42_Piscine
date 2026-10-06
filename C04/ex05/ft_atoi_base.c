/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:44:04 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/26 09:58:27 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	get_index(char c, char *base, long *nbr, int nbr_base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
		{
			*nbr = ((*nbr) * nbr_base) + i;
			return (1);
		}
		i++;
	}
	return (-1);
}

int	valide_base(char *base)
{
	int	i;
	int	j;

	if (!*base)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_atoi(char *str, char *base, int nbr_base)
{
	long	nbr;
	long	sign;
	int		i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (get_index(str[i++], base, &nbr, nbr_base) != -1)
		;
	return ((int)(nbr * sign));
}

int	ft_atoi_base(char *str, char *base)
{
	long	ret_value;
	long	deci_nbr;

	ret_value = valide_base(base);
	if (!ret_value || ret_value <= 1)
		return (0);
	return (ft_atoi(str, base, ret_value));
}
/*
#include <stdio.h>
int main()
{
    char *deci = "0123456789";
    char *bin = "01";
    char *hex = "0123456789ABCDEF";
    char *oct = "poneyvif";

	// convert any base to decimal
	// ft_atoi always returns a decimal number
    printf("%d\n", ft_atoi_base(" -+-++---FFq", hex));
}
*/
