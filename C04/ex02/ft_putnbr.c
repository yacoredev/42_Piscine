/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 11:42:28 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/26 09:33:47 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long	number;
	char	c;

	number = (long)nb;
	if (number == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (number < 0)
	{
		number = -number;
		ft_putchar('-');
	}
	if (number > 9)
		ft_putnbr(number / 10);
	c = (number % 10) + '0';
	ft_putchar(c);
}
/*
#include <limits.h>
#include <stdio.h>
int main()
{
    ft_putnbr(INT_MIN);
}
*/
