/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 19:34:42 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/04 19:34:44 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*arr;
	int	i;

	arr = malloc(length * sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < length)
	{
		arr[i] = f(tab[i]);
		i++;
	}
	return (arr);
}
/*
int	ft_putnbr(int nb)
{
	return(nb);
}
#include <stdio.h>

int	main(void)
{
	int	tab[] = {4, 5, 8, 9};
	int	(*f)(int);
	int	*arr;

	f = ft_putnbr;
	arr = ft_map(tab, 4, f);
	for (int i = 0; i < 4; i++)
		printf("arr[%d] = %d\n", i, arr[i]);
}
*/
