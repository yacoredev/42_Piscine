/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 22:58:23 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/18 12:20:20 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	left;
	int	right;

	right = size - 1;
	left = 0;
	while (left < right)
	{
		ft_swap(&tab[left], &tab[right]);
		left++;
		right--;
	}
}
/*
#include <stdio.h>
int	main()
{
	int tab[] = {1, 8, 5, 9, 7, 4};

	ft_rev_int_tab(tab, 6);

	for (int i = 0; i < 6; i++)
		printf("%d ", tab[i]);
}
*/
