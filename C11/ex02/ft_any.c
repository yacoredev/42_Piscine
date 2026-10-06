/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 19:34:52 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/04 19:34:54 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]))
			return (1);
		i++;
	}
	return (0);
}
/*
int	check_e(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if(str[i] == 'e')
			return (1);
		i++;
	}
	return(0);
}
#include <stdio.h>

int	main(void)
{
	char	*tab[4] = {"hello", "world", "elo", "life"};
	int		(*f)(char *);

	f = check_e;
	printf("return (value: %d\n", ft_any(tab, f)));
}
*/
