/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 10:30:23 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/26 11:49:02 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	n;

	if (power < 0)
		return (0);
	n = 1;
	while (power > 0)
	{
		n *= nb;
		power--;
	}
	return (n);
}
/*
#include <stdio.h>
int main()
{
        int     nb = 0;
	int	pow = 0;

        printf("%d^%d = %d\n", nb, pow, ft_iterative_power(nb, pow));
}
*/
