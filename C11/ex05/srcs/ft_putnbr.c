/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 00:09:31 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/05 00:09:33 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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
