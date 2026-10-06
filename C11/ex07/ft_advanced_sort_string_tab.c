/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 10:53:59 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/05 10:54:00 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[j + 1])
		{
			if (cmp(tab[j], tab[j + 1]) > 0)
				ft_swap(&tab[j], &tab[j + 1]);
			j++;
		}
		i++;
	}
}
/*
int	rev(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str2 - (unsigned char)*str1);
}

int	cmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

#include <unistd.h>

int	main(int ac, char **av)
{
	int		(*ptr_to_strcmp)(char*, char*);
	char	*str;
	int		i;

	if (ac > 1)
	{
		ptr_to_strcmp = cmp;
		av++;
		i = 0;
		ft_advanced_sort_string_tab(av, ptr_to_strcmp);
		while (av[i])
		{
			str = av[i];
			while (*str)
				write(1, str++, 1);
			i++;
			write(1, "\n", 1);
		}
		write(1, "---------\n", 10);
		/////////////////////////////
		ptr_to_strcmp = rev;
		i = 0;
		ft_advanced_sort_string_tab(av, ptr_to_strcmp);
		while (av[i])
		{
			str = av[i];
			while (*str)
				write(1, str++, 1);
			i++;
			write(1, "\n", 1);
		}
	}
	return (0);
}
*/