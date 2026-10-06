/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 22:24:13 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/28 18:22:37 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_result(int *arr, int size)
{
	char	c;
	int		i;

	i = 0;
	while (i < size)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		i++;
	}
}

void	gen_comb(int *comb, int pos, int digit, int size)
{
	if (pos == size)
	{
		print_result(comb, size);
		if (comb[0] != 10 - size)
			write(1, ", ", 2);
		return ;
	}
	while (digit <= (10 - size) + pos)
	{
		comb[pos] = digit;
		gen_comb(comb, pos + 1, digit + 1, size);
		digit++;
	}
	return ;
}

void	ft_print_combn(int n)
{
	int	comb[10];

	if (n > 0 && n < 10)
		gen_comb(comb, 0, 0, n);
}
/*
int	main()
{
	ft_print_combn(3);
}
*/
