/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 09:34:35 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/05 09:34:39 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	ft_strcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

void	ft_sort_string_tab(char **tab)
{
	char	**start;
	char	**size;

	start = tab;
	size = tab;
	while (*size)
	{
		while (*(tab + 1))
		{
			if (ft_strcmp(*tab, *(tab + 1)) > 0)
				ft_swap(tab, tab + 1);
			tab++;
		}
		tab = start;
		size++;
	}
}
/*
#include <unistd.h>

int	main(int ac, char **av)
{
	char	*str;

	if (ac > 1)
	{
		av++;
		ft_sort_string_tab(av);
		while (*av)
		{
			str = *av;
			while (*str)
				write(1, str++, 1);
			av++;
			write(1, "\n", 1);
		}
	}
	return (0);
}
*/