/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/04 19:35:00 by yabaadi           #+#    #+#             */
/*   Updated: 2026/08/04 19:35:02 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (i < length)
	{
		if (f(tab[i]))
			count++;
		i++;
	}
	return (count);
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
	char	*tab[6] = {"hello", "world", "elo", "life", 0};
	int		(*f)(char *);

	f = check_e;
	printf("return (value: %d\n", ft_count_if(tab, 4, f)));
}
*/
