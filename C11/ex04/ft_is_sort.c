/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 19:35:09 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/04 19:35:10 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	skip_equal(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1 && f(tab[i], tab[i + 1]) == 0)
		i++;
	return (i);
}

int	chek_ascending(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	check_decreasing(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (f(tab[i], tab[i + 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;

	if (length <= 1)
		return (1);
	i = skip_equal(tab, length, f);
	if (i == length - 1)
		return (1);
	if (f(tab[i], tab[i + 1]) < 0)
		return (chek_ascending(tab, length, f));
	else
		return (check_decreasing(tab, length, f));
}
/*
int	ft_compare(int a, int b)
{
	return (b - a);
}

#include <stdio.h>

int	main(void)
{
	int	tab[] = {5, 5, 5, 5};
	int	(*f)(int, int);

	f = ft_compare;
	printf("return (value: %d\n", ft_is_sort(tab, 4, f)));
	return (0);
}
*/