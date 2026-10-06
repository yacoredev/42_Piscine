/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 19:11:38 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/16 19:45:45 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	digit1;
	int	digit2;

	digit1 = 0;
	while (digit1 <= 98)
	{
		digit2 = digit1 + 1;
		while (digit2 <= 99)
		{
			ft_putchar((digit1 / 10) + '0');
			ft_putchar((digit1 % 10) + '0');
			ft_putchar(' ');
			ft_putchar((digit2 / 10) + '0');
			ft_putchar((digit2 % 10) + '0');
			if (digit1 != 98)
				write(1, ", ", 2);
			digit2++;
		}
		digit1++;
	}
}
/*
int main()
{
	ft_print_comb2();
	return (0);
}
*/
