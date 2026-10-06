/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 18:01:13 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/22 10:26:57 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_alpha(char c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	if (*str == '\0')
		return (1);
	i = 0;
	while (str[i])
	{
		if (!ft_is_alpha(str[i]))
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int main()
{
	printf("%d", ft_str_is_alpha("hello"));
}
*/
