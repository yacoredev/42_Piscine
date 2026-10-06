/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:51:42 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/16 22:02:11 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	nbrs[12];
	long	number;
	int		i;

	number = (long)nb;
	if (number < 0)
	{
		ft_putchar('-');
		number = -number;
	}
	if (number == 0)
	{
		ft_putchar('0');
		return ;
	}
	i = 0;
	while (number)
	{
		nbrs[i] = (number % 10) + '0';
		number /= 10;
		i++;
	}
	nbrs[i] = '\0';
	while (i > 0)
		ft_putchar(nbrs[--i]);
}
/*
#include <limits.h>
int main()
{
	ft_putnbr(INT_MAX);
	return 0;
}
*/
