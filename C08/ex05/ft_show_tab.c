/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 23:16:00 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/02 23:16:02 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

void	ft_putnbr(int nb)
{
	long	number;
	char	c;

	number = (long)nb;
	if (number == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (number < 0)
	{
		number = -number;
		write(1, "-", 1);
	}
	if (number > 9)
		ft_putnbr(number / 10);
	c = (number % 10) + '0';
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		i++;
	}
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stock_str	*array;

	if(argc > 1)
	{
		argv++;
		argc--;
		array = ft_strs_to_tab(argc, argv);
		ft_show_tab(array);
	}
	return (0);
}
*/