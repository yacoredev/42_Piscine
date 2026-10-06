/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 20:07:23 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/04 20:07:24 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	get_index(char c)
{
	char	*ops;
	int		i;

	ops = OPERATORS;
	i = 0;
	while (ops[i])
	{
		if (ops[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	check_zero(int index, int nbr2)
{
	if (nbr2 == 0)
	{
		if (index == 3)
		{
			ft_putstr(ERROR_DEV);
			return (1);
		}
		else if (index == 4)
		{
			ft_putstr(ERROR_MOD);
			return (1);
		}
	}
	return (0);
}

int	main(int ac, char **av)
{
	int	(*ptr_fts[5])(int, int);
	int	nbr1;
	int	nbr2;
	int	index;
	int	result;

	if (ac == 4)
	{
		index = get_index(av[2][0]);
		if (index == -1 || av[2][1])
		{
			ft_putstr(ZERO);
			return (0);
		}
		init_fts(ptr_fts);
		nbr1 = ft_atoi(av[1]);
		nbr2 = ft_atoi(av[3]);
		if (check_zero(index, nbr2))
			return (1);
		result = ptr_fts[index](nbr1, nbr2);
		ft_putnbr(result);
		write(1, "\n", 1);
	}
	return (0);
}
