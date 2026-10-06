/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 19:34:26 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/05 17:21:00 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
/*
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

int	main(void)
{
	int	tab[] = void ma3ndoch size.{4, 5, 8, 9};

	ft_foreach(tab, 4, &ft_putnbr);
}
*/
