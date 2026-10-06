/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 22:36:14 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/30 22:38:49 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(char *str, int size)
{
	int		i;
	char	*ptr;

	ptr = malloc((size + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < size)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	mark_end_array(t_stock_str *block)
{
	block->size = 0;
	block->str = 0;
	block->copy = 0;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*block;
	int			i;

	block = malloc((ac + 1) * sizeof(t_stock_str));
	if (!block)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		block[i].size = ft_strlen(av[i]);
		block[i].str = av[i];
		block[i].copy = ft_strdup(av[i], block[i].size);
		if (!block[i].copy)
		{
			while (i > 0)
				free(block[--i].copy);
			free(block);
			return (NULL);
		}
		i++;
	}
	mark_end_array(&block[i]);
	return (block);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stock_str	*array;
	int			i;

	if(argc > 1)
	{
		argv++;
		argc--;
		array = ft_strs_to_tab(argc, argv);
		i = 0;
		while(array[i].str)
		{
			printf("string = %s\n", array[i].str);
			printf("size = %d\n", array[i].size);
			printf("copy = %s\n", array[i].copy);
			printf("----------------------\n");
			i++;
		}
	}
	return (0);
}
*/