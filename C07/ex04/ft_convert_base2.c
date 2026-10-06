/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 19:12:49 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/29 22:59:45 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (0);
}

int	ft_atoi_base(char *str, char *base, int nbr_base)
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
	while (get_index(str[i++], base, &nbr, nbr_base))
		;
	return ((int)(nbr * sign));
}

char	*convert_to_base(char *base, char *buff, long nbr, int nbr_base)
{
	int	i;

	i = 0;
	while (nbr)
	{
		buff[i] = base[nbr % nbr_base];
		nbr /= (long)nbr_base;
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

char	*ft_putnbr_base(int nbr, char *buff, char *base, int nbr_base)
{
	long	deci_nbr;

	if (nbr == 0)
	{
		buff[0] = base[0];
		buff[1] = '\0';
		return (buff);
	}
	deci_nbr = nbr;
	if (deci_nbr < 0)
	{
		*buff = '-';
		buff++;
		deci_nbr = -deci_nbr;
	}
	return (convert_to_base(base, buff, deci_nbr, nbr_base));
}
