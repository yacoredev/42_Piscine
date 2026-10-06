/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 10:45:13 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/29 12:25:52 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	value;
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	*range = (int *)malloc(size * sizeof(int));
	if (!*range)
		return (-1);
	value = min;
	i = 0;
	while (value < max)
	{
		*(*(range + 0) + i) = value++;
		i++;
	}
	return (size);
}
/*
#include <stdio.h>
int	main()
{
	int	*arr_of_ints;
	int	min = 2;
	int	max = 4;

	ft_ultimate_range(&arr_of_ints, min, max);
	int i = 0;
	while (i < max - min)
		printf("%d ", arr_of_ints[i++]);
	free(arr_of_ints);
	return (0);
}
*/