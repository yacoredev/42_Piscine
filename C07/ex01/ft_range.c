/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 20:20:12 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/29 10:44:28 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	value;
	int	i;

	if (min >= max)
		return (NULL);
	arr = (int *)malloc((max - min) * sizeof(int));
	if (!arr)
		return (NULL);
	value = min;
	i = 0;
	while (value < max)
	{
		*(arr + i) = value++;
		i++;
	}
	return (arr);
}
/*
#include <stdio.h>
int	main()
{
	int	*arr;
	int	i;
	int	min = 4;
	int	max = 10;

	arr = ft_range(min, max);
	i = 0;
	while (i < max - min)
		printf("%d ", arr[i++]);
	free(arr);
	return (0);
}
*/