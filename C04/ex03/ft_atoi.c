/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:42:15 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/26 09:46:13 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	is_numeric(char n)
{
	return (n >= '0' && n <= '9');
}

int	ft_atoi(char *str)
{
	int	nbr;
	int	sign;
	int	i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (is_space(str[i]))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (is_numeric(str[i]))
	{
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
	}
	return (nbr * sign);
}
/*
#include <stdio.h>
int main()
{
    printf("%d\n", ft_atoi(" ---+-+1234ab567"));
}
*/
