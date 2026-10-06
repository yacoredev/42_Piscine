/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 10:08:22 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/26 10:21:11 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	n;
	int	i;

	if (nb < 0)
		return (0);
	n = 1;
	i = 0;
	while (nb > 0)
	{
		n *= nb;
		nb--;
	}
	return (n);
}
/*
#include <stdio.h>
int main()
{
	int	nb = 5;

	printf("%d! = %d\n", nb, ft_iterative_factorial(nb));
}
*/
