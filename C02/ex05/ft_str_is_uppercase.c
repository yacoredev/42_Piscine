/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabaadi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 19:38:11 by yabaadi           #+#    #+#             */
/*   Updated: 2026/07/22 10:39:01 by yabaadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_str_is_uppercase(char *str)
{
	int	i;

	if (*str == '\0')
		return (1);
	i = 0;
	while (str[i])
	{
		if (!ft_is_upper(str[i]))
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int main()
{
        printf("%d", ft_str_is_uppercase("HELLO"));
}
*/
