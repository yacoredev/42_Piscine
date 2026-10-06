/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 18:42:09 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/30 16:28:17 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_atoi_base(char *str, char *base, int nbr_base);
char	*ft_putnbr_base(int nbr, char *buff, char *base, int nbr_base);
char	*convert_to_base(char *base, char *buff, long nbr, int nbr_base);

int	valide_base(char *base)
{
	int	i;
	int	j;

	if (!*base)
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= '\t' && base[i] <= '\r'))
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

char	*ft_reverstr(char *str)
{
	char	temp;
	int		i;
	int		j;

	i = 0;
	while (str[i])
		i++;
	i--;
	j = 0;
	if (*str == '-')
		j++;
	while (j < i)
	{
		temp = str[j];
		str[j] = str[i];
		str[i] = temp;
		j++;
		i--;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		decimal_nbr;
	int		nbr_basef;
	int		nbr_baset;
	char	*buff;

	buff = malloc(34 * sizeof(char));
	if (!buff)
		return (NULL);
	nbr_basef = valide_base(base_from);
	nbr_baset = valide_base(base_to);
	if (!nbr_basef || nbr_basef <= 1 || !nbr_baset || nbr_baset <= 1)
		return (NULL);
	decimal_nbr = ft_atoi_base(nbr, base_from, nbr_basef);
	ft_putnbr_base(decimal_nbr, buff, base_to, nbr_baset);
	return (ft_reverstr(buff));
}

/*
ft_putnbr_base: convert decimal number to [base_to]
ft_atoi_base: convert 'nbr' (string) from [base_from] to decimal number

- max of int can represent in 32 bits in binary (minimum base)
	(2147483647)10 = (1111111111111111111111111111111)2
- and in hexa in 8 bits
	(2147483647)10 = (7FFFFFFF)16
*/
/*
#include <stdio.h>
int	main(void)
{
	char	*hex;
	char	*bin;
	char	*dec;
	char	*result;

	hex = "0123456789abcdef";
	bin = "01";
	dec = "0123456789";
	result = ft_convert_base(" +-+-2a&@", hex, dec);
	printf("%s\n", result);
	free(result);
}
*/
