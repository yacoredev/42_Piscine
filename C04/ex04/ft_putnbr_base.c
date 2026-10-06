/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:44:04 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/26 09:44:03 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
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

void	convert_to_base(char *base, long nbr, int nbr_base)
{
	char	buff[33];
	int		i;

	i = 0;
	while (nbr)
	{
		buff[i] = base[nbr % nbr_base];
		nbr /= (long)nbr_base;
		i++;
	}
	buff[i] = '\0';
	while (i)
		ft_putchar(buff[--i]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		ret_value;
	long	deci_nbr;

	ret_value = valide_base(base);
	if (!ret_value || ret_value <= 1)
		return ;
	if (nbr == 0)
	{
		ft_putchar(base[0]);
		return ;
	}
	deci_nbr = nbr;
	if (deci_nbr < 0)
	{
		ft_putchar('-');
		deci_nbr = -deci_nbr;
	}
	convert_to_base(base, deci_nbr, ret_value);
}
/*
#include <unistd.h>
#include <limits.h>
int main()
{
    char *deci = "0123456789";
    char *bin = "01";
    char *hex = "0123456789ABCDEF";
    char *oct = "poneyvif";
	
	// convert decimal to any base
    ft_putnbr_base(INT_MIN, bin);
}
*/
