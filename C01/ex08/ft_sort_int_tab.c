/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 23:13:16 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/17 23:50:15 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *num1, int *num2)
{
	int	swap;

	swap = *num1;
	*num1 = *num2;
	*num2 = swap;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	valide;
	int	i;

	while (size)
	{
		i = 0;
		valide = 1;
		while (i < size - 1)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				valide = 0;
			}
			i++;
		}
		if (valide)
			return ;
		size--;
	}
}
