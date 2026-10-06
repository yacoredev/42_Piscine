/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 19:33:27 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/22 10:32:18 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_str_is_lowercase(char *str)
{
	int	i;

	if (*str == '\0')
		return (1);
	i = 0;
	while (str[i])
	{
		if (!ft_is_lower(str[i]))
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int main()
{
        printf("%d", ft_str_is_lowercase("hello"));
}
*/
